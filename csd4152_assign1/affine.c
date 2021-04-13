#include "cs457_crypto.h"

int modInverse(int a, int m){ int i; for(i = 1; i < m; i++) if(((a%m)*(i%m))%m==1) return i; }

uint8_t *affine_encrypt(uint8_t *plaintext){
    char ch;
    int i, x;
    for(i = 0; plaintext[i] != '\0'; ++i){
        ch = plaintext[i];
        x = ch-65;
        ch = ((11*x)+19)%26+'A';  /* f(x) = ax + b mod m */
        plaintext[i] = ch;
    }
    plaintext[i] = '\0';
    return plaintext;
}
uint8_t *affine_decrypt(uint8_t *ciphertext){
    char ch;
    int i, x;
    for(i = 0; ciphertext[i] != '\0'; ++i){
        ch = ciphertext[i];
        x = ch - 'A';
        ch = (modInverse(11, 26) * (x-19)) % 26 + 'A' + 26; /* D(x) = a^-1 * (x - b) % m */
        x = ch;
        if(x > 90) ch -= 26;
        ciphertext[i] = ch; /* printf("---%d---",x); printf("%c", ch); */
    }
    ciphertext[i] = '\0';
    return ciphertext;
}
void affine_cipher(){
    uint8_t *plaintext;
    uint8_t *ciphertext;
    long fileLength;
    int c, i = 0;

    FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
    if(file == NULL) perror("Could not open file\n");
    fseek(file, 0, SEEK_END);    /* calculate the size of the file */
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);
    plaintext = malloc(fileLength);
    ciphertext = malloc(fileLength);

    while ((c = fgetc(file)) != EOF){
        if(c>='A' && c<='Z') plaintext[i++] = (char)c;
        if (c>='a' && c<='z') plaintext[i++] = toupper((char)c);
    }
    plaintext[i] = '\0';

    printf("---------------------------------------\nAffine Cipher\n---------------------------------------\n\n\n");
    
    printf("---------------------------------------\nENCRYPT:\n\n");
    printf("plaintext: %s\n\n", plaintext);
    ciphertext = affine_encrypt(plaintext);
    printf("ciphertext: %s\n", ciphertext);
    printf("---------------------------------------\n");
    
    printf("\n\n---------------------------------------\nDECRYPT:\n\n");
    printf("ciphertext: %s\n\n", ciphertext);
    affine_decrypt(ciphertext);
    printf("plaintext: %s\n", ciphertext); //call by reference - opote metatrepo to ciphertext se plaintext
    printf("---------------------------------------\n\n");
}
int main(int argc, char *argv[]) {
    affine_cipher();
    return 0;
}