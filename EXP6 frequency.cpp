#include <stdio.h> 
#include <string.h> 
int findMultiplicativeInverse(int a) { 
 int inverse; 
 for (inverse = 1; inverse < 26; inverse++) { 
 if ((a * inverse) % 26 == 1) { 
 return inverse; 
 } 
 } 
 return -1;
} 
int main() { 
 char mostFrequent = 'B'; 
 char secondMostFrequent = 'U';  
 int mostFrequentValue = mostFrequent - 'A'; 
 int secondMostFrequentValue = secondMostFrequent - 'A'; 
 int a = (mostFrequentValue - secondMostFrequentValue + 26) % 26; 
 int inverseA = findMultiplicativeInverse(a); 
 if (inverseA == -1) { 
 printf("The multiplicative inverse of 'a' does not exist. Cannot break the cipher.\n"); 
 return 1; 
 } 
 int b = (mostFrequentValue - (inverseA * mostFrequentValue)) % 26; 
 if (b < 0) { 
 b += 26; 
 } 
 printf("Affine Cipher Parameters:\n"); 
 printf("a = %d\n", a); 
 printf("b = %d\n", b); 
 printf("Inverse of a = %d\n", inverseA); 
 printf("Plaintext:\n"); 
 char ciphertext[] = "YOUR_CIPHERTEXT_HERE"; 
 int ciphertextLength = strlen(ciphertext); 
 int i ; 
 for ( i = 0; i < ciphertextLength; i++) { 
 char encryptedChar = ciphertext[i]; 
 if (encryptedChar >= 'A' && encryptedChar <= 'Z') { 
 int encryptedValue = encryptedChar - 'A'; 
 int decryptedValue = (inverseA * (encryptedValue - b)) % 26; 
 if (decryptedValue < 0) { 
 decryptedValue += 26; // Ensure it's positive 
 } 
 char decryptedChar = decryptedValue + 'A'; 
 printf("%c", decryptedChar); 
 } else { 
 printf("%c", encryptedChar); 
 } 
 } 
 printf("\n"); 
 
 return 0; 
}