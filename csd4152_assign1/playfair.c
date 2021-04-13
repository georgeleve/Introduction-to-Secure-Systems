#include "cs457_crypto.h"

// can the plaintext be more than 25 characters?
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char **key){
   unsigned char *ciphertext;
   
   return ciphertext;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char **key){
   unsigned char *plaintext;

   return plaintext;
}

// na ftiaxo na mhn mporei na mpei to idio gramma polles fores
unsigned char **playfair_keymatrix(unsigned char *plaintext){
   printf("playfair keymatrix:\n   ");
   int plaintextSize = strlen(plaintext);
   int temp = 0;
   unsigned char grid[5][5]={"00000", "00000", "00000", "00000", "00000"}; 
   //unsigned char **grid
   for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
         if(temp < plaintextSize){
            //if(containsKey(plaintext[temp], grid) == 1) temp++;
            grid[i][j] = plaintext[temp];
         }else{
            if((temp+'A') == 'J') temp++; //skip letter J
            //if(containsKey((char) (temp + 'A'), char **grid) == 1) temp++;
            grid[i][j] = (char) (temp + 'A');
         }
         printf("%c  ", grid[i][j]);
         if(j == 4) printf("\n   ");
         temp++;
         //printf("grid[%d][%d] = %c\n", i, j, grid[i][j]);
      }
   }
   //return grid;   I NEED TO RETURN THIS
}
int containsKey(char letter, char **grid){
   for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) { 
      	if(grid[i][j] == letter) return 1;
      }
   }
   return 0;
}
int areInSameRow(char letter1, char letter2, unsigned char **key){
   return 0;
}
int areInSameColumn(char letter1, char letter2, unsigned char **key){
   return 0;
}
void playfair_cipher(){
   unsigned char *plaintext;
   unsigned char *ciphertext;
   unsigned char **key;
   long fileLength;
   int c, i = 0;
   char temp;

   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF) {
      if(c>='A' && c<='Z'){  // only read capital letters
         if((i % 2)==0){
            temp = (char)c; 
            plaintext[i++] = (char)c;
         }else{
            if(temp == (char)c)
               plaintext[i++] = 'X';  // check if we have two same letters in a row 
            else
               plaintext[i++] = (char)c;
         }
      }
   }

   // if the plaintext size is even, we arrend X at the end of the plaintext
   if(strlen(plaintext) % 2 != 0){
      plaintext[i++] = 'X';
      i++;
   }
   // replace 'J' with 'I' 
   for(int i = 0; i < strlen(plaintext); i++) if(plaintext[i] == 'J') plaintext[i] = 'I';
   plaintext[i] = '\0';

   printf("---------------------------------------\nPlayfair Cipher\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   //printf("plaintext: %s\n\n", plaintext);
   printf("plaintext: ");
   for(int i = 0; i < strlen(plaintext); i++) {
      printf("%c", plaintext[i]);
      if(i%2==1) printf(" ");
   }
   printf("\n\n");
   playfair_keymatrix(plaintext);
   // ciphertext = playfair_encrypt(plaintext, key);
   printf("\nciphertext: %s\n\n", ciphertext);
   printf("---------------------------------------\n\n\n");
  

   printf("---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: ");
   printf("\n\n");
   //playfair_decrypt(ciphertext, key);
   printf("plaintext: \n\n");
   //for(int i = 0; i < strlen(plaintext); i++) {
     // printf("%c", plaintext[i]);
      //if(i%2==1) printf(" ");
   //}
   printf("---------------------------------------\n\n");
}
int main(int argc, char *argv[]) {
    playfair_cipher();
    return 0;
}