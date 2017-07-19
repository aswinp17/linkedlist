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


  *first = (struct node){1,second};
  *second = (struct node){2,third};
  *third = (struct node){3, NULL};
 
   return first;
}

void push(struct node** headref, int data)
{
  struct node* newnode = malloc(sizeof(struct node));

  newnode->data = data;
  newnode->next = *headref;
  *headref = newnode;
}

void deletelist(struct node** headref)
{
   
   struct node* head = *headref;
   struct node*temp;

  while(head != NULL)
   {
      
       
       temp = head->next;
       free(head);
       head = temp;
   }
   
  *headref = NULL;
}

   








void main()
{

 struct node* head;
  
 head = build();

 push(&head,11);
 push(&head,21);
 push(&head,31);
 deletelist(&head);
}

