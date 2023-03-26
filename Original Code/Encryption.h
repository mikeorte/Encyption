#ifndef PROJECT_ENCRYPTION_H
#define PROJECT_ENCRYPTION_H
class Encryption {
protected:
    int key;
    std::string message, encryptedMessage;
public:
    Encryption(std::string message, int key) {
        this->message = message;
        this->key = key;
        encryptedMessage = message;
    }

    void encrypt() {
        char ch; // place holder
        for (int i = 0; encryptedMessage[i] != '\0'; ++i) {  //Will go through each char until the whole text has been sorted through until it reaches the end which is decribes the end of the string having a value of 0 -> NULL -> \0
            ch = encryptedMessage[i]; // ch will hold the first char of the text
            if (ch >= 'a' && ch <= 'z') { // has long has the char is in the range of a and z itll run
                ch = ch + key; // will shift the char to a new char based on the key
                if (ch > 'z') { // if the char once outside the range of z the program will get it back to the alphabet range
                    ch = ch - 'z' + 'a' - 1;
                }
                encryptedMessage[i] = ch; // will save the new char back into the message variable
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                encryptedMessage[i] = ch;
            }
        }
    }
    std::string getMessage()
    {
        return encryptedMessage;
    }
};
#endif //PROJECT_ENCRYPTION_H
