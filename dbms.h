#ifndef DBMS_H
#define DBMS_H

#include "versioned_value.h"
#include "storage.h"
#include "query_parser.h"
#include <iostream>
#include <map>
#include <mutex>

class DBMS {
public:
    DBMS() : inTransaction(false) {}

    // ניתוח והפעלה של שאילתה
    void executeQuery(const std::string& query) {
        QueryType type = QueryParser::parse(query);

        switch (type) {
        case QueryType::INSERT:
            handleInsert(query);
            break;
        case QueryType::SELECT:
            handleSelect(query);
            break;
        case QueryType::UPDATE:
            handleUpdate(query);
            break;
        case QueryType::DELETE:
            handleDelete(query);
            break;
        default:
            std::cout << "Invalid query. Supported commands: INSERT, SELECT, UPDATE, DELETE\n";
        }
    }

private:
    std::map<int, VersionedValue<std::string>> database;
    Storage storage;
    bool inTransaction;
    std::mutex mtx;

    void handleInsert(const std::string& query) {
        int key;
        std::string value;
        if (QueryParser::parseInsert(query, key, value)) {
            database[key] = VersionedValue<std::string>(value, 1);
            storage.saveData(key, value);
            std::cout << "Data inserted: Key = " << key << ", Value = " << value << "\n";
        }
        else {
            std::cout << "Error: Invalid INSERT query format.\n";
        }
    }

    void handleSelect(const std::string& query) {
        int key;
        if (QueryParser::parseSelect(query, key)) {
            if (database.find(key) != database.end()) {
                auto& val = database[key];
                std::cout << "Data found: Key = " << key << ", Value = " << val.value << ", Version = " << val.version << "\n";
            }
            else {
                std::cout << "No data found for Key = " << key << "\n";
            }
        }
    }

    void handleUpdate(const std::string& query) {
        int key;
        std::string value;
        if (QueryParser::parseUpdate(query, key, value)) {
            if (database.find(key) != database.end()) {
                auto& val = database[key];
                val.setValue(value, val.version + 1);
                storage.saveData(key, value);
                std::cout << "Data updated: Key = " << key << ", New Value = " << value << ", Version = " << val.version << "\n";
            }
            else {
                std::cout << "No data found for Key = " << key << "\n";
            }
        }
    }

    void handleDelete(const std::string& query) {
        int key;
        if (QueryParser::parseDelete(query, key)) {
            if (database.erase(key)) {
                storage.deleteData(key);
                std::cout << "Data deleted: Key = " << key << "\n";
            }
            else {
                std::cout << "No data found for Key = " << key << "\n";
            }
        }
    }
};

#endif
