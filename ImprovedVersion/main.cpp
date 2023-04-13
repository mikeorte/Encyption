#include <iostream>
#include <string>
#include <fstream>  // Stream class to both read and write from/to files. 
#include "Caesar.cpp"
#include "Vigenere.cpp"
using namespace std;

//Prototypes
void encryptionManager();
void decryptionManger();
void fileManager(string plainText, string encryptedText, int intKey, string stringKey, string encryptionType);
void printFile();

int main() {
    string plainText;
    string encryptedText;
    int key;
    int choice = 0;
    while (choice != 4) {
        cout << "\nPlease enter a number to indicate what you would like to do?\n 1 = Encrypt A String.\n 2 = Decrypt A String.\n 3 = Print File.\n 4= Quit\n";
        cin >> choice;
        if(cin.fail()){ // to catch if user does not input int
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice) {
            case 1: // Encryption
                encryptionManager(); 
                break;
            case 2: // Decryption
                decryptionManger();
                break;
            case 3: //printFile
                printFile();
                break;
            case 4: // Quit
                cout << "\nThank you for using the Encryption Manager!";
                break;
            default:
                cout << "Invalid Input!";
        }
    }
    return 0;
}

void encryptionManager(){
    int choice = 0;
    bool successful = false;
    Caesar CaesarObj;
    Vigenere VigenereObj;
    while (successful != true){
        cout<<"\nYou chose Encryption. Please chose the method:\n 1 = Caesar.\n 2 = Vigenere\n 3 = TBD\n 4 = Go Back\n";
        cin >> choice;
        if(cin.fail()){ // to catch if user does not input int
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice){
            case 1: // Caesar
                cout << "You chose Caesar.\n";
                CaesarObj.encryptString();
                cout<<"\nYour encrypted password is: "<< CaesarObj.getEncryptedText()<<endl;
                fileManager(CaesarObj.getPlainText(), CaesarObj.getEncryptedText(), CaesarObj.getKey(), "\0", "Caesar");
                successful = true;
                break;
            case 2: // Vigenere
                cout << "You chose Vigenere.\n";
                VigenereObj.encryptString();
                cout<<"\nYour encrypted password is: "<< VigenereObj.getEncryptedText()<<endl;
                fileManager(VigenereObj.getPlainText(), VigenereObj.getEncryptedText(), -1, VigenereObj.getOriginalKey(), "Vigenere");
                successful = true;
                break;
            case 3: // TBH
                cout << "You chose TBH.\n";
                successful = true;
                break;
            case 4: // Go Back
                successful = true;
                break;
            default:
                cout << "Invalid Input!";

        }
        if (successful == true)
            return;
    }
}

void decryptionManger(){
    int choice = 0;
    bool successful = false;
    Caesar caesarObj;
    Vigenere VigenereObj;
    while (successful != true){
        cout<<"\nYou chose Decryption. Please chose the method:\n 1 = Caesar.\n 2 = Vigenere\n 3 = TBD\n 4 = Go Back\n";
        cin >> choice;
        if(cin.fail()){ // to catch if user does not input int
            cin.clear();
            cin.ignore(10000, '\n');
        }
        switch (choice){
            case 1: // Caesar
                cout << "You chose Caesar.\n";
                caesarObj.decryptString();
                cout<<"\nYour decrypted password is: "<< caesarObj.getPlainText()<<endl;
                successful = true;
                break;
            case 2: // Vigenere
                cout << "You chose Vigenere.\n";
                VigenereObj.decryptString();
                cout<<"\nYour decrypted password is: "<< VigenereObj.getPlainText()<<endl;
                successful = true;
                break;
            case 3: // TBH
                cout << "You chose TBH.\n";
                successful = true;
                break;
            case 4: // Go Back
                successful = true;
                break;
            default:
                cout << "Invalid Input!";
        }
        if (successful == true)
            return;
    }
}

void fileManager(string plainText, string encryptedText, int intKey, string stringKey, string encryptionType){
    fstream fileManager;
    string line;
    fileManager.open("passwords.txt", ios::app); // app means to append
    if(intKey != -1){
        fileManager << plainText << " = " << encryptedText << " with key ' " << intKey << " ' with encryption method: " << encryptionType << endl;
    }
    else {
        fileManager << plainText << " = " << encryptedText << " with key ' " << stringKey << " ' with encryption method: " << encryptionType << endl;
    }
}

void printFile(){
    fstream fileManager;
    string line;
    fileManager.open("passwords.txt");
    fileManager.seekg(0, ios::beg); // sets the reading to the beginning of the file
    if (fileManager.peek() == ifstream::traits_type::eof()) {
        cout << "The file is empty" << endl;
        return;
    }
    while (fileManager) {

        getline(fileManager, line);
 
        // Print line in Console
        cout << line << endl;
    }
    fileManager.close();
}