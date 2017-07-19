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

void insertnth(struct node** headref, int i,int data)
{ struct node* newnode = malloc(sizeof(struct node));
  
  int l = length(*headref);

  struct node* head = *headref;
   

  assert(i >= 0 && i<= (l-1));
  for(int k = 0 ; k < i-1; k++)
  {
   
   head = head->next;
  
 
}
 push((&head->next),data);  
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
 insertnth(&head,2,50);

 int i = getnth(head,2);
  printf("\n data is  %d",i);
}

