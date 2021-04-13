#include "cs457_crypto.h"

uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
char ch;
   int i;
   ushort N2 = N % 10;
   N = N % 26; /* N must be between 1-26 */ 
   
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + N;
			if(ch > 'z') ch = ch - 'z' + 'a' - 1;
			plaintext[i] = ch;
		}
      
      if(ch >= '0' && ch <= '9'){
			ch = ch + N2;
			if(ch > '9') ch = ch - '9' + '0' - 1;
			plaintext[i] = ch;
		}

		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + N;
			if(ch > 'Z') ch = ch - 'Z' + 'A' - 1;
			plaintext[i] = ch;
		}
	}
   plaintext[i] = '\0';  
   return plaintext;
   /* edo to kanoniko plaintext xalaei epeidh to pernao by reference
      alla den me peirazei afou den to xanaxrhsimopoio kapou */
}
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N){
   char ch;
   int i;
   ushort N2 = N % 10;
   N = N % 26; /* N must be between 1-26 */ 
   
   for(i = 0; ciphertext[i] != '\0'; ++i){
		ch = ciphertext[i];
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - N;
			if(ch < 'a') ch = ch + 'z' - 'a' + 1;
			ciphertext[i] = ch;
		}
      if(ch >= '0' && ch <= '9'){
			ch = ch - N2;
			if(ch < '0') ch = ch + '9' - '0' + 1;
			ciphertext[i] = ch;
      }
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch - N;
			if(ch < 'A') ch = ch + 'Z' - 'A' + 1;
			ciphertext[i] = ch;
		}
	}
   ciphertext[i] = '\0';  
   return ciphertext;
   /* edo to kanoniko ciphertext xalaei epeidh to pernao by reference
      alla den me peirazei afou den to xanaxrhsimopoio kapou */
}
void caesars_cipher(){
   uint8_t *plaintext;
   uint8_t *ciphertext;
   ushort N = 4;
   int c;
   long fileLength;

   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   size_t i = 0;
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF)
      if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
   plaintext[i] = '\0';     

   printf("---------------------------------------\nCaesar's Cipher\n---------------------------------------\n\n\n");
   
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\nN = %d\n\n", plaintext, N);
   assert(N >= 0);
   ciphertext = caesar_encrypt(plaintext, N);
   printf("ciphertext: %s\n", ciphertext);
   printf("---------------------------------------\n");

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: %s\n\nN = %d\n\n", plaintext, N);
   caesar_decrypt(ciphertext, N); //call by reference - opote metatrepo to ciphertext se plaintext
   printf("plaintext: %s\n", ciphertext);
   printf("---------------------------------------\n\n");

   //free(plaintext);
   //free(ciphertext);
}
int main(int argc, char *argv[]) {
   caesars_cipher();
   return 0;
}