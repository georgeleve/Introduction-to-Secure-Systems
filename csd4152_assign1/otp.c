#include "cs457_crypto.h"

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key){
    int i;
    assert(strlen(key) >= strlen(plaintext));
    for(i = 0; i < strlen(key); ++i) plaintext[i] = (char)(plaintext[i] ^ key[i]);
    plaintext[i] = '\0';
    return plaintext;
}
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key){
    int i;
    assert(strlen(key) >= strlen(ciphertext));
    for(i=0; i < strlen(key); ++i) ciphertext[i] = (char)(ciphertext[i] ^ key[i]);
    ciphertext[i] = '\0';
    return ciphertext;
}
void onetimepad_cipher(){
    long fileLength, secretKeySize;
    uint8_t *plaintext, *ciphertext, *temp;
    int c, fd, i = 0;
    
    FILE *file = fopen("input.txt", "r");
    if(file == NULL) perror("Could not open file\n");
    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    plaintext = malloc(fileLength);
    ciphertext = malloc(fileLength);
    
    while ((c = fgetc(file)) != EOF)
        if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
    plaintext[i] = '\0';
    secretKeySize = fileLength;

    uint8_t *secretKey = malloc(secretKeySize);
    fd = open("/dev/urandom", O_RDONLY);
    read(fd, secretKey, strlen(plaintext)); // read random bytes (same size as the plaintext)
    close(fd);

    printf("---------------------------------------\nOne Time Pad Cipher\n---------------------------------------\n\n\n");

    printf("---------------------------------------\nENCRYPT:\n\n");
    printf("plaintext = %s            size = %ld\n     ^\n", plaintext, strlen(plaintext));
    printf("secret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("    size = %ld\n      =\n", secretKeySize);
    ciphertext = otp_encrypt(plaintext, secretKey);
    printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);
    printf("\n---------------------------------------\n");

    printf("\n\n---------------------------------------\nDECRYPT:\n\n");
    printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);
    printf("\n       ^\nsecret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("    size = %ld\n      =\n", secretKeySize);
    temp = malloc(fileLength);
    temp = otp_decrypt(ciphertext, secretKey);
    printf("plaintext = %s            size = %ld\n", temp, strlen(temp));
    printf("---------------------------------------\n");
}
int main(int argc, char *argv[]) {
   onetimepad_cipher();
   return 0;
}