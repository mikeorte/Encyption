#include <iostream>
#include <string>

using namespace std;
class Vigenere{ // Each letter of the message is shfited by a different amount, and the Key is a string that repeats to match the length of the message.
private:
    string plainText;                                                                                                                                                                   

    string encryptedText;
    string key;
public:
    void encryptString() { // sets data for rest of class
        string message, TempKey;
        cout << "Please enter a string (Only letters are accepted): ";
        cin >> message;
        while (!(onlyLetters(message))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a string (Only letters are accepted): ";
            cin >> message;
        }
        plainText = message; // sets plainText value
        cout << "Please enter a key (Only letters are accepted): ";
        cin >> TempKey;
        while (!(onlyLetters(TempKey))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a key (Only integers are accepted): ";
            cin >> TempKey;
        }
        key = stoi(TempKey); //sets key value
        encryptedText = encryption(message, key);
    }
    string encryption(string message, string key){
        string encryptedMessage;

        return encryptedMessage;
    }
    string decrypt(){
        string decryptedMessage;

        return decryptedMessage;
    }
    bool onlyLetters(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
    }
};