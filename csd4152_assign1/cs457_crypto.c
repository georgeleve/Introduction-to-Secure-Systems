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
   uint8_t *ciphertext;
   int i;
   assert(sizeof(key) >= sizeof(plaintext));
   printf("\nENCRYPT\n");
   for(i=0; i<LENGTH; ++i)
      ciphertext[i] = (char)(plaintext[i] ^ key[i]);
   printf("plaintext: %s\nXOR\nkey: %s\n=\nciphertext: ", plaintext, key);
   for(i=0; i<LENGTH; ++i)
      printf("%02X ", ciphertext[i]);
   return ciphertext;
}
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key){
   uint8_t *plaintext;
   int i;
   assert(sizeof(key) >= sizeof(ciphertext));
   printf("\n\nDECRYPT\nciphertext: ");
   for(i=0; i<LENGTH; ++i)
      printf("%02X ", ciphertext[i]);
   printf("\nXOR\nkey: %s\n=\nplaintext: ", key);
   for(i=0; i<LENGTH; ++i)
      plaintext[i] = (char)(ciphertext[i] ^ key[i]);
   
   printf("%s\n", plaintext);  // kapou edo troo segmentation
   return plaintext;
}


/*  Caesar’s cipher  - to N einai posa grammata thelo na kano shift */
uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
   char ch;
   int i;
   N = N % 26; /* N must be between 1-26 */ 
   
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + N;
			if(ch > 'z') ch = ch - 'z' + 'a' - 1;
			plaintext[i] = ch;
		}
      
      if(ch >= '0' && ch <= '9'){
			ch = ch + N;
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
   // edo to kanoniko plaintext xalaei epeidh to pernao by reference all den me peirazei afou 
   // den to xanaxrhsimopoio kapou
}
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N){
   char ch;
   int i;
   N = N % 26; /* N must be between 1-26 */ 
   
   for(i = 0; ciphertext[i] != '\0'; ++i){
		ch = ciphertext[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - N;
			if(ch < 'a') ch = ch + 'z' - 'a' + 1;
			ciphertext[i] = ch;
		}
      
      if(ch >= '0' && ch <= '9'){
			ch = ch - N;
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
   // edo to kanoniko ciphertext xalaei epeidh to pernao by reference all den me peirazei afou 
   //den to xanaxrhsimopoio kapou
}


/* Playfair cipher */   
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
   return result;
}


// Affine cipher    ^ (bitwise XOR)    only UPPERCASE
uint8_t *affine_encrypt(uint8_t *plaintext){
   uint8_t *ciphertext;
   int a = 11;
   int b = 19;
   int m = 26;
   int f;
   //f = a*x + b%m;
   return ciphertext;
}
uint8_t *affine_decrypt(uint8_t *ciphertext){
   uint8_t *plaintext;
   int a = 11;
   int b = 19;
   int m = 26;
   int D;
   //D = a^-1 * (x - b) % m;
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

void checkPlaintext(){
   
}

void onetimepad_cipher(){
   //uint8_t plaintext[LENGTH] = "HelloWorld";
   //uint8_t key[LENGTH] = "randombyte";
   //uint8_t ciphertext[LENGTH] = "";
   uint8_t *plaintext;
   uint8_t *ciphertext;
   uint8_t *key;

   otp_encrypt(plaintext, key); // apo edo prepei na krathso kapos to ciphertext
   otp_decrypt(ciphertext, key); // giati edo dino oti nanai 
}

void ceasars_cipher(){
   uint8_t *plaintext;
   uint8_t *ciphertext;
   ushort N = 4;
   int c;

   printf("---------------------------------------\nCeasar's Cipher");
   printf("\n---------------------------------------\n\n\n");

   /* Read input.txt character by character */
   FILE *file = fopen("input.txt", "r");
   size_t i = 0;

   if(file == NULL) perror("Could not open file\n");

   /* calculate the size of the file */
   fseek(file, 0, SEEK_END);
   long f_size = ftell(file);
   fseek(file, 0, SEEK_SET);

   plaintext = malloc(f_size);
   ciphertext = malloc(f_size);

   /* Read from input.txt and initialize the plaintext */
   while ((c = fgetc(file)) != EOF)
      plaintext[i++] = (char)c;
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
   playfair_encrypt(plaintext, key);
   playfair_decrypt(ciphertext, key);
   playfair_keymatrix(second_key);
}

void affine_cipher(){
   uint8_t *plaintext;
   uint8_t *ciphertext;
   affine_encrypt(plaintext);
   affine_decrypt(ciphertext);
}

void feistel_cipher(){
   uint8_t *plaintext;
   uint8_t *ciphertext;
   uint8_t keys[8];
   uint8_t* block;
   uint8_t *key;
   feistel_round(block, key);
   feistel_encrypt(plaintext, keys);
   feistel_decrypt(ciphertext, keys);
}

int main(int argc, char *argv[]) {

   //onetimepad_cipher();

   ceasars_cipher();

   //playfair_cipher();

   //affine_cipher(); 

   //feistel_cipher();

   return 0;
}