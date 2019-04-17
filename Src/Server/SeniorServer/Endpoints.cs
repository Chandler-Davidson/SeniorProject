using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using MongoDB.Bson;
using MongoDB.Bson.IO;
using MongoDB.Driver;
using Nancy;
using Nancy.Responses;

namespace SeniorServer
{
    public class Endpoints : NancyModule
    {
        public Endpoints()
        {
            Options["/{catchAll*}"] = parmeters => { return new Response {StatusCode = HttpStatusCode.Accepted}; };

            After.AddItemToEndOfPipeline(context =>
            {
                context.Response.WithHeader("Access-Control-Allow-Origin", "*")
                    .WithHeader("Access-Control-Allow-Methods", "POST, GET")
                    .WithHeader("Access-Control-Allow-Headers", "Accept, Origin, Content-type");
            });

            Get[nameof(PreviousRun)] = _ => PreviousRun();
            Get[$"{nameof(PreviousRun)}/{{runId}}"] = parameters => PreviousRun(parameters.runId);
            Get[nameof(RuleDefinitions)] = _ => RuleDefinitions();
            Post[nameof(NewAnalysis)] = _ => NewAnalysis();
        }

        internal DatabaseManager DatabaseManager { get; } = new DatabaseManager();

        internal Response PreviousRun()
        {
            var docCollection = DatabaseManager.GetDocuments("AnalysesRun");

            return docCollection.AsResponse();
        }

        internal Response PreviousRun(string runId)
        {
            var filter = Builders<BsonDocument>.Filter.Eq("runId", runId);

            var docCollection = DatabaseManager.GetDocuments("AnalysesDetails", filter);

            return docCollection.AsResponse();
        }

        internal Response RuleDefinitions()
        {
            var docCollection = DatabaseManager.GetDocuments("Rules");

            return docCollection.AsResponse();
        }

        internal Response NewAnalysis()
        {
            try
            {
                // Get analysis config from POST
                var ruleConfig = Request.Form;

                // Create directory
                var path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\SeniorProject";
                Directory.CreateDirectory(path);

                var files = Request.Files;
                var filePaths = new List<string>();
                foreach (var file in files)
                {
                    var fileName = Path.Combine(path, file?.Name);
                    filePaths.Add(fileName);

                    using (var fileStream = new FileStream(fileName, FileMode.OpenOrCreate))
                    {
                        file.Value.CopyTo(fileStream);
                    }
                }

                var rules = ruleConfig["rules"]?.Value;
                var timeRun = ruleConfig["time"]?.Value;

                // Set C++ analysis
                var results = Analyzer.RunAnalysis(rules, string.Join(", ", string.Join(", ", String.Join(",", filePaths))));

                // Add results to AnalysesDetails
                var joinedFileNames = string.Join(", ", Request.Files.Select(x => x.Name));
                var s = $"{{\"runId\": \"{joinedFileNames}:{timeRun}\", Rules: {results}}}";
                DatabaseManager.InsertNewDocument("AnalysesDetails", s);

                // Add analysis information to AnalysesRun
                var analysesRun = DatabaseManager.GetCollection("AnalysesRun");
                var sameNameFilter = Builders<BsonDocument>.Filter.Eq("Name", joinedFileNames);
                var alreadyExists = DatabaseManager.ExistsInCollection(analysesRun, sameNameFilter);

                // If the document exists, update it. Otherwise, insert a new one.
                if (alreadyExists)
                {
                    var update = Builders<BsonDocument>.Update.Push("Dates", timeRun);
                    analysesRun.UpdateOne(sameNameFilter, update);
                }
                else
                {
                    var str = $"{{Name: \"{joinedFileNames}\", Dates: [\"{timeRun}\"] }}";
                    var doc = BsonDocument.Parse(str);
                    analysesRun.InsertOne(doc);
                }
            }
            catch (Exception e)
            {

                throw;
            }

            return HttpStatusCode.OK;
        }
    }

    public static class NancyMongoDBExtensions
    {
        public static Response AsResponse(this IAsyncCursor<BsonDocument> cursor)
        {
            var contents = cursor.ToList();

            var json = contents.ToJson(new JsonWriterSettings {OutputMode = JsonOutputMode.Strict});
            var response = new TextResponse(json, "application/json");

            return response;
        }
    }
}