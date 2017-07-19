#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
 int data;
 struct node* next;
};


struct node* build()
{
  struct node* first = malloc(sizeof(struct node));
  struct node* second = malloc(sizeof(struct node));
  struct node* third = malloc(sizeof(struct node));


  *first = (struct node){3,second};
  *second = (struct node){22,third};
  *third = (struct node){1, NULL};
 
   return first;
}

void push(struct node** headref, int data)
{
  struct node* newnode = malloc(sizeof(struct node));

  newnode->data = data;
  newnode->next = *headref;
  *headref = newnode;
}


void sortedinsert(struct node** headref, struct node* newnode)
{
 if(*headref == NULL || (*headref)->data >= newnode->data){
    newnode->next = *headref;
    *headref = newnode;
    }
  else {
   struct node* current = *headref;
   while (current->next !=NULL && current->next->data < newnode->data)  {
        current = current->next;
  }
  
  newnode->next = current->next;
  current->next = newnode;
 }
} 

void print(struct node* head)
{
  while(head != NULL) {
   printf("\n %d",head->data);
   head = head->next;
   }
}   
 
 
 
void insertsort(struct node** headRef) {

struct node* temp = NULL;
struct node* current = *headRef;
struct node* next;
while (current!=NULL) {
next = current->next;
sortedinsert(&temp, current);
current = next;
}
*headRef = temp;

}

void main()
{

 struct node* head;
  
 head = build();
 print(head);

 insertsort(&head);
 print(head);
  
   
} 

  

 


