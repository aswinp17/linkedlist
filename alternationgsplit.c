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
  *third = (struct node){1, fourth};
  *fourth = (struct node){2,NULL};
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


void alternatingsplit(struct node* source,struct node** one, struct node** two)
{

struct node* a = NULL;
struct node* b = NULL;

struct node* temp = source;

while(temp != NULL) {
 movenode(&a,&temp);
 if(temp != NULL)
 movenode(&b,&temp);
}

*one = a;
*two = b;
}



void main()
{
  struct node* list = build();
  struct node* one = NULL;
  struct node* two = NULL;

  alternatingsplit(list,&one,&two);


  printf("\n one is:");
  print(one);
  printf("\n two is:");
  print(two);
}

