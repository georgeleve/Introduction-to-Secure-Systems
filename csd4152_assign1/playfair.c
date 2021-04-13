#include "cs457_crypto.h"

// can the plaintext be more than 25 characters?
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char **keymatrix){
   unsigned char *ciphertext;
   
   return ciphertext;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char **keymatrix){
   unsigned char *plaintext;

   return plaintext;
}

// na ftiaxo na mhn mporei na mpei to idio gramma polles fores
unsigned char **playfair_keymatrix(unsigned char *keyword){
   int i;
   int keywordSize = strlen(keyword);
   int temp = 0, temp2 = 0;
   unsigned char grid[5][5]={"00000", "00000", "00000", "00000", "00000"};
   int flag = 1;
   
   printf("\n\nkeyword: "); for(i = 0; i < 6; i++) printf("%c", keyword[i]); //PRINT KEYWORD
   
   //unsigned char **grid
   printf("\n\nplayfair keymatrix:\n   ");
   for(i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
         if(temp < keywordSize){
            //if(containsKey(plaintext[temp], grid) == 1) temp++;
            grid[i][j] = keyword[temp++];
         }else{

            flag = 0;
            //if contains the key then move to the next letter
            for(int i = 0; i < 5; i++) {
               for(int j = 0; j < 5; j++) { 
      	         if(grid[i][j] == ((char) (temp2 + 'A'))) flag = 1;
               }
            }

            if(flag == 1) temp2++; // skip the letters that are already in
            if((temp2+'A') == 'J') temp2++; //skip letter J
            grid[i][j] = (char) (temp2 + 'A');
            temp2++;
         }
         printf("%c  ", grid[i][j]);
         if(j == 4) printf("\n   ");  
         //printf("grid[%d][%d] = %c\n", i, j, grid[i][j]);
      }
   }
   //return grid;   I NEED TO RETURN THIS
}
int containsKey(char letter, unsigned char **grid){
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
   unsigned char *keyword;
   
   long fileLength;
   unsigned char **keymatrix;
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
            if(temp == (char)c)        // check if we have two repeated letters
               plaintext[i++] = 'X';   
            else
               plaintext[i++] = (char)c;
         }
      }
   }
   if((strlen(plaintext) % 2) != 0){    // if the plaintext size is even, we append X at the end of the plaintext
      plaintext[i++] = 'X';
      i++;
   }
   plaintext[i] = '\0';

   // MEXRI EDO KALA - tora arxikopoio to keyword
   i = 0;
   keyword = malloc(fileLength); //NOT SURE ABOUT THIS MALLOC
   keyword[i++] = (char)'L';
   keyword[i++] = (char)'I';
   keyword[i++] = (char)'Z';
   keyword[i++] = (char)'A';
   keyword[i++] = (char)'R';
   keyword[i++] = (char)'D';
   keyword[i++] = '\0';
   // replace 'J' with 'I' 
   for(i = 0; i < 6; i++) if(keyword[i] == 'J') keyword[i] = 'I';

   printf("---------------------------------------\nPlayfair Cipher\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   //printf("plaintext: %s\n\n", plaintext);
   printf("plaintext: ");
   for(int i = 0; i < strlen(plaintext); i++) {
      printf("%c", plaintext[i]);
      if(i%2==1) printf(" ");
   }
   
   playfair_keymatrix(keyword);




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