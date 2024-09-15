
# Simple DBMS in C++

## Project Overview

This project implements a **Simple Database Management System (DBMS)** in C++, designed for educational purposes to demonstrate the fundamentals of database operations and version control. The system is entirely based on a **command-line interface (CLI)** and does not rely on any external database engine or graphical user interface. Instead, it manages data in memory and provides basic functionality for **CRUD operations (Create, Read, Update, Delete)** with version control for data consistency.

The DBMS allows you to:
- **Insert** new key-value pairs with version tracking.
- **Select** values based on a key.
- **Update** existing values, automatically incrementing their version.
- **Delete** key-value pairs.
- **Handle transaction-like behavior** using an in-memory log system.

This project is ideal for those who want to learn about:
- C++ programming with classes, templates, and file handling.
- Data structures such as maps and versioning.
- Basic database concepts such as key-value storage and CRUD operations.

## Features

- **INSERT**: Adds a new record to the database with a specific key and value. Each entry is versioned, starting from version 1.
- **SELECT**: Retrieves the value associated with a given key, along with its version.
- **UPDATE**: Modifies the value of an existing record and increments the version by 1.
- **DELETE**: Removes a record from the database based on its key.
- **Version Control**: Every time a record is updated, its version number increments, enabling users to track changes over time.
- **Persistent Storage**: Data can be saved to and read from files, allowing for simple data persistence.

## Project Structure

The project is structured as follows:
```
/Simple-DBMS
├── /include            # Header files for different modules
│   ├── dbms.h          # Main DBMS functionality
│   ├── query_parser.h  # Command parsing for user input
│   ├── storage.h       # File storage management for persistence
│   └── versioned_value.h # Version control for each data entry
├── /src                # Source files containing the implementation
│   ├── main.cpp        # The main entry point of the DBMS
│   ├── dbms.cpp        # Implementation of the DBMS class
│   └── storage.cpp     # Implementation of file storage management
├── Simple-DBMS.sln     # Visual Studio solution file
├── Simple-DBMS.vcxproj # Visual Studio project file
├── README.md           # Project documentation
└── .gitignore          # Git ignore file to exclude unnecessary files from version control
```

## Prerequisites

Before running the project, ensure that you have the following installed on your machine:

- A **C++ compiler** such as GCC, Clang, or MSVC.
- **Visual Studio** (if you prefer to use an IDE for Windows).
- **Git** (optional, for version control).

## How to Build and Run

You can build and run the project using one of the following methods:

### Option 1: Using Visual Studio (for Windows users)

1. Open the `Simple-DBMS.sln` file in Visual Studio.
2. Click on `Build > Build Solution` or press `Ctrl + Shift + B` to compile the project.
3. Once the build is complete, you can run the program by pressing `Ctrl + F5` or selecting `Debug > Start Without Debugging`.

### Option 2: Using g++ (for Linux/MacOS/Windows)

1. Navigate to the project directory in the terminal.
2. Compile the project with the following command:
   ```bash
   g++ -o simple-dbms src/main.cpp src/dbms.cpp src/storage.cpp
   ```
3. Run the executable:
   ```bash
   ./simple-dbms
   ```

### Option 3: Using CMake (for multi-platform)

If you prefer to use CMake for building the project:

1. In the root directory, create a `CMakeLists.txt` file that defines the build configuration.
2. Run the following commands to generate the build system and compile the project:
   ```bash
   cmake .
   make
   ```
3. Run the executable:
   ```bash
   ./simple-dbms
   ```

## How to Use

Once the program is running, it will prompt you to enter commands via the command-line interface (CLI). The system supports the following commands:

- **INSERT**: Adds a new key-value pair to the database with version 1.
  ```
  INSERT <key> <value>
  ```
  Example:
  ```
  INSERT 1 JohnDoe
  ```
  Output:
  ```
  Data inserted: Key = 1, Value = JohnDoe, Version = 1
  ```

- **SELECT**: Retrieves the value associated with a specific key.
  ```
  SELECT <key>
  ```
  Example:
  ```
  SELECT 1
  ```
  Output:
  ```
  Data found: Key = 1, Value = JohnDoe, Version = 1
  ```

- **UPDATE**: Modifies the value of an existing key and increments the version.
  ```
  UPDATE <key> <new_value>
  ```
  Example:
  ```
  UPDATE 1 JaneDoe
  ```
  Output:
  ```
  Data updated: Key = 1, New Value = JaneDoe, Version = 2
  ```

- **DELETE**: Removes a key-value pair from the database.
  ```
  DELETE <key>
  ```
  Example:
  ```
  DELETE 1
  ```
  Output:
  ```
  Data deleted: Key = 1
  ```

- **EXIT**: Exits the application.
  ```
  EXIT
  ```

## Example Session

```bash
INSERT 1 JohnDoe
Data inserted: Key = 1, Value = JohnDoe, Version = 1

SELECT 1
Data found: Key = 1, Value = JohnDoe, Version = 1

UPDATE 1 JaneDoe
Data updated: Key = 1, New Value = JaneDoe, Version = 2

DELETE 1
Data deleted: Key = 1

EXIT
Exiting DBMS...
```

## Future Improvements

- **Transactions**: Add support for multi-step transactions with commit/rollback functionality.
- **Error Handling**: Implement more robust error handling for invalid commands or edge cases.
- **Improved Storage**: Implement more advanced storage mechanisms such as B-trees for better performance with large datasets.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
