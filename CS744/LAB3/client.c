
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <assert.h>
#define PORT 8080 
#define BUFFERSIZE 4100

// taken from first lab
#define MAX_INPUT_SIZE 5000
#define MAX_TOKEN_SIZE 5000
#define MAX_NUM_TOKENS 64


char *protocolString = "<cmd>%s</cmd><valsize>%d</valsize><key>%s</key><value>%s</value>";

char* createKeyPacket(char const *argv[]){

    // printf("%s\n", __func__);
    // take all the arg in local variables 
    char *key_buffer = argv[1];
    
    int valSize = 0;
    if( argv[2] != NULL )
        valSize = atoi(argv[2]);
    
    char *value_buffer = "NA";
    if( argv[3] != NULL )
        value_buffer = argv[3];

    // check if they are all not NULL
    assert(key_buffer != NULL);
    assert(value_buffer != NULL);
    strtok(key_buffer, "\n");

    // printf("%s : %s\n", key_buffer, value_buffer);

    int cmdsize = strlen(key_buffer) + strlen(value_buffer) + strlen(protocolString) + 1;
    // we will be sendint this packet at the end
    char* packet = calloc(cmdsize, sizeof(char));
    assert(packet != NULL);
    
    sprintf(packet, protocolString, argv[0], valSize, key_buffer, value_buffer);

    // printf("packet is %s\n", packet);

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
    token[tokenIndex++] = '\0';
    tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
    strcpy(tokens[tokenNo++], token);
    tokens[tokenNo] = NULL ;
    free(token);
    return tokens;
}


   
int main(int argc, char const *argv[]) 
{ 
    
    char *serverIP = "127.0.0.1";
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "."; 
    char ret[BUFFERSIZE] = {0}; 
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    // Till here connection is established

    char  line[MAX_INPUT_SIZE]; 
    char  **tokens;
    int i;
    int connected = 0;

    FILE *fp; 

    int mode = 0; // 1: interactive. 2: batch
    if( strcmp("interactive", argv[1]) == 0 )
        mode = 1;
    if( strcmp("batch", argv[1]) == 0 ){
        mode = 2;
        fp = fopen(argv[2], "r");
        if (fp == NULL)
            exit(EXIT_FAILURE);
    }
    char *rline = NULL;
    size_t len = 0;
    ssize_t read1;
         

    while (1) {           
        //usleep(100000);
        bzero(line, MAX_INPUT_SIZE);
        if( mode == 1){
            printf("\nHello>");    
            gets(line);
        }
        if( mode == 2){
            if ((read1 = getline(&rline, &len, fp)) != -1) {
                // printf("Retrieved line of length %zu :\n", read1);
                // printf("%s", rline);
                strcpy(line, rline);
            }
            if(read1 <= -1)
                return 0;
        }
        // printf("line = %s\n", line);
           
        if (!strcmp(line,"\0")){
                
            continue;    
        }
        tokens = tokenize(line);
        
        // for( i = 0; tokens[i] != NULL; i++ ){
        //   printf("found token -> %s\n", tokens[i]);
        // }   

        if ( strcmp("quit", tokens[0]) == 0 ) {
            printf("%s\n", "Exiting");
            close(sock);
            return 0;
        }
        if ( strcmp("connect", tokens[0]) == 0 ) {
            // Convert IPv4 and IPv6 addresses from text to binary form 
            // printf("%s\n", "in connect");
            serverIP = tokens[1];
            int port = atoi(tokens[2]);

            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
                printf("\n Socket creation error \n"); 
                 return -1; 
            } 

            memset(&serv_addr, '0', sizeof(serv_addr)); 

            serv_addr.sin_port = htons(port); 
            serv_addr.sin_family = AF_INET; 
        
       
            if(inet_pton(AF_INET, serverIP, &serv_addr.sin_addr)<=0)  
            { 
                printf("\nInvalid address/ Address not supported \n"); 
                continue;
            } 
           
            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
            { 
                printf("\nConnection Failed \n"); 
                continue; 
            }  
            connected = 1; 
            printf("%s\n", "OK");
            continue;   
        }
        if ( strcmp("disconnect", tokens[0]) == 0 ) {
            send(sock , "disconnect" , strlen("disconnect") , 0 );
            close(sock);
            printf("%s\n", "OK");
            connected = 0;
            continue;
        }
        if ( connected == 0) {
            printf("%s\n", "Connect to server first.");
            continue;
        }

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
        send(sock , hello , strlen(hello) , 0 ); 
//        printf("[C] message sent\n"); 

        // Buffer reset
        for ( int i = 0 ; i < BUFFERSIZE - 1 ; i++ )
            ret[i]='\0';

        valread = read( sock , ret, BUFFERSIZE); 
        printf("%s\n",ret ); 
    }
    return 0; 
} 
