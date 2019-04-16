using System.IO;
using System.Linq;
using MongoDB.Bson;
using MongoDB.Driver;

namespace SeniorServer
{
    public class DatabaseManager
    {
        private const string _databaseName = "SeniorProject";
        private readonly string _defaultRulesDocument = File.ReadAllText(@"..\..\defaultRules.json");

        private readonly FilterDefinition<BsonDocument> _emptyFilter = Builders<BsonDocument>.Filter.Empty;
        internal static MongoClient Client { get; } = new MongoClient("mongodb://localhost:27017");
        internal static IMongoDatabase Database { get; } = Client.GetDatabase(_databaseName);

        public DatabaseManager()
        {
            var collExists = CollectionExists(Database, "Rules");

            if (!collExists)
            {
                Database.CreateCollection("Rules");
                InsertNewDocument("Rules", _defaultRulesDocument);
            }
        }

        public bool CollectionExists(IMongoDatabase database, string collectionName)
        {
            var filter = new BsonDocument("name", collectionName);
            var collectionCursor = database.ListCollections(new ListCollectionsOptions { Filter = filter });
            return collectionCursor.Any();
        }

        internal IMongoCollection<BsonDocument> GetCollection(string collectionName)
        {
            // Wrapper to fetch collection
            return Database.GetCollection<BsonDocument>(collectionName);
        }

        internal IAsyncCursor<BsonDocument> GetDocuments(string collectionName, FilterDefinition<BsonDocument> filter = null)
        {
            // Get collection
            var collection = GetCollection(collectionName);

            // Apply filter if not null, otherwise get all
            filter = filter ?? _emptyFilter;

            // Return docs
            return collection.FindSync<BsonDocument>(filter);
        }


        internal void InsertNewDocument(string collectionName, string contents)
        {
            // Create a new document
            var newDoc = BsonDocument.Parse(contents);

            // Fetch collection
            var collection = GetCollection(collectionName);

            // Insert document
            collection.InsertOne(newDoc);
        }

        /// <summary>
        /// Returns true if a document matches the given filter.
        /// </summary>
        internal bool ExistsInCollection(IMongoCollection<BsonDocument> collection, FilterDefinition<BsonDocument> filter)
        {
            var docs = collection.FindSync<BsonDocument>(filter);

            return docs.ToList().Any();
        }
    }
}