#include <iostream>
#include <string>

using namespace std;
class Vigenere{ 
public:
    string key;
    Vigenere(string key){ //The key will be used to encrypt the message
        for (int i = 0; i < key.size(); ++i){
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }
    string encrypt(string message){
        string encryptedMessage;

        return encryptedMessage;
    }
    string decrypt(string message){
        string decryptedMessage;

        return decryptedMessage;
    }
};