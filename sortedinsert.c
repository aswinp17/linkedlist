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


  *first = (struct node){3,second};
  *second = (struct node){22,third};
  *third = (struct node){1, NULL};
 
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

void sortedinsert(struct node** headref, struct node* newnode)
{
 if(*headref == NULL || (*headref)->data >= newnode->data){
    newnode->next = *headref;
    *headref = newnode;
    }
  else {
   struct node* current = *headref;
   while (current->next !=NULL && current->next->data < newnode->data)  {
        current = current->next;
  }
  
  newnode->next = current->next;
  current->next = newnode;
 }
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

 
 
 struct node* newnode = malloc(sizeof(struct node));
 *newnode = (struct node){3,NULL};
  
  sortedinsert(&head,newnode);
  int i = getnth(head,3);
  printf("\n data is  %d",i);


}

