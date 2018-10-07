// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <assert.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080 
pthread_mutex_t lock; 

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct node {
   char *data;
   char *key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
   
   //start from the beginning
   while(ptr != NULL) {
      printf("(%s,%s) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
   
   printf(" ]");
}

//insert link at the first location
void insertFirst(char *key, char *data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   
   link->key = key;
   link->data = data;
   
   //point it to old first node
   link->next = head;
   
   //point first to new first node
   head = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
   
   //mark next to first link as first 
   head = head->next;
   
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
   
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
   
   return length;
}

//find a link with given key
struct node* find(char *key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while( strcmp(current->key , key)) {
   
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
   
   //if data found, return the current Link
   return current->data;
}

//delete a link with given key
struct node* delete(char *key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
   
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(strcmp(current->key , key)) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
   
   return current;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



char* do_create(char* name, char* key, char* value) {

    // find if its aleady exists
    struct node *foundLink = find(key);
    if(foundLink != NULL) {
        printf("Aalready in the list: Not Inserting");

    } else {
        printf("OK");
        insertFirst(key,value);
        printList();
        printf("\n");
    }

    char *ret = calloc(sizeof(char), 100);
    strcpy(ret,"Key Inserted\0");
    return ret;
}

char* do_delete(char* name, char* key) {

    char *ret = calloc(sizeof(char), 100);
    // find if its aleady exists
    struct node *foundLink = find(key);
    if(foundLink != NULL) {
        printf("Key found in the list: Deleting");
        delete(key);
        printList();
    } else {
        printf("[Error] Element not found. Can not delete");
        
        strcpy(ret,"Key Not dound: delete failed\0");
        return ret;
    }
    strcpy(ret,"OK\0");
    return ret;
}

char* do_update(char* name, char* key, char* value) {

    char *ret = calloc(sizeof(char), 100);
    // find if its aleady exists
    struct node *foundLink = find(key);
    if(foundLink != NULL) {
        printf("Key found in the list: updating");
        delete(key);
        insertFirst(key,value);
        printList();

    } else {
        printf("[Error] Element not found. Can not delete");

        strcpy(ret,"Key Not found: update failed\0");
        return ret;

    }
    strcpy(ret,"OK\0");
    return ret;
}
char* do_read(char* name, char* key) {

    char *ret;
    ret = (char *)find(key); 
    if (ret == NULL){
        ret = calloc(sizeof(char), 100);
        strcpy(ret,"Key Not Found\0");

    }

    printf("In do_read = %s\n", ret);
    return ret;
}



void getAndParseData(void *socket_desc){
    
    int new_socket = *(int*)socket_desc;
    int buffer[4096] = {0}; 
    int valread = 0;

    // printf("Raw : %s\n",buffer ); 

    char* command = calloc(sizeof(char), 100);
    char* size = calloc(sizeof(char), 100);
    while(1){
        // Read new command from command line
        for (int i = 0 ; i < 4096 ;i++)
            buffer[i] = 0;
        valread = read( new_socket , buffer, 5000); 
        // printf("\n--> %s\n", buffer);
        if(strcmp("disconnect", buffer) == 0)
          pthread_exit(NULL);

        char* key = calloc(sizeof(char), 1000);
        char* value = calloc(sizeof(char), 4096);
         
        // check whether these values are NULL or not
        assert(command != NULL);
        assert(size != NULL);
        assert(key != NULL);
        assert(value != NULL);

        // %[^<] uses a regex to match any characters that are not '<'.
        sscanf(buffer, "<cmd>%[^<]</cmd><valsize>%[^<]</valsize><key>%[^<]</key><value>%[^<]</value>",
               command,size, key, value);

        printf("Processed : \n" );
            printf("  command=\"%s\"\n", command);
        if(strcmp(size, "NONE"))     
            printf("  size=\"%s\"\n", size);
        if(strcmp(key, "NONE"))    
            printf("  key=\"%s\"\n", key);
        if(strcmp(value, "NONE")) 
            printf("  value=\"%s\"\n", value);
        printf("\n");
        // now process commands
         char *ret ="done";
        
        pthread_mutex_lock(&lock); 
        
        if( !strcmp( command, "create" )) {
            ret = do_create( command, key, value);
        } else if( !strcmp( command, "delete")) {
            ret = do_delete(command, key);
        } else if( !strcmp( command, "read")) {
            ret = do_read(command, key);
        } else if( !strcmp( command, "update")) {
            ret = do_update( command, key, value);
        }
        pthread_mutex_unlock(&lock); 
        // send temporary data
        send(new_socket , ret , strlen(ret) , 0 ); 
        //printf("Hello message sent\n");
        sleep(1);
    }    
}


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvv Main vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread, *temp_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    
    // VVVVVVVVVVVVVV Mutex code
    // Initialize mutex lock 
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
    // ^^^^^^^^^^^^^^
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    if (argv[2] == NULL){
      printf("%s\n", "Enter port number");
      return 0;
    }
    int port = atoi(argv[2]);
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( port ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    

    int i = 0;
    while (1 ) {

        new_socket = accept(server_fd, (struct sockaddr *)&address,  (socklen_t*)&addrlen);
        temp_socket = malloc(1);
        *temp_socket = new_socket;

        pthread_t client_thread;

        if( pthread_create( &client_thread , NULL ,  getAndParseData , (void*) temp_socket) < 0)
        {
            perror("could not create thread");
            return 1;
        }
        pthread_detach(client_thread);
        printf("%s\n", "Connected to new socket");
        i++;
    }
     
    // getAndParseData(new_socket);
    // for (int i = 0; i < 3; i++) {
    //   printf("%s\n", "waiting");
    //   pthread_join(client_thread[i], NULL);  
    // }
    printf("%s\n", "All client_thread done");
    return 0; 
} 

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Main ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

