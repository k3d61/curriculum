#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
   return current;
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


void main() {

      insertFirst("asdca","dcdcasxax");

   insertFirst("aa","asxax");
   printList();
   struct node *foundLink = find("aa");
   
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%s,%s) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
   delete("aa");
   printList();
   
/*
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
   
   //print list
/*
   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
   
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
   
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
  */ 
}