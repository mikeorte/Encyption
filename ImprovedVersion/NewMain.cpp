#include <iostream>
#include <string>
#include <fstream> //For the Future
#include "Caesar.cpp"
#include "Vigenere.cpp"
using namespace std;

//Prototypes
void encryptionManager();
void decryptionManger();

int main() {
    string plainText;
    string encryptedText;
    int key;
    int choice = 0;
    while (choice != 3) {
        cout << "\nPlease enter a number to indicate what you would like to do?\n 1 = Encrypt A String.\n 2 = Decrypt A String.\n 3 = Quit\n";
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
            case 3: // Quit
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
    Caesar caesarObj;
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
                caesarObj.encryptString();
                cout<<"\nYour encrypted password is: "<< caesarObj.getEncryptedText()<<endl;
                successful = true;
                break;
            case 2: // Vigenere
                cout << "You chose Vigenere.\n";
                VigenereObj.encryptString();
                cout<<"\nYour encrypted password is: "<< VigenereObj.getEncryptedText()<<endl;
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