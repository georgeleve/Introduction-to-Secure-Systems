#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <assert.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <ctype.h>

#define LENGTH 11

/* One-Time Pad (OTP) */
uint8_t *otp_encrypt(uint8_t *plaintext, uint8_t *key);
uint8_t *otp_decrypt(uint8_t *ciphertext, uint8_t *key);

/* Caesar’s cipher */
uint8_t *caesar_encrypt(uint8_t *plaintext, ushort N);
uint8_t *caesar_decrypt(uint8_t *ciphertext, ushort N);

/* Playfair cipher */
unsigned char *playfair_encrypt(unsigned char *plaintext, unsigned char **keymatrix);
unsigned char *playfair_decrypt(unsigned char *ciphertext, unsigned char **keymatrix);
unsigned char **playfair_keymatrix(unsigned char *key);

/* Affine cipher */
uint8_t *affine_encrypt(uint8_t *plaintext);
uint8_t *affine_decrypt(uint8_t *ciphertext);

/* Feistel cipher */
uint32_t* feistel_round(uint32_t* block, uint32_t key); //may make it uint32_t
uint32_t* feistel_encrypt(uint32_t *plaintext, uint32_t keys[]); //may make it uint64
uint32_t* feistel_decrypt(uint32_t *ciphertext, uint32_t keys[]);