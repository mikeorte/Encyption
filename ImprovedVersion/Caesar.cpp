#include <iostream>
#include <string>
#include <algorithm>

class Caesar{ // shifts entire alphabet by a certain amount
private:
    std::string plainText;
    std::string encryptedText;
    int key;
public:
    void encryptString() { // sets data for rest of class
        std::string TempMessage, TempKey;
        std::cout << "Please enter a message (Only letters are accepted): ";
        std::cin.ignore();
        getline(std::cin, TempMessage);
        while (!(onlyLetters(TempMessage))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a message (Only letters are accepted): ";
            getline(std::cin, TempMessage);
        }
        plainText = TempMessage; // sets plainText value
        std::cout << "Please enter a key (Only integers are accepted): ";
        getline(std::cin, TempKey);
        while (!(onlyNumbers(TempKey))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a key (Only integers are accepted): ";
            getline(std::cin, TempKey);
        }
        key = stoi(TempKey); // sets key value
        encryptedText = encryption(plainText, key);
    }
    std::string encryption(std::string message, int key){ // sets encryptedText
        std::string cipher = "";
        for(int i = 0; i < message.length(); i++){
            char c = message[i];
            if (isupper(c)){
                int x = c - 'A' + key;

                x = x % 26;

                c = (char)(x + 'A');

            }
            else if(islower(c)) {
                int x = c - 'a' + key;

                x = x % 26;

                c = (char)(x + 'a');

            }
            cipher.insert(cipher.end(), c);
        }
        return cipher;
    }
    void decryptString() { // sets data for rest of class
        std::string TempMessage, TempKey;
        std::cout << "Please enter a message (Only letters are accepted): ";
        std::cin.ignore();
        getline(std::cin, TempMessage);
        while (!(onlyLetters(TempMessage))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a message (Only letters are accepted): "; 
            getline(std::cin, TempMessage);
        }
        encryptedText = TempMessage; // sets encryptedText value
        std::cout << "Please enter a key (Only integers are accepted): ";
        getline(std::cin, TempKey);
        while (!(onlyNumbers(TempKey))) {
            std::cout << "Invalid Input!\n";
            std::cout << "Please enter a key (Only integers are accepted): ";
            getline(std::cin, TempKey);
        }
        key = stoi(TempKey); //sets key value
        plainText = decryption(encryptedText, key);
    }
    std::string decryption(std::string message, int key){ // sets plainText
        std::string plain = "";
        for(int i = 0; i < message.length(); i++){
            char c = message[i];
            if (isupper(c)){
                int x = c - 'A' - key;

                if(x<0)
                x += 26;

                c = (char)(x + 'A');

            }
            else if(islower(c)) {
                int x = c - 'a' - key;

                if(x<0)
                    x+=26;

                c = (char)(x + 'a');

            }
            plain.insert(plain.end(), c);
        }
    return plain;
}
    bool onlyLetters(std::string str) { // checks for only letters
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
    }
    bool onlyNumbers(std::string str) { // checks for only numbers
    return str.find_first_not_of("0123456789") == std::string::npos;
    }
    std::string getPlainText(){ // returns plainText
        return plainText;
    }
    std::string getEncryptedText(){ //returns encryptedText
        return encryptedText;
    }
    int getKey(){ //returns Key
        return key;
    }

    static std::string encryptFile(std::string text) {
        std::string encryptedText = "";
        int key = 25;
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];
            if (std::isalpha(c)) {
                char base;
                if (std::isupper(c)) {
                    base = 'A';
                }
                else {
                    base = 'a';
                }
                c = (c - base + key) % 26 + base;
            }
            encryptedText += c;
        }
        return encryptedText;
    }

    static std::string decryptFile(std::string text) {
        std::string decryptedText = "";
        int key = 25;
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];
            if (std::isalpha(c)) {
                char base;
                if (std::isupper(c)) {
                    base = 'A';
                }
                else {
                    base = 'a';
                }
                c = (c - base - key + 26) % 26 + base;
            }
            decryptedText += c;
        }
        return decryptedText;
    }
};