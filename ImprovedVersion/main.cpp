#include <iostream>
#include <string>
#include <fstream>  // Stream class to both read and write from/to files. 
#include <conio.h> // for _getch() and _putch() functions
#include "Caesar.cpp"
#include "Vigenere.cpp"

//Prototypes
bool login();
void encryptionManager();
void decryptionManger();
void fileManager(std::string plainText, std::string encryptedText, int intKey, std::string stringKey, std::string encryptionType);
void printFile();

int main() {
    if (!login()) {
        return 1;
    }
    int choice = 0;
    while (choice != 4) {
        std::cout << "\nPlease enter a number to indicate what you would like to do?\n 1 = Encrypt A String.\n 2 = Decrypt A String.\n 3 = Print File.\n 4= Quit\n";
        std::cin >> choice;
        if(std::cin.fail()){ // to catch if user does not input int
            std::cin.clear();
            std::cin.ignore(10000, '\n');
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
                std::cout << "\nThank you for using the Encryption Manager!";
                break;
            default:
                std::cout << "Invalid Input!";
        }
    }
    return 0;
}

bool login() {
    std::fstream file("credentials.txt"); // open the file containing the credentials

    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }
    
    std::string username, password, correctUsername, correctPassword, line;
    int attempts = 3;
    bool foundCredentials = false;
    
    // read the correct username and password from the file
    while (!foundCredentials && getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            correctUsername = line.substr(0, pos);
            correctPassword = line.substr(pos + 1);
            foundCredentials = true;
        }
    }
    
    while (attempts > 0) {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        password = "";
        char ch = _getch();
        while (ch != 13) { // 13 is the ASCII code for 'Enter'
            if (ch == 8) { // 8 is the ASCII code for 'Backspace'
                if (password.length() > 0) {
                    password.pop_back();
                    std::cout << "\b \b"; // move the cursor back, print a space, and move the cursor back again
                }
            }
            else {
                password += ch;
                std::cout << "*";
            }
            ch = _getch();
        }
        
        // check if the username and password entered by the user match the correct ones from the file
        if (username == correctUsername && password == correctPassword) {
            std::cout << "\nLogin successful.\n";
            return true;
        }
        else {
            attempts--;
            if (attempts > 0) {
                std::cout << "\nIncorrect username or password. Please try again.\n";
                std::cout << "You have " << attempts << " attempts left.\n\n";
            }
            else {
                std::cout << "\nYou have exceeded the maximum number of attempts. The program will now exit.\n";
                std::cout << correctUsername <<"\n" << correctPassword;
                return false;
            }
        }
    }
}


void encryptionManager() {
    int choice = 0;
    bool successful = false;
    Caesar CaesarObj;
    Vigenere VigenereObj;
    while (successful != true) {
        std::cout << "\nYou chose Encryption. Please chose the method:\n 1 = Caesar.\n 2 = Vigenere\n 3 = TBD\n 4 = Go Back\n";
        std::cin >> choice;
        if (std::cin.fail()) { // to catch if user does not input int
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        switch (choice) {
            case 1: // Caesar
                std::cout << "You chose Caesar.\n";
                CaesarObj.encryptString();
                std::cout << "\nYour encrypted password is: " << CaesarObj.getEncryptedText() << std::endl;
                fileManager(CaesarObj.getPlainText(), CaesarObj.getEncryptedText(), CaesarObj.getKey(), "\0", "Caesar");
                successful = true;
                break;
            case 2: // Vigenere
                std::cout << "You chose Vigenere.\n";
                VigenereObj.encryptString();
                std::cout << "\nYour encrypted password is: " << VigenereObj.getEncryptedText() << std::endl;
                fileManager(VigenereObj.getPlainText(), VigenereObj.getEncryptedText(), -1, VigenereObj.getOriginalKey(), "Vigenere");
                successful = true;
                break;
            case 3: // TBH
                std::cout << "You chose TBH.\n";
                successful = true;
                break;
            case 4: // Go Back
                successful = true;
                break;
            default:
                std::cout << "Invalid Input!";
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
        std::cout<<"\nYou chose Decryption. Please chose the method:\n 1 = Caesar.\n 2 = Vigenere\n 3 = TBD\n 4 = Go Back\n";
        std::cin >> choice;
        if(std::cin.fail()){ // to catch if user does not input int
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        switch (choice){
            case 1: // Caesar
                std::cout << "You chose Caesar.\n";
                caesarObj.decryptString();
                std::cout<<"\nYour decrypted password is: "<< caesarObj.getPlainText()<<std::endl;
                successful = true;
                break;
            case 2: // Vigenere
                std::cout << "You chose Vigenere.\n";
                VigenereObj.decryptString();
                std::cout<<"\nYour decrypted password is: "<< VigenereObj.getPlainText()<<std::endl;
                successful = true;
                break;
            case 3: // TBH
                std::cout << "You chose TBH.\n";
                successful = true;
                break;
            case 4: // Go Back
                successful = true;
                break;
            default:
                std::cout << "Invalid Input!";
        }
        if (successful == true)
            return;
    }
}

void fileManager(std::string plainText, std::string encryptedText, int intKey, std::string stringKey, std::string encryptionType) {
    std::fstream fileManager;
    std::string line;
    std::string pushToFile;
    fileManager.open("passwords.txt", std::ios::app); // app means to append
    if (intKey != -1) {
        pushToFile = plainText + " = " + encryptedText + " with key ' " + std::to_string(intKey)  + " ' with encryption method: " + encryptionType;
        pushToFile = Caesar::encryptFile(pushToFile);
        fileManager <<  pushToFile << std::endl;
    }
    else {
        pushToFile = plainText + " = " + encryptedText + " with key ' " + stringKey + " ' with encryption method: " + encryptionType;
        pushToFile = Caesar::encryptFile(pushToFile);
        fileManager <<  pushToFile << std::endl;
    }
}

void printFile() {
    std::fstream fileManager;
    std::string line;
    fileManager.open("passwords.txt");
    fileManager.seekg(0, std::ios::beg); // sets the reading to the beginning of the file
    if (fileManager.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The file is empty" << std::endl;
        return;
    }
    while (fileManager) {
        getline(fileManager, line);
        line = Caesar::decryptFile(line);
        std::cout << line << std::endl;
    }
    fileManager.close();
}
