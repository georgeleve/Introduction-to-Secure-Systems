#include "cs457_crypto.h"

#define LENGTH 11

int main() {
    uint8_t *plaintext = "HelloWorld";
    uint8_t *key = "randombyte";
    uint8_t *ciphertext;
    int i;

    printf("\nENCRYPT\n");
    for(i=0; i<LENGTH; ++i)
        ciphertext[i] = (char)(plaintext[i] ^ key[i]);
    printf("plaintext: %s\nXOR\nkey: %s\n=\nciphertext: ", plaintext, key);
    for(i=0; i<LENGTH; ++i)
        printf("%02X ", ciphertext[i]);
    
    printf("\n\nDECRYPT\nciphertext: ");
    for(i=0; i<LENGTH; ++i)
        printf("%02X ", ciphertext[i]);
    printf("\nXOR\nkey: %s\n=\nplaintext: ", key);
    for(i=0; i<LENGTH; ++i)
        plaintext[i] = (char)(ciphertext[i] ^ key[i]);
    printf("%s\n", plaintext);

    return 0;
}