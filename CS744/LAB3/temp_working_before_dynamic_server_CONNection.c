before moving connection code inside if 



// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <assert.h>
#define PORT 8080 
#define BUFFERSIZE 1024

// taken from first lab
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64


char *protocolString = "<cmd>%s</cmd><valsize>%d</valsize><key>%s</key><value>%s</value>";

char* createKeyPacket(char const *argv[]){

    printf("%s\n", __func__);
    // take all the arg in local variables 
    char *key_buffer = argv[1];
    int valSize = atoi(argv[2]);
    char *value_buffer = argv[3];

    // check if they are all not NULL
    assert(key_buffer != NULL);
    assert(value_buffer != NULL);
    strtok(key_buffer, "\n");

    printf("%s : %s\n", key_buffer, value_buffer);

    int cmdsize = strlen(key_buffer) + strlen(value_buffer) + strlen(protocolString) + 1;
    // we will be sendint this packet at the end
    char* packet = calloc(cmdsize, sizeof(char));
    assert(packet != NULL);
    
    sprintf(packet, protocolString, argv[0], valSize, key_buffer, value_buffer);

    printf("packet is %s\n", packet);

    return packet;
}



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
    tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
    strcpy(tokens[tokenNo++], token);
    tokens[tokenNo] = NULL ;
    free(token);
    return tokens;
}


   
int main(int argc, char const *argv[]) 
{ 
    

    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "."; 
    char buffer[BUFFERSIZE] = {0}; 
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    // Till here connection is established

    char  line[MAX_INPUT_SIZE]; 
    char  **tokens;
    int i;


    while (1) {           
        //usleep(100000);
        printf("\nHello>");    
        bzero(line, MAX_INPUT_SIZE);
        gets(line);   
        if (!strcmp(line,"\0")){
                
            continue;    
        }
        tokens = tokenize(line);
        
   
        if ( strcmp("create", tokens[0]) == 0 ) {
            hello = createKeyPacket( tokens );
        }
        if ( strcmp("read", tokens[0]) == 0 ) {
            hello = createKeyPacket( tokens );
        }
        if ( strcmp("update", tokens[0]) == 0 ) {
            hello = createKeyPacket( tokens );
        }
        if ( strcmp("delete", tokens[0]) == 0 ) {
            hello = createKeyPacket( tokens );
        }
        if ( strcmp("quit", tokens[0]) == 0 ) {
            printf("%s\n", "Exiting");
            close(sock);
            return 0;
        }
        send(sock , hello , strlen(hello) , 0 ); 
        printf("    message sent\n"); 

        valread = read( sock , buffer, BUFFERSIZE); 
        printf("%s\n",buffer ); 
    }
    return 0; 
} 
