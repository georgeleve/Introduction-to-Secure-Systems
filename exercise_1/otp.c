#include "cs457_crypto.h"

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key){
    int i;
    assert(strlen(key) >= strlen(plaintext));
    uint8_t *ciphertext = malloc(strlen(plaintext) * sizeof(int));
    for(i = 0; i < strlen(key); ++i) ciphertext[i] = (char)(plaintext[i] ^ key[i]);
    ciphertext[i] = '\0';
    return ciphertext;
}
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key){
    int i;
    assert(strlen(key) >= strlen(ciphertext));
    uint8_t *plaintext2 = malloc(strlen(ciphertext) * sizeof(int));
    for(i=0; i < strlen(key); ++i) plaintext2[i] = (char)(ciphertext[i] ^ key[i]);
    plaintext2[i] = '\0';
    return plaintext2;
}
void onetimepad_cipher(){
    uint8_t *plaintext, *ciphertext, *plaintext2;
    long fileLength, secretKeySize;
    int c, fd, i = 0;
    
    FILE *file = fopen("input.txt", "r");
    if(file == NULL) perror("Could not open file\n");
    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    plaintext = malloc(fileLength);
    
    while ((c = fgetc(file)) != EOF)
        if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
    plaintext[i] = '\0';
    secretKeySize = fileLength;

    uint8_t *secretKey = malloc(secretKeySize);
    fd = open("/dev/urandom", O_RDONLY);
    read(fd, secretKey, strlen(plaintext)); // read random bytes (same size as the plaintext)
    close(fd);

    printf("-----------------------------------------------------------------------\nOne Time Pad Cipher\n-----------------------------------------------------------------------\n\n\n");

    printf("-----------------------------------------------------------------------\nENCRYPT:\n\n");
    printf("plaintext = %s            size = %ld\n     ^\n", plaintext, strlen(plaintext));
    printf("secret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("  size = %ld\n      =\n", secretKeySize);
    ciphertext = otp_encrypt(plaintext, secretKey);
    printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);
    printf("\n-----------------------------------------------------------------------\n");

    printf("\n\n-----------------------------------------------------------------------\nDECRYPT:\n\n");
    printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);
    printf("\n       ^\nsecret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("  size = %ld\n      =\n", secretKeySize);

    plaintext2 = otp_decrypt(ciphertext, secretKey);
    printf("plaintext = %s            size = %ld\n", plaintext2, strlen(plaintext2));
    printf("-----------------------------------------------------------------------\n");

    free(plaintext);
    free(ciphertext);
    free(plaintext2);
}
int main(int argc, char *argv[]) {
   onetimepad_cipher();
   return 0;
}