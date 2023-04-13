#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Caesar{ // shifts entire alphabet by a certain amount
private:
    string plainText;
    string encryptedText;
    int key;
public:
    void encryptString() { // sets data for rest of class
        string TempMessage, TempKey;
        cout << "Please enter a message (Only letters are accepted): ";
        cin.ignore();
        getline(cin, TempMessage);
        while (!(onlyLetters(TempMessage))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a message (Only letters are accepted): ";
            getline(cin, TempMessage);
        }
        plainText = TempMessage; // sets plainText value
        cout << "Please enter a key (Only integers are accepted): ";
        getline(cin, TempKey);
        while (!(onlyNumbers(TempKey))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a key (Only integers are accepted): ";
            getline(cin, TempKey);
        }
        key = stoi(TempKey); // sets key value
        encryptedText = encryption(plainText, key);
    }
    string encryption(string message, int key){ // sets encryptedText
        string cipher = "";
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
        string TempMessage, TempKey;
        cout << "Please enter a message (Only letters are accepted): ";
        cin.ignore();
        getline(cin, TempMessage);
        while (!(onlyLetters(TempMessage))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a message (Only letters are accepted): "; 
            getline(cin, TempMessage);
        }
        encryptedText = TempMessage; // sets encryptedText value
        cout << "Please enter a key (Only integers are accepted): ";
        getline(cin, TempKey);
        while (!(onlyNumbers(TempKey))) {
            cout << "Invalid Input!\n";
            cout << "Please enter a key (Only integers are accepted): ";
            getline(cin, TempKey);
        }
        key = stoi(TempKey); //sets key value
        plainText = decryption(encryptedText, key);
    }
    string decryption(string message, int key){ // sets plainText
        string plain = "";
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
    bool onlyLetters(string str) { // checks for only letters
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
    }
    bool onlyNumbers(string str) { // checks for only numbers
    return str.find_first_not_of("0123456789") == string::npos;
    }
    string getPlainText(){ // returns plainText
        return plainText;
    }
    string getEncryptedText(){ //returns encryptedText
        return encryptedText;
    }
    int getKey(){ //returns Key
        return key;
    }
};