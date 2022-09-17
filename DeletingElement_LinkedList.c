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

int delete(struct node *past,int value){
    struct node *future=past;
    int t=0;
    while(future->next != NULL){
        future=future->next;
        if(future->data==value){
            past->next=future->next;
            t=1;
            break;
        }
        past=past->next;
    }
    if(t==0){
        printf("Element not found.");
    }
    return 0;
}

void main(){
    struct node *start=newnode();
    struct node *ptr1=newnode();
    start->next=ptr1;
    int i,n=5,t;
    printf("Enter the size of linkedlist: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&t);
        struct node *present=newnode();
        ptr1->next=present;
        ptr1->data=t;
        ptr1=present;
    }
    printf("\nEntered numbers : ");
    print(start);
    printf("\nEnter a number that is to be deleted in the above list: ");
    scanf("%d",&t);
    delete(start,t);
    printf("\nFinal list: ");		
    print(start);
    
}
