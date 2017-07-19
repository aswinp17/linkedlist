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

int getnth(struct node* head, int i)
{ struct node* temp = malloc(sizeof(struct node));
  temp = head; 
  int l = length(temp);
  assert(i >= 0 && i<= (l-1));
  for(int k = 0 ; k < (l-1); k++)
  {
   if(k == i)
   {
     return head->data;
     break;
   }
   head = head->next;
  }
  free(temp);
}

   








void main()
{

 struct node* head;
  
 head = build();

 push(&head,11);
 push(&head,21);
 push(&head,31);
 int n = getnth(head,1);
  printf("\n data is  %d",n);
}

