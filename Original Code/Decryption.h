#ifndef PROJECT_DECRYPTION_H
#define PROJECT_DECRYPTION_H
class Decryption {
protected:
    int key;
    std::string message, encryptedMessage;
public:
    Decryption(std::string encryptedMessage, int key) {
        this->encryptedMessage = encryptedMessage;
        this->key = key;
        message = encryptedMessage;
    }

    void decrypt() {
        char ch; // place holder
        for (int i = 0; message[i] != '\0'; ++i) {
            ch = message[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if (ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
                message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if (ch > 'a') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }
    }
    std::string getDecryption()
    {
        return message;
    }
};
#endif //PROJECT_DECRYPTION_H