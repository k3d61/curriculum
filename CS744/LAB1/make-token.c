#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h> // for exec system call
#include  <sys/types.h> // for wait system call
#include <string.h> 
#include <unistd.h> //  for usleep

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char historyFile[] = "History\0";
int waitingPID[1000];
int numberOfProcessesWaiting = 0;

// Definitions to move in .h file afterwards
int convertToSubCommands(char **token);
int executeCommand(char **command, char flag);
int executeCDCommand(char **tokens);
int addCommandToHistory(char *command);
int releaseWaitingProcess();

char **tokenize(char *line)
{
	char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	int i, tokenIndex = 0, tokenNo = 0;
	
	for(i =0; i < strlen(line); i++){

		char readChar = line[i];

		if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
			token[tokenIndex] = '\0';
			if (tokenIndex != 0){
				tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
				strcpy(tokens[tokenNo++], token);
				tokenIndex = 0; 
			}
		} else {
			token[tokenIndex++] = readChar;
		}
	}

	free(token);
	tokens[tokenNo] = NULL ;
	return tokens;
}

int convertToSubCommands(char **token){
	
}


void printWaitingQ(){
	int iterateThroughWaitingProc = 0;
	while( iterateThroughWaitingProc < numberOfProcessesWaiting 
		&& waitingPID[ iterateThroughWaitingProc ] != -1 ){
		printf("%d\n",  waitingPID[ iterateThroughWaitingProc ]);
	iterateThroughWaitingProc++;
}

}
/*
	- flag is to enforce whether execution is foreground or 
	- bckground
*/
int executeCommand(char **command, char flag){
	int ret = 0;
	pid_t pid = fork();
	if (pid == 0){  // child
    //printf("\t\t\tForked\n");
		ret = execvp(command[0], command);  
    //printf("\nexitcode=%d\n", ret);
		//exit(ret);
	}
	if (pid > 0){ // parent
		if (flag == 'F'){
			wait(&pid);
		}
		if (flag == 'B'){
			waitingPID[numberOfProcessesWaiting++] = pid;
			printWaitingQ();
		}

    //printf("\t\t\tJoined %d -> %d\n", ret_f, ret);

	}
}

int addCommandToHistory(char *command){
	//char historyFile[10] = “History\0”;
	FILE *fp= fopen(historyFile, "a+");

	if (fp == NULL){
		printf("%s\n", "ERROR: Conn't Open the file");
		return 1;
	}

	fprintf( fp, "%s\n", command);
	fclose(fp);
}

int printHistory(){
	FILE *fp= fopen("History", "r");
	char buf[1000];

	if (!fp) {
		printf("%s\n", "ERROR: Conn't Open the file");
		return 1;
	}

	while (fgets(buf,1000, fp)!=NULL)
		printf("%s",buf);

	fclose(fp);
}


// write code for stderr stdout file descriptor pointer change





int executeCDCommand(char **tokens){
	int ret = chdir(tokens[1]);  
}

int releaseWaitingProcess(){
	int iterateThroughWaitingProc = 0;

	while( iterateThroughWaitingProc < numberOfProcessesWaiting 
		&& waitingPID[ iterateThroughWaitingProc ] != -1 ){
		int statusOfBProc = -1;
	int pid = waitingPID[ iterateThroughWaitingProc ];

	waitpid(pid, &statusOfBProc, WNOHANG);
	//printf("state = %d 0f %d\n", statusOfBProc, pid);

	if (WIFEXITED(statusOfBProc)  ){
		printf("Child exited with code %d -> %d\n", pid, WEXITSTATUS(statusOfBProc));
		wait(&pid);
		waitingPID[ iterateThroughWaitingProc ] = -1;
		//exit(0);
	}

	else if (WIFSIGNALED(statusOfBProc) ){
		printf("Child terminated abnormally, signal %d -> %d\n", pid, WTERMSIG(statusOfBProc));
		wait(&pid);
		waitingPID[ iterateThroughWaitingProc ] = -1;
		//exit(0);
	}
	iterateThroughWaitingProc++;

	}
}



void  main(void)
{
	char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;
	char backGroundflag;

	while (1) {           

		releaseWaitingProcess();
		//usleep(100000);
		printf("\nHello>");    
		bzero(line, MAX_INPUT_SIZE);
		gets(line);     
		if (!strcmp(line,"\0")){
			continue;    
		}
       //printf("Got command %s\n", line);

       line[strlen(line)] = '\n'; //terminate with new line

       // Detect & at the end of file to make process background
  		//printf("Before: %s\n", line);
       if ( line[ strlen(line)-2 ] == '&' ){
       	backGroundflag = 'B';
       	line[strlen(line) - 2 ] = '\n';
      	//printf("%s\n", "background process");
       }
      // printf("After: %s\n", line);


       tokens = tokenize(line);

   		 
   		for(i=0;tokens[i]!=NULL;i++){
          printf("found token %s\n", tokens[i]);
      }
			

       //do whatever you want with the commands, here we just print them
       convertToSubCommands(tokens);
       addCommandToHistory(tokens[0]);



       if ( strcmp(tokens[0],"cd") == 0 ){
       	executeCDCommand(tokens);	
       }
       else if ( strcmp(tokens[0],"history") == 0 ){
       	printHistory();	
       }
       else
       	executeCommand(tokens, backGroundflag);



       // Freeing the allocated memory	
       for(i=0;tokens[i]!=NULL;i++){
       	free(tokens[i]);
       }
       free(tokens);
     }
     

   }


