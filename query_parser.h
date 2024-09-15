#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H

#include <string>
#include <sstream>
#include <vector>

enum class QueryType {
    INSERT,
    SELECT,
    UPDATE,
    DELETE,
    INVALID
};

class QueryParser {
public:
    // פונקציה לזיהוי סוג השאילתה
    static QueryType parse(const std::string& query) {
        std::istringstream stream(query);
        std::string command;
        stream >> command;

        if (command == "INSERT") return QueryType::INSERT;
        if (command == "SELECT") return QueryType::SELECT;
        if (command == "UPDATE") return QueryType::UPDATE;
        if (command == "DELETE") return QueryType::DELETE;
        return QueryType::INVALID;
    }

    // פונקציה לפירוק שאילתת INSERT
    static bool parseInsert(const std::string& query, int& key, std::string& value) {
        std::istringstream stream(query);
        std::string command;
        stream >> command >> key;
        std::getline(stream, value);
        if (!value.empty() && value[0] == ' ') value = value.substr(1);  // הסרת רווח בהתחלה
        return !value.empty();
    }

    // פונקציה לפירוק שאילתת SELECT
    static bool parseSelect(const std::string& query, int& key) {
        std::istringstream stream(query);
        std::string command;
        stream >> command >> key;
        return true;
    }

    // פונקציה לפירוק שאילתת UPDATE
    static bool parseUpdate(const std::string& query, int& key, std::string& value) {
        std::istringstream stream(query);
        std::string command;
        stream >> command >> key;
        std::getline(stream, value);
        if (!value.empty() && value[0] == ' ') value = value.substr(1);
        return !value.empty();
    }

    // פונקציה לפירוק שאילתת DELETE
    static bool parseDelete(const std::string& query, int& key) {
        std::istringstream stream(query);
        std::string command;
        stream >> command >> key;
        return true;
    }
};

#endif
