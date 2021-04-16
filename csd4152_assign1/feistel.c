#include "cs457_crypto.h"

uint32_t* feistel_encrypt(uint32_t* plaintext, uint32_t keys[]){
   int R, L, i, n_rounds = 8, S = 64; // block size of 64 bits
   uint32_t* result = plaintext;
   for(i = 0; i < n_rounds; i++) result = feistel_round(result, keys[i]);
   uint32_t tmp = result[0];
   result[0] = result[1];
   result[1] = tmp;
   return result;
}

uint32_t* feistel_decrypt(uint32_t *ciphertext, uint32_t keys[]){
   int R, L, i, n_rounds = 8, S = 64; // block size of 64 bits
   uint32_t* result = ciphertext;
   for(i = n_rounds-1; i >=0; i--) result = feistel_round(result, keys[i]);
   uint32_t tmp = result[0];
   result[0] = result[1];
   result[1] = tmp;
   return result;
}
uint32_t* feistel_round(uint32_t* block, uint32_t key){
   // block[0] = LEFT, block[1] = RIGHT
   uint32_t* result = malloc(sizeof(uint32_t)*2);
   result[0] = block[1];
   uint32_t hash = (block[1]*(uint64_t)key) % (((uint64_t)1)<<32);
   result[1] = hash^block[0];
   return result;
}
void feistel_cipher(){
   uint32_t keys[] = {6,44,65,4321,12312,67,5454,344};
   uint64_t block = 134133;
   printf("---------------------------------------\nPlayfair Cipher\n---------------------------------------\n\n\n");
   printf("---------------------------------------\nENCRYPT:\n\n");

   printf("plaintext: %llu\n\n", (long long unsigned) block);

   uint32_t* blockSplit = malloc(sizeof(uint32_t)*2);
   blockSplit[0] = block>>32;
   blockSplit[1] = block%(((uint64_t)1)<<32);

   uint32_t* enc = feistel_encrypt(blockSplit, keys);
   block = (((uint64_t)enc[0])<<32) + enc[1];
   printf("ciphertext: %llu\n", (long long unsigned) block);
   blockSplit[0] = block>>32;
   blockSplit[1] = block%(((uint64_t)1)<<32);
   
   printf("---------------------------------------\n");
   printf("\n\n---------------------------------------\nDECRYPT:\n\n");
   printf("ciphertext: %llu\n\n", (long long unsigned) block);
   uint32_t* dec = feistel_decrypt(blockSplit, keys);
   block = (((uint64_t)dec[0])<<32) + dec[1];
   printf("plaintext: %llu\n", (long long unsigned) block);  
   printf("---------------------------------------\n\n");

   free(blockSplit);
}
int main(int argc, char *argv[]) {
   feistel_cipher();
   return 0;
}