#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>

#define _GNU_SOURCE

#ifndef SYS_gettid
#error "SYS_gettid unavailable on this system"
#endif

#define gettid() ((pid_t)syscall(SYS_gettid))

int main(){
    write(1, "hello world", 11);
	
	write(1, "hello world", 11);
	
	write(1, "hello world", 11);
	write(1, "hello world", 11);
	
	gettid();
	
	// clone(); clone(); clone(); clone(); clone();
	// mmap(); mmap(); mmap(); mmap(); mmap();
	// gettid(); gettid(); gettid();   
	
	exit(-1);
	
	//FILE *file = fopen("input.txt", "r");
	
	//fclose(file);
    printf("\nEnd of execution of tracee.c\n-----------------------------\n\n");
}