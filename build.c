#include<stdio.h>
#include<stdlib.h>
struct node {
 int data;
 struct node* next;
};

struct node* build()
{
 struct node* first = malloc(sizeof(struct node));
 struct node* second = malloc(sizeof(struct node));
 struct node* third = malloc(sizeof(struct node));

 *first =(struct node){1, second};
 *second =(struct node) {2, third};
 *third =(struct node) {3, NULL};

 return first;
}

int length(struct node* head)
{
  int l = 1;
  while(head->next != NULL)
  {
    l++;
    head = head->next;
  }

   return l;
}


void push(struct node** headref, int data)
{
  struct node* newnode = malloc(sizeof(struct node));
  
  newnode->data = data;
  newnode->next = *headref;
  *headref = newnode;
}
void main()
{
 int l;
 struct node* head;
 head = build();
 
 push(&head, 21);
 push(&head, 37);
 
 l=length(head);
 printf("\n %d",l);


}






