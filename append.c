#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node{
 int data;
 struct node* next;
};


struct node* build1()
{
  struct node* first = malloc(sizeof(struct node));
  struct node* second = malloc(sizeof(struct node));
  struct node* third = malloc(sizeof(struct node));


  *first = (struct node){12,second};
  *second = (struct node){22,third};
  *third = (struct node){3, NULL};
 
   return first;
}

struct node* build2()
{
  struct node* first = malloc(sizeof(struct node));
  struct node* second = malloc(sizeof(struct node));
  struct node* third = malloc(sizeof(struct node));


  *first = (struct node){3,second};
  *second = (struct node){22,third};
  *third = (struct node){1, NULL};
 
   return first;
}

void append(struct node** one, struct node** two)
{

if(*one == NULL)

    *one = *two;
else {
    struct node* temp = *one;
    while(temp->next != NULL) {
      temp = temp->next;
    }
 temp->next = *two;
}
}

void print(struct node* head)
{
 while(head != NULL)
 {
   printf("%d->",head->data);
   
    head = head->next;
 }
}


void main()
{
 struct node* one = build1();
 struct node* two = build2();

 append(&one, &two);
  
 print(one);
}






