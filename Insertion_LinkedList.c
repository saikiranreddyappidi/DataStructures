#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode(){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr->next=NULL;
    return ptr;
};

void print(struct node *start){
    start=start->next;
    while(start->next !=NULL){
        printf("%d ",start->data);
        start=start->next;
    }
}

void main(){
    struct node *start=newnode();
    struct node *ptr1=newnode();
    start->next=ptr1;
    int i,n,t;
    printf("Enter the size of Linked List: ");
    scanf("%d",&n);
    printf("Enter the numbers: ");
    for(i=0;i<n;i++){
        scanf("%d",&t);
        struct node *present=newnode();
        ptr1->next=present;
        ptr1->data=t;
        ptr1=present;
    }
    printf("\nEntered numbers : ");
    print(start);
    printf("\nEnter a number that is to be inserted at the starting of the list: ");
    scanf("%d",&t);
    //insert(start,t);
    struct node *new=newnode();
    new->next=start->next;
    new->data=t;
    start->next=new;
    printf("\nFinal list: ");		
    print(start);
    
}
