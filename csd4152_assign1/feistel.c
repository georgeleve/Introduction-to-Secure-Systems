#include "cs457_crypto.h"

uint8_t *feistel_encrypt(uint8_t *plaintext, uint8_t keys[]){
   uint8_t *ciphertext;
   int R, L, i;
   int S = 64; // block size of 64 bits
   int n_rounds = 8;
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    round(block, keys[i]);
   } 
   return ciphertext;
}
uint8_t *feistel_decrypt(uint8_t *ciphertext, uint8_t keys[]){
   uint8_t *plaintext;
   int R, L, i;
   int S = 64;
   int n_rounds = 8;
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    round(block, keys[i]);
   }
   return plaintext;
}
uint8_t *feistel_round(uint8_t *block, uint8_t *key){
   uint8_t *result;
   //R[]; K[];
   //F = (R[i] * K[i])%(2^32);
   return result; // returns one output the same size as the data block
}
void feistel_cipher(){
   printf("---------------------------------------\nFeistel Cipher");
   printf("\n---------------------------------------\n\n\n");
   int i, fd, c;
   long fileLength;
   uint8_t *plaintext, *ciphertext, *block, *key;
   uint8_t keys[8];
   feistel_round(block, key);

   i = 0; 
   uint8_t *secretKey = malloc(fileLength);
   fd = open("/dev/urandom", O_RDONLY);
   read(fd, secretKey, strlen(plaintext)); // read random bytes same size as the plaintext
   close(fd);

   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF)
      plaintext[i++] = (char)c; // only read capital letters
   plaintext[i] = '\0';  


   printf("---------------------------------------\nENCRYPT:\n\n");
   //feistel_encrypt(plaintext, keys);
   printf("---------------------------------------\n");

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   //feistel_decrypt(ciphertext, keys);
   printf("---------------------------------------\n\n");
}
int main(int argc, char *argv[]) {
   feistel_cipher();
   return 0;
}