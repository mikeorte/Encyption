#include <iostream>
#include <string>
#include <algorithm>
#include "Vigenere.h"

class Vigenere {
private:
    std::string plainText;
    std::string encryptedText;
    std::string key;
    std::string originalKey;

public:
    void createKey(std::string tempMessage, std::string tempKey) {
        originalKey = tempKey;
        for (int i = 0; i < tempKey.length(); i++) {
            tempKey[i] = toupper(tempKey[i]);
        }
        int messageSize = tempMessage.size();
        for (int i = 0;; i++) {
            if (messageSize == i)
                i = 0;
            if (tempKey.size() == tempMessage.size())
                break;
            tempKey += tempKey[i];
        }
        key = tempKey;
    }
    void encryptString() {
        std::string TempMessage, TempKey;
        std::cout << "Please enter a message (Only letters are accepted): ";
        std::cin.ignore();
        getline(std::cin, TempMessage);
        while (!(onlyLetters(TempMessage))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a message (Only letters are accepted): ";
            getline(std::cin, TempMessage);
        }
        for (int i = 0; i < TempMessage.length(); i++) {
            TempMessage[i] = toupper(TempMessage[i]);
        }
        plainText = TempMessage;
        std::cout << "Please enter a passphrase (Only letters are accepted): ";
        getline(std::cin, TempKey);
        while (!(onlyLetters(TempKey))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a passphrase (Only letters are accepted): ";
            getline(std::cin, TempKey);
        }
        createKey(TempMessage, TempKey);
        encryptedText = encryption(plainText, key);
    }
    std::string encryption(std::string message, std::string key) {
        std::string encrypted;
        for (int i = 0; i < message.size(); i++) {
            char x = (message[i] + key[i]) % 26;
            x += 'A';
            encrypted += x;
        }
        return encrypted;
    }
    void decryptString() { // sets data for rest of class
    std::string TempMessage, TempKey;
    std::cout << "Please enter a message (Only letters are accepted): ";
    std::cin.ignore();
    std::getline(std::cin, TempMessage);
    while (!(onlyLetters(TempMessage))) { // checks if valid input
        std::cout << "Invalid Input!\n";
        std::cout << "Please enter a message (Only letters are accepted): ";
        std::getline(std::cin, TempMessage);
    }
    for (int i = 0; i < TempMessage.length(); i++) // will turn TempMessage to all capital letters
    {
        TempMessage[i] = std::toupper(TempMessage[i]);
    }
    encryptedText = TempMessage; // sets encryptedText value
    std::cout << "Please enter a key (Only letters are accepted): ";
    std::getline(std::cin, TempKey);
    while (!(onlyLetters(TempKey))) { // checks if valid input
        std::cout << "Invalid Input!\n";
        std::cout << "Please enter a passphrase (Only letters are accepted): ";
        std::getline(std::cin, TempKey);
    }
    createKey(TempMessage, TempKey); // creates the key and will set the value
    plainText = decryption(encryptedText, key);
}
    std::string decryption(std::string message, std::string key){
    std::string decrypted;
    for (int i = 0; i < message.size(); i++) // decryption process
    {
        char x = (message[i] - key[i] + 26) %26;
        x += 'A';
        decrypted += x;
    }
    return decrypted;
}
    bool onlyLetters(std::string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
    }
    std::string getPlainText(){ // returns plainText
        return plainText;
    }
    std::string getEncryptedText(){ //returns encryptedText
        return encryptedText;
    }
    std::string getKey(){ //returns Key
        return key;
    }
    std::string getOriginalKey(){ //returns Key
        return originalKey;
    }
};