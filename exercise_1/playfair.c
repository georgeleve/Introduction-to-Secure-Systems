#include "cs457_crypto.h"

int getI(char temp, unsigned char **keymatrix){
   int i, j;
   for(i = 0; i < 5; i++){
      for(j = 0; j < 5; j++){
         if(keymatrix[i][j] == temp) return i;
      }
   }
   return -1;
}
int getJ(char temp, unsigned char **keymatrix){
   int i, j;
   for(i = 0; i < 5; i++){
      for(j = 0; j < 5; j++){
         if(keymatrix[i][j] == temp) return j;
      }
   }
   return -1;
}
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char **keymatrix){
   unsigned char *ciphertext;
   char temp1, temp2, temp1I, temp2I, temp1J, temp2J;
   int i,j;

   ciphertext = malloc(strlen(plaintext) * sizeof(unsigned char));

   for(i = 0; i < strlen(plaintext); i+=2){
      temp1 = plaintext[i];
      temp2 = plaintext[i+1];
      
      temp1I = getI(temp1, keymatrix);
      temp2I = getI(temp2, keymatrix);

      temp1J = getJ(temp1, keymatrix);
      temp2J = getJ(temp2, keymatrix);

      if(temp1I == temp2I){ //same row
         ciphertext[i] = keymatrix[temp1I][(temp1J+1)%5];
         ciphertext[i+1] = keymatrix[temp2I][(temp2J+1)%5];
      } else if(temp1J == temp2J){ //same column
         ciphertext[i] = keymatrix[(temp1I+1)%5][temp1J];
         ciphertext[i+1] = keymatrix[(temp2I+1)%5][temp2J];
      }else{ //same 3x3 grid
         ciphertext[i] = keymatrix[temp1I][temp2J];
         ciphertext[i+1] = keymatrix[temp2I][temp1J];
      }
   }
   ciphertext[i] = '\0';
   return ciphertext;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char **keymatrix){
   unsigned char *plaintext;
   char temp1, temp2, temp1I, temp2I, temp1J, temp2J;
   int i, j;
   plaintext = malloc(strlen(ciphertext) * sizeof(unsigned char));

   for(i = 0; i < strlen(ciphertext); i+=2){
      temp1 = ciphertext[i];
      temp2 = ciphertext[i+1];
      
      temp1I = getI(temp1, keymatrix);
      temp2I = getI(temp2, keymatrix);

      temp1J = getJ(temp1, keymatrix);
      temp2J = getJ(temp2, keymatrix);

      if(temp1I == temp2I){ //same row
         plaintext[i] = keymatrix[temp1I][(temp1J+5-1)%5];
         plaintext[i+1] = keymatrix[temp2I][(temp2J+5-1)%5];
      } else if(temp1J == temp2J){ //same column
         plaintext[i] = keymatrix[(temp1I+5-1)%5][temp1J];
         plaintext[i+1] = keymatrix[(temp2I+5-1)%5][temp2J];
      }else{ //same 3x3 grid
         plaintext[i] = keymatrix[temp1I][temp2J];
         plaintext[i+1] = keymatrix[temp2I][temp1J];
      }
   }
   plaintext[i] = '\0';

   return plaintext;
}
int containsKey(char letter, unsigned char **keymatrix){
   int i, j;
   for(i = 0; i < 5; i++) {
      for(j = 0; j < 5; j++) { 
      	if(keymatrix[i][j] == letter) return 1;
      }
   }
   return 0;
}
unsigned char **playfair_keymatrix(unsigned char *keyword){
   int keywordSize = strlen(keyword);
   int i, j, x, y, flag, temp = 0, temp2 = 0;
   
   // create 2D array (the key)
   unsigned char **keymatrix = (unsigned char**) malloc(5 * sizeof(unsigned char *));
   for (i=0; i<5; i++) keymatrix[i] = (unsigned char*)malloc(5 * sizeof(unsigned char));
   
   printf("\n\nkeyword: "); for(i = 0; i < keywordSize; i++) printf("%c", keyword[i]);
   
   for(i = 0; i < 5; i++){
      for(j = 0; j < 5; j++){
         int found = 0;
         while(temp<keywordSize){
            if(keyword[temp]<'A' || keyword[temp]>'Z' || containsKey(keyword[temp],keymatrix)){
               temp++;
            }else{
               found = 1;
               keymatrix[i][j] = keyword[temp++];
               break;
            }
         }
         if(found == 1) continue;
         for(char c = 'A'; c<='Z'; c++){
            if(!containsKey(c,keymatrix)){
               keymatrix[i][j] = c;
               break;
            }
         }
      }
   }
   return keymatrix;
}
void printKeymatrix(unsigned char **keymatrix){
   int i, j;
   printf("\n\nplayfair keymatrix:\n\n   ");
   for(i = 0; i < 5; i++){
      for(j = 0; j < 5; j++){
         printf("%c  ", keymatrix[i][j]);
         if(j == 4) printf("\n   ");
      }
   }
   printf("\n");
}
void playfair_cipher(){
   unsigned char *plaintext, *ciphertext, *keyword, *plaintext2;
   unsigned char **keymatrix;
   long fileLength;
   int c, j, i = 0;
   char temp;

   FILE *file = fopen("input.txt", "r");
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   
   while ((c = fgetc(file)) != EOF) {
      if(c>='A' && c<='Z'){  // only read capital letters
         if((i % 2)==0){
            temp = (char)c; 
            plaintext[i++] = (char)c;
         }else{
            if(temp == (char)c)  // check if we have two repeated letters
               plaintext[i++] = 'X';   
            else
               plaintext[i++] = (char)c;
         }
      }
   }
   if((strlen(plaintext) % 2) != 0){   // if the plaintext size is even, we append X at the end of the plaintext
      plaintext[i++] = 'X';
      i++;
   }
   plaintext[i] = '\0';

   keyword = "HELLO WORLD";
   for(i = 0; i < 6; i++) if(keyword[i] == 'J') keyword[i] = 'I';    /* replace 'J' with 'I' */

   printf("---------------------------------------\nPlayfair Cipher\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s", plaintext);
   keymatrix = playfair_keymatrix(keyword);
   printKeymatrix(keymatrix);
   ciphertext = playfair_encrypt(plaintext, keymatrix);
   printf("\nciphertext: %s\n", ciphertext);
   printf("---------------------------------------\n\n\n");
  
   printf("---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: %s\n", ciphertext);
   printKeymatrix(keymatrix);
   plaintext2 = playfair_decrypt(ciphertext, keymatrix);
   printf("plaintext: %s \n", plaintext2);
   printf("---------------------------------------\n\n");

   free(plaintext);
   free(ciphertext);
   free(keymatrix);
}
int main(int argc, char *argv[]) {
    playfair_cipher();
    return 0;
}