#include "cs457_crypto.h"

uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
   char ch;
   int i, j;
   N = N % 62;
   printf("N = %d\n\n", N);
   uint8_t *ciphertext = malloc(strlen(plaintext) * sizeof(int));
   //48-57  0-9       65-90  A-Z    97-122 a-z
   char map[62] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //62 characters in total
   
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];
      j = 0;
      while(1){
         if(map[j] == ch) break;
         j++;
      }
      //printf("plaintextchar = %c    and   mapcharacter = %c\n", ch, map[j]);
      ch = map[(j+N)%62];
      ciphertext[i] = ch;
	}
   ciphertext[i] = '\0';  
   return ciphertext;
}
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N){
   char ch;
   int i, j;
   N = N % 62;
   printf("N = %d\n\n", N);
   uint8_t *plaintext2 = malloc(strlen(ciphertext) * sizeof(int)); 
   char map[62] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //62 characters in total
   
	for(i = 0; ciphertext[i] != '\0'; ++i){
		ch = ciphertext[i];
      j = 0;
      while(1){
         if(map[j] == ch) break;
         j++;
      }
      if((j-N)<0){
         ch = map[(62+j-N)%62];
      }else{
         ch = map[(j-N)];
      }
      plaintext2[i] = ch;
	}
   plaintext2[i] = '\0';  
   return plaintext2;
}
void caesars_cipher(){
   uint8_t *plaintext, *ciphertext, *plaintext2;
   ushort N = 5;
   long fileLength;
   int c;

   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   size_t i = 0;
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF)
      if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
   plaintext[i] = '\0';

   printf("---------------------------------------\nCaesar's Cipher\n---------------------------------------\n\n\n");
   
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\n", plaintext);
   assert(N >= 0);
   ciphertext = caesar_encrypt(plaintext, N);
   printf("ciphertext: %s\n", ciphertext);
   printf("---------------------------------------\n");

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: %s\n\n", ciphertext);
   plaintext2 = caesar_decrypt(ciphertext, N); //call by reference - opote metatrepo to ciphertext se plaintext
   printf("plaintext: %s\n", plaintext2);
   printf("---------------------------------------\n\n");

   free(plaintext);
   free(ciphertext);
   free(plaintext2);
}
int main(int argc, char *argv[]) {
   caesars_cipher();
   return 0;
}