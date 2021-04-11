#include "cs457_crypto.h"

// can the plaintext be more than 25 characters?
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char** key){
   unsigned char *ciphertext;
   
   return ciphertext;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char** key){
   unsigned char *plaintext;

   return plaintext;
}
unsigned char **playfair_keymatrix(unsigned char *key){
   unsigned char **result;


   return result;
}
void playfair_cipher(){
   unsigned char *plaintext;
   unsigned char *ciphertext;
   unsigned char **key;
   unsigned char *second_key;
   long fileLength;
   int c;

   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   size_t i = 0;
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF)
      if(c>='A' && c<='Z') plaintext[i++] = (char)c; // only read capital letters
   plaintext[i] = '\0';

   printf("---------------------------------------\nPlayfair Cipher");
   printf("\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\n", plaintext);
   printf("---------------------------------------\n\n\n");

  // playfair_encrypt(plaintext, key);

   printf("---------------------------------------\nDECRYPT:\n\n");
   //playfair_decrypt(ciphertext, key);
   //playfair_keymatrix(second_key);
   printf("---------------------------------------\n\n");
}
int main(int argc, char *argv[]) {
    playfair_cipher();
    return 0;
}