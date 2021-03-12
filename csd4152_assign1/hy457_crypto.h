#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <sys/socket.h>

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key);
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key);


/* Caesar’s cipher */
uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N);
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N);

/* Playfair cipher */
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char **key);
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char **key);
unsigned char **playfair_keymatrix(unsigned char *key);

/* Affine cipher */
uint8_t *affine_encrypt(uint8_t *plaintext);
uint8_t *affine_decrypt(uint8_t *ciphertext);

/* Feistel cipher */
uint8_t *round(uint8_t *block, uint8_t *key);
uint8_t *feistel_encrypt(uint8_t *plaintext, uint8_t keys[]);
uint8_t *feistel_decrypt(uint8_t *ciphertext, uint8_t keys[]);