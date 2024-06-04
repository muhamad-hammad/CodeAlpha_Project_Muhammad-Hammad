#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>

using namespace std;

#include <cstdio>
#include <string>

void listDirectory(const std::string& path) {
    std::string command = "cmd /c dir \"" + path + "\" /b";
    system(command.c_str());
}

void createDirectory(const std::string& path) {
    std::string command = "cmd /c mkdir \"" + path + "\"";
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Directory created: " << path << std::endl;
    } else {
        std::cerr << "Error creating directory: " << path << std::endl;
    }
}

void copyFile(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    if (src) {
        ofstream dest(destination, ios::binary);
        if (dest) {
            dest << src.rdbuf();
            cout << "File copied: " << source << " -> " << destination << "\n";
        } else {
            cerr << "Error creating destination file: " << destination << "\n";
        }
    } else {
        cerr << "Error opening source file: " << source << "\n";
    }
}

void moveFile(const string& source, const string& destination) {
    if (rename(source.c_str(), destination.c_str()) == 0) {
        cout << "File moved: " << source << " -> " << destination << "\n";
    } else {
        cerr << "Error moving file: " << source << " -> " << destination << "\n";
    }
}

int main()
{
    cout << "Welcome to the File/Directory Manager!" << endl;
    cout << "This program allows you to manage files and directories using a command-line interface." << endl;
    cout << "Available commands:" << endl;
    cout << "ls: List files and directories in the current directory" << endl;
    cout << "mkdir <directory_name>: Create a new directory" << endl;
    cout << "cd <directory_name>: Change the current directory" << endl;
    cout << "cd..: Change the current directory to the parent directory" << endl;
    cout << "cp <source_file> <destination_file>: Copy a file (not implemented)" << endl;
    cout << "mv <source_file> <destination_file>: Move a file (not implemented)" << endl;
    cout << "exit: Exit the program" << endl;
    cout << "menu: Access the menu-based interface" << endl;
    cout << endl;

    string currentPath = "."; // Current directory

    while (true)
    {
        cout << "\n> " << currentPath << ": ";
        string command;
        getline(cin, command);

        vector<string> args;
        string arg;
        istringstream iss(command);
        while (iss >> arg)
        {
            args.push_back(arg);
        }

        if (args.empty())
        {
            continue;
        }

        if (args[0] == "ls")
        {
            listDirectory(currentPath);
        }
        else if (args[0] == "cd")
        {
            if (args.size() == 2)
            {
                currentPath = args[1];
            }
            else
            {
                cerr << "Usage: cd <directory_name>\n";
            }
            cout << "Current directory: " << currentPath << endl;
        }
        else if (args[0] == "cd..")
        {
            if (currentPath == ".")
            {
                cerr << "Cannot go up from root directory\n";
            }
            else
            {
                size_t lastSlash = currentPath.find_last_of("\\");
                if (lastSlash == string::npos)
                {
                    currentPath = ".";
                    cout << "Current directory: " << currentPath << endl;
                }
                else
                {
                    currentPath = currentPath.substr(0, lastSlash);
                    cout << "Current directory: " << currentPath << endl;
                }
            }
        }
        else if (args[0] == "mkdir")
        {
            if (args.size() == 2)
            {
                createDirectory(args[1]);
            }
            else
            {
                cerr << "Usage: mkdir <directory_name>\n";
            }
        }
        else if (args[0] == "cp")
        {
            if (args.size() == 3)
            {
                copyFile(args[1], args[2]);
            }
            else
            {
                cerr << "Usage: cp <source_file> <destination_file>\n";
            }
        }
        else if (args[0] == "mv")
        {
            if (args.size() == 3)
            {
                moveFile(args[1], args[2]);
            }
            else
            {
                cerr << "Usage: mv <source_file> <destination_file>\n";
            }
        }
        else if (args[0] == "exit")
        {
            break;
        }
        else if (args[0] == "menu")
        {
            cout << "\nWhat would you like to do?" << endl;
            cout << "1. List files/directories" << endl;
            cout << "2. Create a new directory" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cin.ignore(); // Ignore the newline character

            switch (choice)
            {
            case 1:
                cout << "Enter the path to list files/directories: ";
                getline(cin, currentPath);
                listDirectory(currentPath);
                break;
            case 2:
                cout << "Enter the path to create a new directory: ";
                getline(cin, currentPath);
                createDirectory(currentPath);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        else
        {
            cerr << "Invalid command: " << args[0] << "\n";
        }
    }

    return 0;
}