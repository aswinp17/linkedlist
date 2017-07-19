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

void movenode(struct node** destref, struct node** sourceref)
{
  assert(*sourceref != NULL);
  
  
  
  push(&(*destref), (*sourceref)->data);
  
  *sourceref = (*sourceref)->next;
}

void reverse(struct node** headref) {
 struct node* rev = NULL;
 
 struct node* temp = *headref;

 while(temp != NULL) {
    movenode(&rev,&temp);
   }
   *headref = rev;
}


int main()
{
  struct node* list = build();
  
  reverse(&list);
  
  print(list);
}




