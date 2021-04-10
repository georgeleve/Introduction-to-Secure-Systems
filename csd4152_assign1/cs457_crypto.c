#include "cs457_crypto.h"

/* Na ftiaxoume dika mas test file , eite apo arxeio na diabazei eite apo consola (kalytera na diabazei apo arxeio to plaintext) 
/* To input einai mono xarakthres tou ascii
 isos iparxei proforikh exetash  isos na xrhsimopoihso thn toupper()  me to #include <ctype.h>*/
//  Na xrhsimopoihso thn  /dev/urandom  gia na kano generate random kleidia

//uint8_t is an unsigned 8 bit integer (a type of unsigned integer of length 8 bits)

//uint8_t* is a pointer to an 8 bit integer in ram
/* The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. */

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key){
   int i;
   assert(strlen(key) >= strlen(plaintext));
   for(i = 0; i < strlen(key); ++i) plaintext[i] = (char)(plaintext[i] ^ key[i]);
   return plaintext;
}
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key){
   int i;
   assert(strlen(key) >= strlen(ciphertext));
   for(i=0; i < strlen(key); ++i) ciphertext[i] = (char)(ciphertext[i] ^ key[i]);
   return ciphertext;
}


uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
   char ch;
   int i;
   ushort N2;
   N2 = N % 10;
   N = N % 26; /* N must be between 1-26 */ 
   
   //48-57  0-9
   //65-90  A-Z
   //97-122 a-z
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];    
      if(ch >= '0' && ch <= '9'){
			ch = ch + N2;
			if(ch > '9') ch = ch - '9' + '0' - 1;
			plaintext[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + N;
			if(ch > 'Z') ch = ch - 'Z' + 'A' - 1;
			plaintext[i] = ch;
		}
		else if(ch >= 'a' && ch <= 'z'){
			ch = ch + N;
			//if(ch > 'z') ch = ch + ;
			plaintext[i] = ch;
		}else{
         printf("Invalid character!\n");
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
   ushort N2;
   N2 = N % 10;
   N = N % 26; /* N must be between 1-26 */ 
   
   for(i = 0; ciphertext[i] != '\0'; ++i){
		ch = ciphertext[i];
      if(ch >= '0' && ch <= '9'){
			ch = ch - N2;
			if(ch < '0') ch = ch + '9' - '0' + 1;
			ciphertext[i] = 53;
		}
      else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - N;
			if(ch < 'A') ch = ch + 'Z' - 'A' + 1;
			ciphertext[i] = ch;
		}
		else if(ch >= 'a' && ch <= 'z'){
			ch = ch - N;
			if(ch < 'a') ch = ch + 'z' - 'a' + 1;
			ciphertext[i] = ch;
		}else{
         printf("Invalid character!\n");
      }
	}
   ciphertext[i] = '\0';  
   return ciphertext;
   /* edo to kanoniko ciphertext xalaei epeidh to pernao by reference
      alla den me peirazei afou den to xanaxrhsimopoio kapou */
}


// can the plaintext be more than 25 characters?
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char** key){
   unsigned char *ciphertext;
   // do stuff
   return ciphertext;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char** key){
   unsigned char *plaintext;
   // do stuff
   return plaintext;
}
unsigned char **playfair_keymatrix(unsigned char *key){
   unsigned char **result;
   // do something
   return result;
}


/* Affine cipher    ^ (bitwise XOR)    only UPPERCASE */
uint8_t *affine_encrypt(uint8_t *plaintext){
   // “a” is a constant, “b”is the magnitude of the shift and “x” is the letter to encrypt
   uint8_t *ciphertext;
   int a = 11, b = 19, m = 26, f, x;
   f = (a*x+b)%m;
   return ciphertext;
}
uint8_t *affine_decrypt(uint8_t *ciphertext){
   // a^-1 is the modular multiplicative inverse of a mod m     The letter x denotes the encrypted letter
   uint8_t *plaintext;
   int a = 11, b = 19, m = 26, D, x;
   D = a^-1 * (x - b) % m;
   return plaintext;
}

/* Feistel cipher */
uint8_t *feistel_round(uint8_t* block, uint8_t *key){
   uint8_t *result;
   //R[];
   //K[];
   //F = (R[i] * K[i])%(2^32);
   return result; // returns one output the same size as the data block
}
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


void onetimepad_cipher(){
   printf("---------------------------------------\nOne Time Pad Cipher\n---------------------------------------\n\n\n");
   long fileLength, secretKeySize;
   uint8_t *plaintext, *ciphertext, *temp;
   int c, fd;
   size_t i = 0;

   FILE *file = fopen("input.txt", "r");
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);
  
   while ((c = fgetc(file)) != EOF){
      if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
   }
   plaintext[i] = '\0';
   secretKeySize = fileLength;

   i = 0; 
   uint8_t *secretKey = malloc(fileLength);
   fd = open("/dev/urandom", O_RDONLY);
   read(fd, secretKey, strlen(plaintext)); // read random bytes same size as the plaintext
   close(fd);

   assert(strlen(secretKey) >= strlen(plaintext));   // sometimes the assertion fails.. but why?        FIX THIS

   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext = %s            size = %ld\n     ^\n", plaintext, strlen(plaintext));
   printf("secret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("    size = %ld\n      =\n", secretKeySize);
   
   ciphertext = otp_encrypt(plaintext, secretKey);
 
   printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);

   printf("\n---------------------------------------\n");
   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", ciphertext[i]);
   printf("\n       ^\nsecret key = "); for(i = 0; i < secretKeySize; ++i) printf("%02X ", secretKey[i]); printf("    size = %ld\n      =\n", secretKeySize);
   
   temp = malloc(fileLength);
   temp = otp_decrypt(ciphertext, secretKey);
   printf("plaintext = %s            size = %ld\n", temp, strlen(temp));
}

void caesars_cipher(){
   uint8_t *plaintext;
   uint8_t *ciphertext;
   ushort N = 4;
   int c;
   long fileLength;

   printf("---------------------------------------\nCaesar's Cipher");
   printf("\n---------------------------------------\n\n\n");


   FILE *file = fopen("input.txt", "r");    /* Read input.txt character by character */
   size_t i = 0;
   if(file == NULL) perror("Could not open file\n");
   fseek(file, 0, SEEK_END);    /* calculate the size of the file */
   fileLength = ftell(file);
   fseek(file, 0, SEEK_SET);
   plaintext = malloc(fileLength);
   ciphertext = malloc(fileLength);

   /* Read from input.txt and initialize the plaintext */
   while ((c = fgetc(file)) != EOF){
      if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z')) plaintext[i++] = (char)c;
   }
   plaintext[i] = '\0';     

   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\nN = %d\n\n", plaintext, N);
   ciphertext = caesar_encrypt(plaintext, N);
   printf("ciphertext: %s\n", ciphertext);
   printf("---------------------------------------\n");

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: %s\n\nN = %d\n\n", plaintext, N);
   caesar_decrypt(ciphertext, N); //call by reference - opote metatrepo to ciphertext se plaintext
   printf("plaintext: %s\n", ciphertext);
   printf("---------------------------------------\n\n");
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

   /* Read from input.txt and initialize the plaintext */
   while ((c = fgetc(file)) != EOF){
      if(c>='A' && c<='Z') plaintext[i++] = (char)c;
   }
   plaintext[i] = '\0';  

   printf("---------------------------------------\nPlayfair Cipher");
   printf("\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\n", plaintext);


  // playfair_encrypt(plaintext, key);


   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   //playfair_decrypt(ciphertext, key);
   //playfair_keymatrix(second_key);
}

void affine_cipher(){
   printf("---------------------------------------\nAffine Cipher");
   printf("\n---------------------------------------\n\n\n");
   uint8_t *plaintext;
   uint8_t *ciphertext;
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

   /* Read from input.txt and initialize the plaintext */
   while ((c = fgetc(file)) != EOF){
      if(c>='A' && c<='Z'){
         plaintext[i++] = (char)c;
      }
      if (c>='a' && c<='z') {
         plaintext[i++] = toupper((char)c);
      }
   }
   plaintext[i] = '\0';

   printf("---------------------------------------\nENCRYPT:\n\n");
   printf("plaintext: %s\n\n", plaintext);
  // affine_encrypt(plaintext);

   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   //affine_decrypt(ciphertext);
}

void feistel_cipher(){
   printf("---------------------------------------\nFeistel Cipher");
   printf("\n---------------------------------------\n\n\n");
   uint8_t *plaintext;
   uint8_t *ciphertext;
   uint8_t keys[8];
   uint8_t* block;
   uint8_t *key;
   feistel_round(block, key);

   printf("---------------------------------------\nENCRYPT:\n\n");
   feistel_encrypt(plaintext, keys);

   printf("\nDECRYPT\n");
   feistel_decrypt(ciphertext, keys);
}

void checkPlaintext(){
   
}

int main(int argc, char *argv[]) {

   //onetimepad_cipher();

   //caesars_cipher();

   //playfair_cipher();

   affine_cipher(); 

   //feistel_cipher();

   return 0;
}
