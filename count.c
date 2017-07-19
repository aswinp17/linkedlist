#include<stdio.h>
#include<stdlib.h>

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

int count(struct node* head,int n)
{
  int c = 0;
  while(head != NULL)
   {
      if(head->data == n)
       ++c;
       head = head->next;
   }
   
   return c;
}


void main()
{

 struct node* head;
  
 head = build();

 push(&head,21);
 push(&head,21);
 push(&head,21);

 int n = count(head,21);
 printf("\n the count is %d",n);
}

