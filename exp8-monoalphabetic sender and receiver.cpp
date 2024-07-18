#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateCipherAlphabet(const char *keyword, char *cipherAlphabet) {
    int used[ALPHABET_SIZE] = {0}; // Track used letters
    int index = 0;

    // Add unique letters from keyword to cipherAlphabet
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (isalpha(ch)) {
            int pos = ch - 'A';
            if (!used[pos]) {
                used[pos] = 1; // Mark as used
                cipherAlphabet[index++] = ch;
            }
        }
    }

    // Add remaining letters of the alphabet
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        int pos = ch - 'A';
        if (!used[pos]) {
            cipherAlphabet[index++] = ch;
        }
    }
    cipherAlphabet[index] = '\0'; // Null terminate the string
}

void encrypt(const char *plaintext, const char *cipherAlphabet, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            int pos = ch - 'A';
            ciphertext[i] = cipherAlphabet[pos]; // Substitute using cipher alphabet
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabet characters remain unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null terminate the string
}

int main() {
    char keyword[100], plaintext[100], cipherAlphabet[ALPHABET_SIZE + 1], ciphertext[100];

    // Input keyword and plaintext
    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    // Generate cipher alphabet
    generateCipherAlphabet(keyword, cipherAlphabet);

    // Encrypt the plaintext
    encrypt(plaintext, cipherAlphabet, ciphertext);

    // Display the cipher alphabet and ciphertext
    printf("Cipher Alphabet: %s\n", cipherAlphabet);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
