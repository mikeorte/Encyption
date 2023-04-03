#include <iostream>
#include <string>

using namespace std;

class Caesar{ // shifts entire alphabet by a certain amount
private:
    string plainText;
    string encryptedText;
    int key;
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
        cout << "Please enter a key (Only integers are accepted): ";
        cin >> TempKey;
        while (!(onlyNumbers(TempKey)) || stoi(TempKey)> 1000) {
            cout << "Invalid Input!\n";
            cout << "Please enter a key (Only integers are accepted): ";
            cin >> TempKey;
        }
        key = stoi(TempKey); //sets key value
        encryptedText = encryption(message, key);
    }
    string encryption(string message, int key){ //sets encryptedText
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
    string message, TempKey;
    cout << "Please enter a string (Only letters are accepted): ";
    cin >> message;
    while (!(onlyLetters(message))) {
        cout << "Invalid Input!\n";
        cout << "Please enter a string (Only letters are accepted): ";
        cin >> message;
    }
    encryptedText = message; // sets encryptedText value
    cout << "Please enter a key (Only integers are accepted): ";
    cin >> TempKey;
    while (!(onlyNumbers(TempKey))) {
        cout << "Invalid Input!\n";
        cout << "Please enter a key (Only integers are accepted): ";
        cin >> TempKey;
    }
    key = stoi(TempKey); //sets key value
    plainText = decryption(message, key);
    }
    string decryption(string message, int key){ //will also shift the letters by the key, but opposite way
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
    bool onlyLetters(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
    }
    bool onlyNumbers(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
    }
    string getPlainText(){
        return plainText;
    }
    string getEncryptedText(){
        return encryptedText;
    }
    int getKey(){
        return key;
    }
};