//insertions
#include"stdio.h"
#include"stdlib.h"
struct node{
    int data;
    struct node* next;
};
struct node *tail=NULL;
 struct node *newnode(){
     struct node *ptr;
     ptr = malloc(sizeof(struct node));
     ptr->next=NULL;
     
     return ptr;
 }
 
 void print(struct node *start){
     start=start->next;
     while(start->next != NULL){
         printf("%d ",start->data);
         start=start->next;
     }
 }
 
 void insert_at_beginning(struct node *start){
     printf("\nEnter the number that is to be inserted at beginning: ");
     int value;
     scanf("%d",&value);
     struct node *fresh=newnode();
     fresh->data=value;
     fresh->next=start->next;
     start->next=fresh;
 }
 
 void insert_at_ending(struct node *start){
     printf("\nEnter the number that is to be inserted at ending: ");
     int value;
    //  scanf("%d",&value);
    //  struct node *fresh=newnode();
    //  fresh->data=value;
    //  start->next=fresh;
 }
 
 int main(){
     struct node *start=newnode();
     start->data=10;
     struct node *present=newnode();
     struct node *future = newnode();
     start->next=present;
     printf("Enter the size of linked list: ");
     int size;
     scanf("%d",&size);
     //printf("Enter the values: ");
     for(int i=0;i<size;i++){
         int value;
         //scanf("%d",&value);
         present->data=i+10;
         future=newnode();
         present->next=future;
         present=future;
     }
     print(start);
     printf("\nOver");
     insert_at_beginning(start);
     print(start);
     //insert_at_ending(present);
     struct node *tail=newnode();
     future->next=tail;
     tail->data=100;
     future=tail;
     //tail=newnode();
     print(start);
 }
