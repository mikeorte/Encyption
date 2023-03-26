#include <iostream>
#include <string>
#include <fstream> //For the Future
#include "CaesarCipher.cpp"
using namespace std;

//Prototypes
string encrypt(string, int);
string decrypt(string, int);
bool properMessage(string);
bool properKey(string);

int main(){
    string message = "";
    string TempKey = "";
    int key = 0;
    int choice = 0;
    while (choice != 3){
        cout<< "Please enter a number to indicate what you would like to do?\n 1 = Encrypt A String.\n 2 = Decrypt A String.\n 3 = Quit\n";
        cin >> choice;
        if(choice == 1){
            cout << "Please enter a string (Only letters are accepted): ";
            cin >> message;
            while(!(properMessage(message))){
                cout << "Invalid Input!\n";
                cout << "Please enter a string (Only letters are accepted): ";
                cin >> message;
            }
            cout << "Please enter a key (Only integers are accepted): ";
            cin >> TempKey;
            while (!(properKey(TempKey))) {
                cout << "Invalid Input!\n";
                cout << "Please enter a key (Only integers are accepted): ";
                cin >> TempKey;
            }
            key = stoi(TempKey);
            string encryptedMessage = encrypt(message, key);
            cout << encryptedMessage<<endl;
        }
        else if(choice == 2){
            cout << "Please enter a string (Only letters are accepted): ";
            cin >> message;
            while(!(properMessage(message))){
                cout << "Invalid Input!\n";
                cout << "Please enter a string (Only letters are accepted): ";
                cin >> message;
            }
            cout << "Please enter a key (Only integers are accepted): ";
            cin >> TempKey;
            while (!(properKey(TempKey))) {
                cout << "Invalid Input!\n";
                cout << "Please enter a key (Only integers are accepted): ";
                cin >> TempKey;
            }
            key = stoi(TempKey);
            string decryptedMessage = decrypt(message, key);
            cout << decryptedMessage<<endl;
        }
        else if(choice != 3)
        {
            cout<< "Invalid Input!";
        }
    }
    cout << "Thank you for using the Encryption Manager!";
    return 0;
}
string encrypt(string message, int key){
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
string decrypt(string message, int key){
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
bool properMessage(string str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos;
}
bool properKey(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}