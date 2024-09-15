#include "dbms.h"
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

// פונקציה להצגת תפריט הפקודות
void displayMenu() {
    std::cout << "\n--- Simple DBMS Menu ---\n";
    std::cout << "1. INSERT (e.g., INSERT 1 John Doe)\n";
    std::cout << "2. SELECT (e.g., SELECT 1)\n";
    std::cout << "3. UPDATE (e.g., UPDATE 1 Jane Doe)\n";
    std::cout << "4. DELETE (e.g., DELETE 1)\n";
    std::cout << "5. EXIT\n";
    std::cout << "------------------------\n";
}

// פונקציה לניהול פקודות שאילתות
void handleQuery(std::shared_ptr<DBMS> dbms, const std::string& query) {
    try {
        dbms->executeQuery(query);
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// פונקציה לקריאת קלט מהמשתמש ולהפעלת שאילתות בהתאם
void processUserInput(std::shared_ptr<DBMS> dbms) {
    std::string command;

    while (true) {
        std::cout << "DBMS> ";
        std::getline(std::cin, command);

        if (command == "EXIT") {
            std::cout << "Exiting DBMS...\n";
            break;
        }

        if (!command.empty()) {
            handleQuery(dbms, command);
        }
        else {
            std::cout << "No command entered. Please try again.\n";
        }
    }
}

int main() {
    // ניהול זיכרון חכם באמצעות shared_ptr
    std::shared_ptr<DBMS> dbms = std::make_shared<DBMS>();

    std::cout << "Welcome to the Simple DBMS!\n";
    displayMenu();  // הצגת תפריט השימוש

    processUserInput(dbms);  // קריאת פקודות מהמשתמש

    return 0;
}
