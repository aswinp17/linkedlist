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

  *first = (struct node){3,second};
  *second = (struct node){5,third};
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


struct node* sortedintersect( struct node* a, struct node* b)
{

 struct node temp;
 struct node* tail = &temp;
 temp.next = NULL;

 while(a != NULL && b != NULL) {
    if (a->data == b->data){
       push(&(tail->next),a->data);
       tail = tail->next;
       a = a->next;
       b = b->next;
     }
  
     else if( a->data <  b->data)
        a = a->next;
     else
         b = b->next;
   }


  return(temp.next);
}

void print(struct node* head)
{
  while(head != NULL) {
   printf("\n %d",head->data);
   head = head->next;
   }
}   

void main()
{
 
 struct node* list = build();
 struct node* list2 = build2();

  struct node* intersect = sortedintersect(list,list2);

 print(intersect);
}





