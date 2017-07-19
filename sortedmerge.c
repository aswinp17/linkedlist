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

  *first = (struct node){1,second};
  *second = (struct node){2,third};
  *third = (struct node){3, fourth};
  *fourth = (struct node){5,NULL};
   return first;
}

struct node* build2()
{
  struct node* first = malloc(sizeof(struct node));
  struct node* second = malloc(sizeof(struct node));
  struct node* third = malloc(sizeof(struct node));
  struct node* fourth = malloc(sizeof(struct node));

  *first = (struct node){6,second};
  *second = (struct node){7,third};
  *third = (struct node){21, fourth};
  *fourth = (struct node){123,NULL};
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



void main()
{
 struct node* a = build();
 struct node* b =build2();

 struct node* sortlist = sortedmerge(a,b);
 print(sortlist);

} 
     
   






















