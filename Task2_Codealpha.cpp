#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for user registration
void registerUser() {
    string username, password;

    cout << "\n===== User Registration =====\n";
    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check if username already exists
    ifstream readFile((username + ".txt").c_str());

    if (readFile.is_open()) {
        cout << "Username already exists! Try another username.\n";
        readFile.close();
        return;
    }

    readFile.close();

    // Store username and password in file
    string filename = username + ".text";
    ofstream writeFile(filename.c_str());

    writeFile << username << endl;
    writeFile << password << endl;

    writeFile.close();

    cout << "Registration Successful!\n";
}

// Function for user login
void loginUser() {
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== User Login =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Read user file
    ifstream readFile((username + ".txt").c_str());
    ofstream writeFile((username + ".txt").c_str());

    if (!readFile.is_open()) {
        cout << "User not found!\n";
        return;
    }

    getline(readFile, storedUsername);
    getline(readFile, storedPassword);

    readFile.close();

    // Verify credentials
    if (username == storedUsername && password == storedPassword) {
        cout << "Login Successful!\n";
    } else {
        cout << "Invalid Username or Password!\n";
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;}

