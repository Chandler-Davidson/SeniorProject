using System;
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
            // Get analysis config from POST
            var ruleConfig = Request.Form;

            var file = Request.Files.FirstOrDefault();

            var fileName = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\SeniorProject", file?.Name);
            using (var fileStream = new FileStream(fileName, FileMode.Create))
            {
                file.Value.CopyTo(fileStream);
            }

            var rules = ruleConfig["rules"]?.Value;
            var filePaths = ruleConfig["fileName"]?.Value;
            var timeRun = ruleConfig["time"]?.Value;

            // Set C++ analysis
            var results = Analyzer.RunAnalysis(rules, fileName);

            // Add results to AnalysesDetails
            var s = $"{{runId: \"{file.Name}:{timeRun}\", Rules: {results}}}";
            DatabaseManager.InsertNewDocument("AnalysesDetails", s);

            // Add analysis information to AnalysesRun
            var analysesRun = DatabaseManager.GetCollection("AnalysesRun");
            var sameNameFilter = Builders<BsonDocument>.Filter.Eq("Name", file.Name);
            var alreadyExists = DatabaseManager.ExistsInCollection(analysesRun, sameNameFilter);

            // If the document exists, update it. Otherwise, insert a new one.
            if (alreadyExists)
            {
                var update = Builders<BsonDocument>.Update.Push("Dates", timeRun);
                analysesRun.UpdateOne(sameNameFilter, update);
            }
            else
            {
                var str = $"{{Name: \"{file.Name}\", Dates: [\"{timeRun}\"] }}";
                var doc = BsonDocument.Parse(str);
                analysesRun.InsertOne(doc);
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