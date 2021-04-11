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

TO DO:
otp:
giati petaei assert error kamia fora?  strlen(secretKey) < strlen(plaintext)
ama exo george$$$ tote eite to diavazo san george eite apla kano encrypt to george mono kai ta alla ta afhno os exei
isos na vazo kathe fora sto kleidi 2^7

caesars: 
-FTIAXIMO TO ENCRYPT KAI TO DECRYPT
-Στην άσκηση το αλφάβητο του Ceasars που ζητάμε είναι 0-9A-Za-z. Οπότε το wrap around γίνετε σε όλο το αλφάβητο και όχι ξεχωριστά σε μικρά, κεφαλαία, αριθμούς.
-Mono aytes tis times mporei na parei 48-57  0-9       65-90  A-Z    97-122 a-z

playfair:
to N mporei na einai megalytero toy 62   
fiavazeis mexri na teleiosoun oi carakthres h mexri na gemisei to cipher

feistel:
isos na to allaxo se *keys[]
8 kleidia(dhladh na ginoun 8 rounds)






/* To input einai mono xarakthres tou ascii

//uint8_t is an unsigned 8 bit integer (a type of unsigned integer of length 8 bits)

//uint8_t* is a pointer to an 8 bit integer in ram
/* The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. */