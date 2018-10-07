#include <stdio.h>
#include <unistd.h> // for exec system call
#include  <sys/types.h> // for wait system call
#include "test.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int externCounter;
void main() {
	int i = 5;
	

	char *argv[4] = {"ls","./","-l",  NULL};
	pid_t ret = fork();
	if(ret == 0 ) { // child
		//printf("\n\t\tret == 0, i =%d",i);
		sleep(12);

		execvp(argv[0], argv);
	}	
	if(ret > 0) {
		
		int statusOfBFProc = -1;
		while(1){
			printf("\nIN\n");
			sleep(1);
			waitpid(ret,&statusOfBFProc, WNOHANG);
			printf("state = %d 0f %d\n", statusOfBFProc, ret);
	
			if (WIFEXITED(statusOfBFProc)  ){
     			 printf("Child exited with code %d\n", WEXITSTATUS(statusOfBFProc));
     			 wait(&ret);
     			 exit(0);
			}
			
   			else if (WIFSIGNALED(statusOfBFProc) ){
				printf("Child terminated abnormally, signal %d\n", WTERMSIG(statusOfBFProc));
   				wait(&ret);
   				exit(0);
   			}
   			
		}
		//wait(&ret);
	}

	//printf("\nexternCounter=%d\n",externCounter );
	//foo();
	
	printf("\njdfnvkjn\n");
	exit(0);
}		
