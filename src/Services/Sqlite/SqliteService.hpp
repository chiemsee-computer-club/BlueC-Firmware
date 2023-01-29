#pragma once

#include <sqlite3.h>
#include <FS.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>
#include <exception>

#include "../LoRa/Entities/Message.hpp"

// Sqlite3 libary: https://github.com/siara-cc/esp32_arduino_sqlite3_lib
// Sqlite3 callback example: https://stackoverflow.com/questions/31146713/sqlite3-exec-callback-function-clarification

class SqliteService
{
private:
    const char* _dbName = "/sd/bluec.db"; // SD-Card storage - use "/spiffs/bluec.db" for local storage of esp
    sqlite3 *_db;

    bool CreateDefaultTables();
    bool CreateTableMessages();

    bool OpenDb();
    bool QueryDb(String query);
    bool QueryDb(String query, int (*callback)(void*,int,char**,char**));
    bool QueryDb(String query, int (*callback)(void*,int,char**,char**), void* callbackData);


public:
    bool Initialize();

    bool InsertMessage(Message *message);
    std::list<Message>* GetMessages();
};