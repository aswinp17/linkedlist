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

int length(struct node* head)
{
  int c = 0;
  while(head != NULL)
   {
      
       ++c;
       head = head->next;
   }
   
   return c;
}

int pop(struct node** headref)
{
   struct node* head = *headref;
   int data;
   
   assert( head != NULL);
     
   data = head->data;
   *headref = head->next;

   free(head);

   return(data);
}







void main()
{

 struct node* head;
  
 head = build();

 push(&head,11);
 push(&head,21);
 push(&head,31);
 int n = pop(&head);
  printf("\n data is  %d",n);
  n = pop(&head);
  printf("\n data is %d",n);
  n = pop(&head);
  printf("\n data is %d",n);

}

