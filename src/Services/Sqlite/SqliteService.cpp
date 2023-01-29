#include "SqliteService.hpp"

bool SqliteService::Initialize()
{
    sqlite3_initialize();

    bool successOpenDb = OpenDb();
    bool successTables = CreateDefaultTables();

    return successOpenDb && successTables;
}

bool SqliteService::CreateDefaultTables()
{
    return CreateTableMessages();
}

bool SqliteService::CreateTableMessages()
{
    String query = "CREATE TABLE IF NOT EXISTS messages (id INTEGER PRIMARY KEY, text TEXT NOT NULL, senderId TEXT NOT NULL, receiverId TEXT NOT NULL, timestamp INTEGER NOT NULL ON DELETE CASCADE);";
    return SqliteService::QueryDb(query);
}

bool SqliteService::InsertMessage(Message *message)
{
    String query = "INSERT INTO messages (text, senderId, receiverId, timestamp) VALUES (" +
                   String("'") + String(message->Message.c_str()) + String("', ") +
                   String("'") + String(message->SenderId.c_str()) + String("', ") +
                   String("'") + String(message->ReceiverId.c_str()) + String("', ") +
                   message->Timestamp + String(");");

    return QueryDb(query);
}

std::list<Message>* SqliteService::GetMessages()
{
    std::list<Message> *data = {};

    String query = "SELECT * FROM messages;";

    int rq = QueryDb(query, CallbackSelectMessages, (void *)data);

    return data;
}

static int CallbackSelectMessages(void *messageList, int colCount, char **rowValues, char **colNames)
{
    struct std::list<Message> *list = static_cast<std::list<Message> *>(messageList);

    Message message = Message();

    for (int i = 0; i < colCount; i++)
    {
        String colName = String(colNames[i]);
        if (colName == String("id"))
        {
            message.Id = atoi(rowValues[i]);
        }
        else if (colName == String("text"))
        {
            message.Message = rowValues[i];
        }
        else if (colName == String("senderId"))
        {
            message.SenderId = atoi(rowValues[i]);
        }
        else if (colName == String("receiverId"))
        {
            message.ReceiverId = atoi(rowValues[i]);
        }
        else if (colName == String("timestamp"))
        {
            message.Timestamp = atoi(rowValues[i]);
        }
    }

    list->push_back(message);

    return 0;
}


bool SqliteService::OpenDb()
{
    int openResult = sqlite3_open(_dbName, &_db);
    if (openResult)
    {
        _db = NULL;
        Serial.printf("Can't open database  - %s: %s\n", _dbName, sqlite3_errmsg(_db));
    }
    else
    {
        Serial.printf("Opened database successfully - %s\n", _dbName);
    }
    return openResult;
}

bool SqliteService::QueryDb(String query)
{
    return SqliteService::QueryDb(query, NULL);
}

bool SqliteService::QueryDb(String query, int (*callback)(void *, int, char **, char **))
{
    return SqliteService::QueryDb(query, callback, NULL);
}

bool SqliteService::QueryDb(String query, int (*callback)(void *, int, char **, char **), void *callbackData)
{
    sqlite3 *db = SqliteService::_db;

    if (db == NULL)
    {
        Serial.printf("Cannot execute query - Database is not open. => %s\n", query.c_str());
        return false;
    }

    char *zErrMsg = 0;
    int queryResult = sqlite3_exec(db, query.c_str(), callback, callbackData, &zErrMsg);
    if (queryResult == SQLITE_OK)
    {
        Serial.printf("Sqlite query executed successfully => %s\n", query.c_str());
    }
    else
    {
        Serial.printf("Sqlite error while executing query - %s => %s\n", zErrMsg, query.c_str());
        sqlite3_free(zErrMsg);
    }
    return queryResult;
}


