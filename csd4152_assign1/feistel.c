#include "cs457_crypto.h"

uint8_t *feistel_encrypt(uint8_t *plaintext, uint8_t keys[]){
   uint8_t *ciphertext = malloc(strlen(plaintext) * sizeof(int)); 
   int R, L, i, n_rounds = 8, S = 64; // block size of 64 bits
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    feistel_round(block, keys[i]);
   } 
   return ciphertext;
}
uint8_t *feistel_decrypt(uint8_t *ciphertext, uint8_t keys[]){
   uint8_t *plaintext2 = malloc(strlen(ciphertext) * sizeof(int)); 
   int R, L, i, S = 64, n_rounds = 8;
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    feistel_round(block, keys[i]);
   }
   return plaintext2;
}
uint8_t *feistel_round(uint8_t *block, uint8_t *key){
   uint8_t *result;
   //R[]; K[]; //F = (R[i] * K[i])%(2^32);
   return result; // returns one output the same size as the data block 
}
void feistel_cipher(){
   int fd, c, i =0;
   long fileLength;
   uint8_t *plaintext, *ciphertext, *block, *key, keys[8];

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

   while ((c = fgetc(file)) != EOF)
      plaintext[i++] = (char)c;  // only read capital letters
   plaintext[i] = '\0';

   printf("---------------------------------------\nFeistel Cipher\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n", plaintext);
   //feistel_encrypt(plaintext, keys);
   printf("\nciphertext: \n");
   printf("---------------------------------------\n");

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: \n");
   //feistel_decrypt(ciphertext, keys);
   printf("\nplaintext: \n");
   printf("---------------------------------------\n\n");

   //free(plaintext);
   //free(ciphertext);
   //free(plaintext2);
}
int main(int argc, char *argv[]) {
   feistel_cipher();
   return 0;
}