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


struct node* shufflemerge(struct node* a,struct node* b)
{

struct node * list = NULL;

while( a != NULL || b != NULL)
{
   if(a != NULL)
   movenode(&list,&a);
   if(b != NULL)
   movenode(&list,&b);
}

return list;
}



void main()
{

struct node* a = build();
struct node* b = build();

struct node* merge = shufflemerge(a,b);

print(merge);
}
