#include <iostream>
#include "Encryption.h"
#include "Decryption.h"

int main(){
    char message[100], ch;// message is going to be the encrypted text provided by the user and need to be an array of char so that the program can sort through each char and rearrange them | max size of 100 char
    // ch is going to hold the new encrypted char after being run through by the program
    std::string encryptedMessage, decryptedMessage;
    int x, key; // key is a random number inputted by the user that shift the message char
    bool quit = false;

    do {
        std::cout << "Enter A Message: ";
        std::cin >>message; // to read and display an entire line entered by user. First argument is the name of the string (address of first element of string) and second argument is the maximum size of the array.
        std::cout << "Enter Key: ";
        std::cin >> key;
        std::cout << "\nPlease Choose Following Options:\n";
        std::cout << "1 = Encrypt The String.\n"; // will be char + key
        std::cout << "2 = Decrypt The String.\n"; // will be char - key
        std::cout << "3 = Quit.\n";
        std::cin >> x;
        switch (x) {

            case 1: {
                // Traverse the given text one character at a time .
                Encryption e(message, key);
                e.encrypt();
                encryptedMessage = e.getMessage(); //saves the encryption
                std::cout << "Encrypted Message: " << encryptedMessage << "\n";
                break;
            }
            case 2: {
                Decryption d(message, key);
                d.decrypt();
                decryptedMessage = d.getDecryption();
                std::cout << "Decrypted Message: " << decryptedMessage << "\n";

                break;
            }
            case 3: {
                quit = true;
                break;
            }
            default:
                std::cout << "\n Invalid Input !!! \n";

        }
    } while (quit == false);

    return 0;
}

