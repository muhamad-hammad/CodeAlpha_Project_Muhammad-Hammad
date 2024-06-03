#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;

// Function declarations
void listDirectory(const filesystem::path& path);
void createDirectory(const filesystem::path& path);
void copyFile(const filesystem::path& source, const filesystem::path& destination);
void moveFile(const filesystem::path& source, const filesystem::path& destination);

int main() {
    filesystem::path currentPath = filesystem::current_path();

    while (true) {
        cout << "> " << currentPath << ": ";
        string command;
        getline(cin, command);

        // Parse command and arguments
        vector<string> args;
        // ... (code to parse command into args vector)

        if (args.empty()) {
            continue;
        }

        if (args[0] == "ls") {
            listDirectory(currentPath);
        } else if (args[0] == "cd") {
            // Handle changing directory
        } else if (args[0] == "mkdir") {
            // Handle creating directory
        } else if (args[0] == "cp") {
            // Handle copying file
        } else if (args[0] == "mv") {
            // Handle moving file
        } else if (args[0] == "exit") {
            break;
        } else {
            cerr << "Invalid command: " << args[0] << "\n";
        }
    }

    return 0;
}

// Function definitions
void listDirectory(const filesystem::path& path) {
    // Code to list directory contents
}

void createDirectory(const filesystem::path& path) {
    // Code to create a new directory
}

void copyFile(const filesystem::path& source, const filesystem::path& destination) {
    // Code to copy a file
}

void moveFile(const filesystem::path& source, const filesystem::path& destination) {
    // Code to move a file
}
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;

// Function declarations
void listDirectory(const filesystem::path& path);
void createDirectory(const filesystem::path& path);
void copyFile(const filesystem::path& source, const filesystem::path& destination);
void moveFile(const filesystem::path& source, const filesystem::path& destination);

int main() {
    filesystem::path currentPath = filesystem::current_path();

    while (true) {
        cout << "> " << currentPath << ": ";
        string command;
        getline(cin, command);

        // Parse command and arguments
        vector<string> args;
        // ... (code to parse command into args vector)

        if (args.empty()) {
            continue;
        }

        if (args[0] == "ls") {
            listDirectory(currentPath);
        } else if (args[0] == "cd") {
            // Handle changing directory
        } else if (args[0] == "mkdir") {
            // Handle creating directory
        } else if (args[0] == "cp") {
            // Handle copying file
        } else if (args[0] == "mv") {
            // Handle moving file
        } else if (args[0] == "exit") {
            break;
        } else {
            cerr << "Invalid command: " << args[0] << "\n";
        }
    }

    return 0;
}

// Function definitions
void listDirectory(const filesystem::path& path) {
    // Code to list directory contents
}

void createDirectory(const filesystem::path& path) {
    // Code to create a new directory
}

void copyFile(const filesystem::path& source, const filesystem::path& destination) {
    // Code to copy a file
}

void moveFile(const filesystem::path& source, const filesystem::path& destination) {
    // Code to move a file
}
