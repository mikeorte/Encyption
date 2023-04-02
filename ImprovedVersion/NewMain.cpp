#include <iostream>
#include <string>
#include <fstream> //For the Future
#include "Caesar.cpp"
using namespace std;

int main() {
    string plainText;
    string encryptedText;
    int key;
    int choice = 0;
    int secondChoice = 0;
    Caesar caesarObj;
    while (choice != 3) {
        cout << "Please enter a number to indicate what you would like to do?\n 1 = Encrypt A String.\n 2 = Decrypt A String.\n 3 = Quit\n";
        cin >> choice;
        switch (choice) {
            case 1: // Encryption
                switch (secondChoice) {
                    case 1: // Caesar
                        caesarObj.encryptString();
                        break;
                    case 2: // Second Encryption Option
                        break;
                    case 3: // Second Encryption Option
                        break;
                    default:
                        cout << "Invalid Input!";
                }
                break;
            case 2: // Decryption
                switch (secondChoice) {
                    case 1: // Caesar
                        caesarObj.decryptString();
                        break;
                    case 2: // Second Encryption Option
                        break;
                    case 3: // Second Encryption Option
                        break;
                    default:
                        cout << "Invalid Input!";
                }
            case 3: // Quit
                cout << "Thank you for using the Encryption Manager!";
                break;
            default:
                cout << "Invalid Input!";
        }
    }
    return 0;
}