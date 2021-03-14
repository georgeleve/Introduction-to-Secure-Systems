#include "cs457_crypto.h"

/* Na ftiaxoume dika mas test file , eite apo arxeio na diabazei eite apo consola (kalytera na diabazei apo arxeio to plaintext) 
/* To input einai mono xarakthres tou ascii 
 isos iparxei proforikh exetash  isos na xrhsimopoihso thn toupper()  me to #include <ctype.h>*/
//  Na xrhsimopoihso thn  /dev/urandom  gia na kano generate random kleidia

//uint8_t = a type of unsigned integer of length 8 bits

//uint8_t is an unsigned 8 bit integer

//uint8_t* is a pointer to an 8 bit integer in ram
/* The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. */

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key){
   uint8_t ciphertext[LENGTH];
   assert(sizeof(key) >= sizeof(plaintext);
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
   assert(sizeof(key) >= sizeof(ciphertext);
   printf("\n\nDECRYPT\nciphertext: ");
   for(i=0; i<LENGTH; ++i)
      printf("%02X ", ciphertext[i]);
   printf("\nXOR\nkey: %s\n=\nplaintext: ", key);
   for(i=0; i<LENGTH; ++i)
      plaintext[i] = (char)(ciphertext[i] ^ key[i]);
   printf("%s\n", plaintext);
   return plaintext;
}


/*  Caesar’s cipher  - to N einai posa grammata thelo na kano shift */
uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
   uint8_t *ciphertext;
   return ciphertext;
}
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N){
   uint8_t *plaintext;
   return plaintext;
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
   f = a*x + b%m;
   return ciphertext;
}
uint8_t *affine_decrypt(uint8_t *ciphertext){
   uint8_t *plaintext;
   int a = 11;
   int b = 19;
   int m = 26;
   int D;
   D = a^-1 * (x - b) % m;
   return plaintext;
}

/* Feistel cipher */
uint8_t *round(uint8_t* block, uint8_t *key){
   uint8_t *result;
   //R[];
   //K[];
   F = (R[i] * K[i])%(2^32);
   return result; // returns one output the same size as the data block
}
uint8_t *feistel_encrypt(uint8_t *plaintext, uint8_t keys[]){
   uint8_t *ciphertext;
   int R, L;
   int S = 64; // block size of 64 bits
   int n_rounds = 8;
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    round(block, keys[i]);
   } 
   return ciphertext;
}
uint8_t *feistel_decrypt(uint8_t *ciphertext, uint8_t keys[]){
   uint8_t *plaintext;
   int R, L;
   int S = 64;
   int n_rounds = 8;
   for(i = 0; i < n_rounds; i++){
      // kapou tha kalo thn round    round(block, keys[i]);
   }
   return plaintext;
}


int main(void) {
   uint8_t plaintext[LENGTH] = "HelloWorld";
   uint8_t key[LENGTH] = "randombyte";
   uint8_t ciphertext[LENGTH];

   /* One-Time Pad (OTP) */
   ciphertext = uint8_t *otp_encrypt(plaintext, key);
   uint8_t *otp_decrypt(ciphertext, key);

   /* Caesar’s cipher
   uint8_t *caesar_encrypt(plaintext, 3);
   uint8_t *caesar_decrypt(ciphertext, 3);
   */

   /* Playfair cipher
   unsigned char *playfair_encrypt(plaintext, key);
   unsigned char *playfair_decrypt(ciphertext, key);
   unsigned char **playfair_keymatrix(key);
   */

   /* Affine cipher 
   uint8_t *affine_encrypt(plaintext);
   uint8_t *affine_decrypt(ciphertext);
   */

   /* Feistel cipher
   uint8_t* round(block, key);
   uint8_t* feistel_encrypt(plaintext, keys[]);
   uint8_t* feistel_decrypt(ciphertext, keys[]);
   */

   return 0;
}