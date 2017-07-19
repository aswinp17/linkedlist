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
  struct node* fourth = malloc(sizeof(struct node));

  *first = (struct node){32,second};
  *second = (struct node){1,third};
  *third = (struct node){56, fourth};
  *fourth = (struct node){3,NULL};
   return first;
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






void movenode(struct node** destref, struct node** sourceref)
{
  assert(*sourceref != NULL);
  
  
  
  push(&(*destref), (*sourceref)->data);
  
  *sourceref = (*sourceref)->next;
}

struct node* sortedmerge(struct node* a, struct node* b)
{

  struct node dummy;
  
  struct node *tail = &dummy;
  dummy.next = NULL;

  while(1) {
   if (a == NULL) {
      tail->next = b;
      break;
      }
  else if (b == NULL) {
      tail->next = a;
      break;
     }
  else {
  if (a->data <= b->data) {
      movenode(&(tail->next),&a);
     }
  else  
    movenode(&(tail->next),&b);
      }
      tail = tail->next;
   }
   
   return(dummy.next);
}

void mergesort(struct node** headref)
{
  struct node* head = *headref;
  struct node* a;
  struct node* b;
   
 if((head == NULL) || (head->next ==NULL)) {
     return;
   }
  
 frontbacksplit(head,&a,&b);
 mergesort(&a);
 mergesort(&b);
 
 *headref = sortedmerge(a,b);
}


void main()
{
 struct node* list = build();

 mergesort(&list);
 
print(list);

}

















