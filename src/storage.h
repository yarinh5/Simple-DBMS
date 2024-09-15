#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

class Storage {
public:
    // ����� ������ �����
    void saveData(int key, const std::string& value) {
        std::ofstream file("database.txt", std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open database file.");
        }
        file << key << " " << value << "\n";
        file.close();
    }

    // ����� ������ ������
    void deleteData(int key) {
        std::ifstream infile("database.txt");
        std::ofstream tempFile("temp.txt");
        int currentKey;
        std::string value;

        while (infile >> currentKey >> value) {
            if (currentKey != key) {
                tempFile << currentKey << " " << value << "\n";
            }
        }
        infile.close();
        tempFile.close();

        // ����� ����� ������ ������� ����� �����
        std::remove("database.txt");
        std::rename("temp.txt", "database.txt");
    }
};

#endif
