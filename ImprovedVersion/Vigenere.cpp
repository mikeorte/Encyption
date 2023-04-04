#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Vigenere{ // Each letter of the message is shfited by a different amount depending on the key.
private:
    string plainText;
    string encryptedText;
    string key;
public:
    void createKey(string tempMessage, string tempKey){ // will create the key
        for (int i = 0; i < tempKey.length(); i++) // will turn key to all capital letters
  	    {
  		    tempKey[i] = toupper(tempKey[i]);
  	    }
        int messageSize = tempMessage.size();
        for (int i = 0;; i++) // will make the key the same length as the message;
        {
            if (messageSize == i)
                i = 0;
            if (tempKey.size() == tempMessage.size())
                break;
            tempKey += tempKey[i];
        }
        key = tempKey; // sets the value for key
    }
    void encryptString() { // sets data for rest of class
        string TempMessage, TempKey;
        cout << "Please enter a message (Only letters are accepted): ";
        cin.ignore();
        getline(cin, TempMessage);
        while (!(onlyLetters(TempMessage))) { // checks if valid input
            cout << "Invalid Input!\n";
            cout << "Please enter a message (Only letters are accepted): ";
            getline(cin, TempMessage);
        }
        for (int i = 0; i < TempMessage.length(); i++) // will turn TempMessage to all capital letters
  	    {
  		    TempMessage[i] = toupper(TempMessage[i]);
  	    }
        plainText = TempMessage; // sets plainText value
        cout << "Please enter a passphrase (Only letters are accepted): ";
        getline(cin, TempKey);
        while (!(onlyLetters(TempKey))) { // checks if valid input
            cout << "Invalid Input!\n";
            cout << "Please enter a passphrase (Only letters are accepted): ";
            getline(cin, TempKey);
        }
        createKey(TempMessage, TempKey); // creates the key and will set the value
        encryptedText = encryption(plainText, key); // creates the encryptedText and sets the value
    }
    string encryption(string message, string key){
        string encrypted;
        for (int i = 0; i < message.size(); i++) // encryption process
        {
            char x = (message[i] + key[i]) % 26;
            x += 'A';
            encrypted += x;
        }
        return encrypted;
    }
    void decryptString() { // sets data for rest of class
        string TempMessage, TempKey;
        cout << "Please enter a message (Only letters are accepted): ";
        cin.ignore();
        getline(cin, TempMessage);
        while (!(onlyLetters(TempMessage))) { // checks if valid input
            cout << "Invalid Input!\n";
            cout << "Please enter a message (Only letters are accepted): ";
            getline(cin, TempMessage);
        }
        for (int i = 0; i < TempMessage.length(); i++) // will turn TempMessage to all capital letters
  	    {
  		    TempMessage[i] = toupper(TempMessage[i]);
  	    }
        encryptedText = TempMessage; // sets encryptedText value
        cout << "Please enter a key (Only letters are accepted): ";
        getline(cin, TempKey);
        while (!(onlyLetters(TempKey))) { // checks if valid input
            cout << "Invalid Input!\n";
            cout << "Please enter a passphrase (Only letters are accepted): ";
            getline(cin, TempKey);
        }
        createKey(TempMessage, TempKey); // creates the key and will set the value
        plainText = decryption(encryptedText, key);
    }
    string decryption(string message, string key){
        string decrypted;
        for (int i = 0; i < message.size(); i++) // decryption process
        {
            char x = (message[i] - key[i] + 26) %26;
            x += 'A';
            decrypted += x;
        }
        return decrypted;
    }
    bool onlyLetters(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
    }
    string getPlainText(){ // returns plainText
        return plainText;
    }
    string getEncryptedText(){ //returns encryptedText
        return encryptedText;
    }
    string getKey(){ //returns Key
        return key;
    }
};