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
  *third = (struct node){2, fourth};
  *fourth = (struct node){3, NULL};
   return first;
}

void print(struct node* head)
{
  while(head != NULL) {
   printf("\n %d",head->data);
   head = head->next;
   }
}   

void removeduplicate(struct node* source)
{
  assert(source != NULL);
  
  while(source->next != NULL)
    {
       if(source->data == source->next->data)
         {
           struct node* temp = source->next->next;
           free(source->next);
           source->next = temp;
          }
        else
            source = source->next;
     }
}


void main()
{

 struct node* list = build();  
 printf("\n the list is :");
 print(list);
 removeduplicate(list);
 printf("\nlist after function");
 print(list);
}         
