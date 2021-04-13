#include "cs457_crypto.h"

int getI(char temp, unsigned char **keymatrix){
   int i,j;
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

   ciphertext = malloc(strlen(plaintext)); //* sizeof(char)  ??

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

   plaintext = malloc(strlen(ciphertext)); // *sizeof(char))   ???

   for(i = 0; i < strlen(plaintext); i+=2){
      temp1 = ciphertext[i];
      temp2 = ciphertext[i+1];
      
      temp1I = getI(temp1, keymatrix);
      temp2I = getI(temp2, keymatrix);

      temp1J = getJ(temp1, keymatrix);
      temp2J = getJ(temp2, keymatrix);

      if(temp1I == temp2I){
         plaintext[i] = keymatrix[temp1I][(temp1J+5-1)%5];
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
   int i, flag, temp = 0, temp2 = 0;
   unsigned char grid[5][5] = {"00000", "00000", "00000", "00000", "00000"}; // kai me malloc mporo
   
   printf("\n\nkeyword: "); for(i = 0; i < keywordSize; i++) printf("%c", keyword[i]); //PRINT KEYWORD
   
   printf("\n\nplayfair keymatrix:\n   ");
   for(i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
         if(temp < keywordSize){
            //put the keyword
            flag = 0;
            for(int i = 0; i < 5; i++) {
               for(int j = 0; j < 5; j++) { 
      	         if(grid[i][j] == keyword[temp]) flag = 1;
               }
            }
            if(flag == 1) temp++;
            grid[i][j] = keyword[temp++];
         }else{
            //put the rest of the alphabet

            //if contains the key then move to the next letter
            flag = 0;
            for(int i = 0; i < 5; i++) {
               for(int j = 0; j < 5; j++) { 
      	         if(grid[i][j] == ((char) (temp2 + 'A'))) flag = 1;
               }
            }

            if(flag == 1) temp2++; // skip the letters that are already in

            if((temp2+'A') == 'J') temp2++; // skip letter J
            grid[i][j] = (char) (temp2 + 'A');
            temp2++; // move to the next letter of the alphabet
         }
         printf("%c  ", grid[i][j]);
         if(j == 4) printf("\n   ");
         // printf("grid[%d][%d] = %c\n", i, j, grid[i][j]);
      }
   }
   //return grid;   //I NEED TO RETURN THIS correctly
}
int containsKey(char letter, unsigned char **grid){
   for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) { 
      	if(grid[i][j] == letter) return 1;
      }
   }
   return 0;
}

void playfair_cipher(){
   unsigned char *plaintext;
   unsigned char *ciphertext;
   unsigned char *keyword;
   unsigned char **keymatrix;
   long fileLength;
   int c, i = 0;
   char temp;
   unsigned char grid[5][5] = {"00000", "00000", "00000", "00000", "00000"};

   FILE *file = fopen("input.txt", "r");
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength); // NOT SURE ABOUT THIS MALLOC
   ciphertext = malloc(fileLength);

   while ((c = fgetc(file)) != EOF) {
      if(c>='A' && c<='Z'){  // only read capital letters
         if((i % 2)==0){
            temp = (char)c; 
            plaintext[i++] = (char)c;
         }else{
            if(temp == (char)c)       // check if we have two repeated letters
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

   // MEXRI EDO KALA - tora arxikopoio to keyword
   i = 0;
   keyword = malloc(fileLength); //NOT SURE ABOUT THIS MALLOC
   keyword = "LIZARD\0";
   //keyword[i++] = (char)'L'; // or put it letter by letter like that 

   // replace 'J' with 'I'
   for(i = 0; i < 6; i++) if(keyword[i] == 'J') keyword[i] = 'I';

   printf("---------------------------------------\nPlayfair Cipher");
   printf("\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");

   printf("plaintext: ");
   for(int i = 0; i < strlen(plaintext); i++) printf("%c", plaintext[i]); if(i%2==1) printf(" ");
   
   // grid = playfair_keymatrix(keyword);

   // ciphertext = playfair_encrypt(plaintext, key);
   printf("\nciphertext: %s\n\n", ciphertext);
   printf("---------------------------------------\n\n\n");
  
   printf("---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: ");
   for(int i = 0; i < strlen(plaintext); i++) printf("%c", plaintext[i]); if(i%2==1) printf(" ");
   printf("\n\n");
   //playfair_decrypt(ciphertext, key);
   printf("plaintext: \n\n");
   //for(int i = 0; i < strlen(plaintext); i++) printf("%c", plaintext[i]); if(i%2==1) printf(" ");
   printf("---------------------------------------\n\n");

   //free(plaintext);
   //free(ciphertext);
   //free(keyword);
}
int main(int argc, char *argv[]) {
    playfair_cipher();
    return 0;
}