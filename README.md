# [Introduction-to-Secure-Systems](https://www.csd.uoc.gr/~hy457/index.html)  

Exercise 2:  
- Part 1: System call tracker in C. Tracked the number of system calls in a C program.
- Part 2: Modified an old version of the Linux kernel to add a new functionality (used QEMU).    



Exercise 1 - Encryption Algorithms implemented in C (One Time Pad, Caesars Cipher, Playfair Cipher, Affine Cipher, Feistel Cipher):

How to use it:
- clone the project
- cd exercise_1
- make a file "input.txt" and write the message that you want to encrypt
- type "make" and then the name of the algorithm that you want to use  (e.g.: "make playfair")

Available commands the user can type:
- make otp
- make caesars
- make playfair
- make affine
- make feistel

Each of these commands will use a different algorithm to encrypt the message.

You can see the output in the images below (input="HELLOWORLD")

- One Time Pad  
![alt text](https://github.com/georgeleve/CS457-Introduction-to-Security-Systems/blob/main/images/otp.jpg)  

- Caesars Cipher  
![alt text](https://github.com/georgeleve/CS457-Introduction-to-Security-Systems/blob/main/images/caesars.jpg)  

- Playfair Cipher  
![alt text](https://github.com/georgeleve/CS457-Introduction-to-Security-Systems/blob/main/images/playfair.jpg)  

- Affine Cipher  
![alt text](https://github.com/georgeleve/CS457-Introduction-to-Security-Systems/blob/main/images/affine.jpg)  

- Feistel Cipher  
![alt text](https://github.com/georgeleve/CS457-Introduction-to-Security-Systems/blob/main/images/feistel.jpg)  
