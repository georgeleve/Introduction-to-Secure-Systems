#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LENGTH 11

// call by reference
void generateRandomKey(char *buffer, size_t keySize){
    int i;
    int fd;
    fd = open("/dev/urandom", O_RDONLY);
    if(fd < 0){
        perror("Error on generateRandomKey function\n");
    }
    read(fd, buffer, keySize);
    //buffer now contains the random data
    close(fd);
    for(i = 0; i < keySize; ++i)
       printf("%02X ", buffer[i]);
    printf("\n");
    printf("%d", sizeof(buffer));
}

int main(int argc, char *argv[]) {
    char const plaintext[LENGTH] = "HelloWorld";
    int keySize = LENGTH;
    char ciphertext[LENGTH];
    char key[LENGTH];
    int i;

    printf("PlainText: %s\n\n", plaintext);

    generateRandomKey(key, LENGTH);
    
    assert(sizeof(key)>=sizeof(plaintext));

    printf("Key: ");
    for(i = 0; i < LENGTH; ++i)
        printf("%02X ", key[i]);
    printf("\n");

    for(i=0; i < LENGTH; ++i)
        ciphertext[i] = (char)(plaintext[i] ^ key[i]);

    printf("Ciphertext: ");
    for(i = 0; i < LENGTH; ++i)
        printf("%02X ", ciphertext[i]);  //gt den tiponetai to 0x sthn arxh?
    printf("\n");
    return 0;
}