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

      if(temp1I == temp2I){
         ciphertext[i] = keymatrix[temp1I][(temp1J+1)%5];
         ciphertext[i+1] = keymatrix[temp2I][(temp2J+1)%5];
      } else if(temp1J == temp2J){
         ciphertext[i] = keymatrix[(temp1I+1)%5][temp1J];
         ciphertext[i+1] = keymatrix[(temp2I+1)%5][temp2J];
      }else{
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
   int i,j;
   plaintext = malloc(strlen(ciphertext) * sizeof(unsigned char));

   for(i = 0; i < strlen(ciphertext); i+=2){
      temp1 = ciphertext[i];
      temp2 = ciphertext[i+1];
      
      temp1I = getI(temp1, keymatrix);
      temp2I = getI(temp2, keymatrix);

      temp1J = getJ(temp1, keymatrix);
      temp2J = getJ(temp2, keymatrix);

      if(temp1I == temp2I){
         plaintext[i] = keymatrix[temp1I][(temp1J+5-1)%5];
         printf("plaintext[i] = %c", plaintext[i]);
         plaintext[i+1] = keymatrix[temp2I][(temp2J+5-1)%5];
      } else if(temp1J == temp2J){
         plaintext[i] = keymatrix[(temp1I+5-1)%5][temp1J];
         plaintext[i+1] = keymatrix[(temp2I+5-1)%5][temp2J];
      }else{
         plaintext[i] = keymatrix[temp1I][temp2J];
         plaintext[i+1] = keymatrix[temp2I][temp1J];
      }
   }
   plaintext[i] = '\0';

   return plaintext;
}
// na ftiaxo na mhn mporei na mpei to idio gramma polles fores
unsigned char **playfair_keymatrix(unsigned char *keyword){
   int keywordSize = strlen(keyword);
   int i, flag, j = 0, temp = 0, temp2 = 0;
   int x, y;

   unsigned char **keymatrix = (unsigned char**) malloc(5 * sizeof(unsigned char *));
   for (i=0; i<5; i++) keymatrix[i] = (unsigned char*)malloc(5 * sizeof(unsigned char));
   
   printf("\n\nkeyword: "); for(i = 0; i < keywordSize; i++) printf("%c", keyword[i]);
   
   for(i = 0; i < 5; i++){
      for(j = 0; j < 5; j++){
         if(temp < keywordSize){
            //put the keyword
            flag = 0;
            for(x = 0; x < 5; x++) {
               for(y = 0; y < 5; y++) { 
      	         if(keymatrix[x][y] == keyword[temp]) flag = 1;
               }
            }
            if(flag == 1) temp++;
            keymatrix[i][j] = keyword[temp++];
         }else{
            //put the rest of the alphabet

            //if contains the key then move to the next letter
            flag = 0;
            for(x = 0; x < 5; x++) {
               for(y = 0; y < 5; y++) {
      	         if(keymatrix[x][y] == ((char) (temp2 + 'A'))) flag = 1;
               }
            }

            if(flag == 1) temp2++; // skip the letters that are already in

            if((temp2+'A') == 'J') temp2++; // skip letter J
            keymatrix[i][j] = (char) (temp2 + 'A');
            temp2++; // move to the next letter of the alphabet
         }
      }
   }
   return keymatrix;
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

   keyword = "LIZARD\0";
   for(i = 0; i < 6; i++) if(keyword[i] == 'J') keyword[i] = 'I';    /* replace 'J' with 'I' */

   printf("---------------------------------------\nPlayfair Cipher");
   printf("\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s", plaintext);

   unsigned char **keymatrix = playfair_keymatrix(keyword);
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