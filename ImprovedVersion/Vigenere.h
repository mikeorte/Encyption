#pragma once
#include <string>

class Vigenere {
private:
    std::string plainText;
    std::string encryptedText;
    std::string key;
    std::string originalKey;

public:
    void createKey(std::string tempMessage, std::string tempKey);
    void encryptString();
    std::string encryption(std::string message, std::string key);
    void decryptString();
    std::string decryption(std::string message, std::string key);
    bool onlyLetters(std::string str);
    std::string getPlainText();
    std::string getEncryptedText();
    std::string getKey();
    std::string getOriginalKey();
};





