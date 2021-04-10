---------------------------------------------------------------
Georgios Gerasimos Leventopoulos csd4152
Exercise 1 CS457 - Introduction to Security Systems
---------------------------------------------------------------

How to run it:

make otp
make caesars
make playfair
make affine
make feistel
make clean





 prostheto to key +  2^7     tha prostheso sto key     (1<<7)  h allios 2^7
----------------------------------------------------------------
TURNIN COMMAND: turnin assignment_1@hy457 csd4152_assign1

VERIFY TURNIN: ls -l ~hy457/TURNIN/assignment_1
----------------------------------------------------------------


να χρησιμοποιησω την συναρτηση toupper() της <ctype.h>

TO DO:
otp:
giati petaei assert error kamia fora?  strlen(secretKey) < strlen(plaintext)
na to xanatsekaro kai me special characters
● The messages can only contain digits (0-9) and printable letters (A-Za-z)
● Be careful with non printable ASCII characters!


caesars: 
FTIAXIMO TO ENCRYPT KAI TO DECRYPT
na to kano na paizei etsi opos to theloyn

Στην άσκηση το αλφάβητο του Ceasars που ζητάμε είναι
0-9A-Za-z. Οπότε το wrap around γίνετε σε όλο το αλφάβητο
και όχι ξεχωριστά σε μικρά, κεφαλαία, αριθμούς.'

Mono aytes tis times mporei na parei
48-57  0-9
65-90  A-Z
97-122 a-z


playfair:
mono kefalaia tha dothoun san eisodos