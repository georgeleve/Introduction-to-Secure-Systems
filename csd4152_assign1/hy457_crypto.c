#include "hy457_crypto.h"

/* Na ftiaxoume dika mas test file , eite apo arxeio na diabazei eite apo consola (kalytera na diabazei apo arxeio to plaintext) 
/* To input einai mono xarakthres tou ascii 
 isos iparxei proforikh exetash   */

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key){
   /* The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. */
   static const uint8_t buffer[] = {5, 7, 3, 4, 9, 1, 3};
   uint8_t *rv = malloc(sizeof(buffer));
   if (rv != 0) memmove(rv, buffer, sizeof(buffer));
   return rv;
}
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key){
   int result;
   return result;
}


/*  Caesar’s cipher  - to N einai posa grammata thelo na kano shift */
uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N){
   int result;
   return result;
}
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N){
   int result;
   return result;
}


/* Playfair cipher */   
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char** key){
   //return something;
}
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char** key){
   //return something;
}
unsigned char **playfair_keymatrix(unsigned char *key){
   //return something;
}


/* Affine cipher */
uint8_t *affine_encrypt(uint8_t *plaintext){
   //return something;
}
uint8_t *affine_decrypt(uint8_t *ciphertext){
   //return something;
}


/* Feistel cipher */
uint8_t *round(uint8_t* block, uint8_t *key){
   //return something;
}
uint8_t *feistel_encrypt(uint8_t *plaintext, uint8_t keys[]){
   //return something;
}
uint8_t *feistel_decrypt(uint8_t *ciphertext, uint8_t keys[]){
   //return something;
}


int main(void) {
   printf("Hello, World!");

   /* One-Time Pad (OTP)
   uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key);
   uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key);
   */

   /* Caesar’s cipher
   uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N);
   uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N);
   */

   /* Playfair cipher
   unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char** key);
   unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char** key);
   unsigned char **playfair_keymatrix(unsigned char *key);
   */

   /* Affine cipher 
   uint8_t *affine_encrypt(uint8_t *plaintext);
   uint8_t *affine_decrypt(uint8_t *ciphertext);
   */

   /* Feistel cipher
   uint8_t* round(uint8_t* block, uint8_t* key);
   uint8_t* feistel_encrypt(uint8_t* plaintext, uint8_t keys[]);
   uint8_t* feistel_decrypt(uint8_t* ciphertext, uint8_t keys[]);
   */

   return 0;
}