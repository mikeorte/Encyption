# Introduction

This is my encryption project. The goals are to be able to have multiple encyption methods, save them to text files, and encrypt the text files

# Updates

## 3/26/2023 <br>

### Things I did:
* Error catching for Caesar and key values
    * Changed key input to string, in case user had wrong input. Changed the code of caesar to make more sense and be easier to understand. Made it so that it threw errors in case user did something wrong, rather than crashing the program.
* Made it possible to use capital letters
    * Improved functionality
* Changed the order of the program so that it asked the user what it would like to do before asking for a string
    * Because in the future users would be able to have multiple encyrption and decryption methods, it makes more sense to ask them what they would like to do and then ask for string and key, especially because the limitations depends on the methods.
* Used a while loop instead of switch and case
    * Believe that it would easier to work with.

### Things I have to do:
* Make Caesar its own class
* Make new methods of encryption and implement them
* Read and write text files
* Encrypt the actual text files
</p>

## 3/27/2023<br>

### Things I did:
* Made Caesar its own class
    * I originally had seperate classes for enryption and decryption, due to my project only being about the caesar cipher. But now, I combined them and made it easier to understand. 
* Started working on Vigenere encryption method
    * Looked into Vigenere cipher, and it is multiple caesar ciphers. Realized that it would be a good next encryption method. 

### Things I have to do:
* Make new methods of encryption and implement them
* Read and write text files
* Encrypt the actual text files
</p>

## 4/2/2023<br>

### Things I did:   
* Used switch case for choice
    * While loops for all of them made it more complicated, decided to go back to switch case.
* Simplified main and expanded Caesar class's functionality
    * I put all of the user input into Caesar class in a seperate function. Making it so that main calls the encryptString, that that method will do all of the checking, and call the encryption method. 
* Improved code readablity 
    * By drastically simplifying main and adding comments, I made my code much easier to follow.
* Created an encryption and decryption manager
    * The goal is to further simplify main, by only calling other functions.
* Used switch case for encryption and decryption choices
    * Learning from my previous while loop mistake, I went with switch case from the beginning.
* Limited key size for Caesar to 10000
    * Realized that big numbers break my stoi function, I limited the size before it says, invalid input. 

### Things I have to do:
* Make new methods of encryption and implement them
* Read and write text files
* Encrypt the actual text files
</p>

## 4/3/2023 <br>
### Things I did:
* Made Vigenere class functional
    * Created a createKey function that capitalizes the letters, and makes it the length of the message. Also created the encyrption and decryption options, made sure to make them all capital in case user does not input it correctly. Was able to output all information.   
* Caught a few errors, but was not able to fix all of them
    * Includes user not only inputting letters, white space, for choices was able to fix user input and keep it in the loop. 
* Made Vigenere an option for encryption and decryption
    * Vigenere is an option in my encryption and decryption manager. It is also able to be called on, and output the correct encryption. Also added going back as an option.
* Updated the README file with more specific information about what I did.

### Things I have to do:
* Make 1 more method of encryption and implement it
* Read and write text files
* Encrypt the actual text files

## 4/8/2023 <br>
### Things I did:
* Created a fileManager
    * It is called whenever the user encrypts a file and writes to the file
* Created an option to print the file
    * In the main menu, printing the file is now option 3, while quitting is option 4.
* Made the fileManager able to properly write to the file
    * The plainText, encryptedText, key, and encryption method are all properly saved to the passwords.txt file.

### Things I have to do:
* Make 1 more method of encryption and implement it
* Encrypt the actual text files