#include "cs457_crypto.h"


#define LENGTH 11

int main() {
    uint8_t *plaintext;
    uint8_t *ciphertext;
    uint8_t *temp;
    //uint8_t *key = "randombyte";
    
    /*
    printf("\nENCRYPT\n");
    for(i=0; i<LENGTH; ++i)
        ciphertext[i] = (char)(plaintext[i] ^ key[i]);
    printf("plaintext: %s\nXOR\nkey: %s\n=\nciphertext: ", plaintext, key);
    for(i=0; i<LENGTH; ++i)
        printf("%02X ", ciphertext[i]);
    
    printf("\n\nDECRYPT\nciphertext: ");
    for(i=0; i<LENGTH; ++i)
        printf("%02X ", ciphertext[i]);
    printf("\nXOR\nkey: %s\n=\nplaintext: ", key);
    for(i=0; i<LENGTH; ++i)
        plaintext[i] = (char)(ciphertext[i] ^ key[i]);
    printf("%s\n", plaintext);
    */

   /* Give a number and i will return you the ascii value */
   /* a-z   97-122 */   /* A - Z  65 - 90 */  /*  0 - 9   48 - 57 */
    /*
    int e;
    char ch;
    printf("\n Enter a character : ");
    scanf("%c",&ch);
    e=ch;
    printf("\n The ASCII value of the character is : %d\n",e);
    return 0;
    */

    /* read from a file character by character */
    FILE *file = fopen("input.txt", "r");
    size_t i = 0;
    int c;

    if(file == NULL) perror("Could not open file\n");

    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    plaintext = malloc(f_size);
    ciphertext = malloc(f_size);
    temp = malloc(f_size);

    while ((c = fgetc(file)) != EOF)
        plaintext[i++] = (char)c;
    plaintext[i] = '\0';     

    // uncomment to print the plaintext
    for(i = 0;  plaintext[i] != '\0';  i++){
        int ch;
        ch = plaintext[i];
        printf("'%c' %3d\n", ch, ch);
    }
    
	char ch;
	int key;
	
	//printf("Enter a message to encrypt: ");
	//gets(message);
	printf("Enter key: ");
	scanf("%d", &key);
    key = key%26;
	
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			if(ch > 'z') ch = ch - 'z' + 'a' - 1;
			plaintext[i] = ch;
		}
        if(ch >= '0' && ch <= '9'){
			ch = ch + key;
			if(ch > '9') ch = ch - '9' + '0' - 1;
			plaintext[i] = ch;
		}
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			if(ch > 'Z') ch = ch - 'Z' + 'A' - 1;
			plaintext[i] = ch;
		}
	}
    plaintext[i] = '\0';  
	printf("Encrypted message(ciphertext): %s\n", plaintext);


    /*
    for(i = 0; ciphertext[i] != '\0'; ++i){
		ch = ciphertext[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;
			if(ch < 'a') ch = ch + 'z' - 'a' + 1;
			temp[i] = ch;
		}
        if(ch >= '0' && ch <= '9'){
			ch = ch - key;
			if(ch < '0') ch = ch + '9' - '0' + 1;
			temp[i] = ch;
		}
		if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
			if(ch < 'A') ch = ch + 'Z' - 'A' + 1;
			temp[i] = ch;
		}
	}
    temp[i] = '\0';

    printf("Decrypted message:(plaintext) %s", temp);
    */

	return 0;
}