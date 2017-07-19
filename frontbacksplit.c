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

void print(struct node* head)
{
  while(head != NULL) {
   printf("\n %d",head->data);
   head = head->next;
   }
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

void frontbacksplit(struct node* source, struct node** frontref, struct node** backref) 
{
   int l = length(source);
   struct node* temp = source; 
   if (l < 2) {
    *frontref = source;
    *backref = NULL;
   }
   else
    {
      for(int i = 0; i < (l-1)/2; i++)
         temp = temp->next;
        
    }
     *frontref = source;
     *backref = temp->next;
     temp->next =NULL;
}







void main()
{
 struct node* list = build();
 
 struct node* front = NULL;
 struct node* back = NULL;

 frontbacksplit(list,&front,&back);

 printf("\n front list");
 print(front);
 printf("\n back list");
 print(back);
}
