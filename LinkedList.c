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

int insert(struct node *start,int value){
    struct node *future=start;
    while(future != NULL){
        future=future->next;
        // if(start->data >value){
        //     printf("---%d---",value);
        //     struct node *new=newnode();
        //     new->next=start->next;
        //     new->data=value;
        //     start->next=new;
        //     break;
        // }
        if(start->data <=value && future->data > value){
            struct node *new=newnode();
            new->next=start->next;
            new->data=value;
            start->next=new;
            break;
        }
        else if(future->next == NULL){
            struct node *new=newnode();
            new->data=value;
            future->next=new;
            future->data=value;
            break;
        }
        start=start->next;
    }
}

void main(){
    struct node *start=newnode();
    struct node *present=newnode();
    start->next=present;
    int i,n,value;
    printf("Enter the size of linked list to be created initially: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        present->data=value;
        present->next=newnode();
        present=present->next;
    }
    printf("\nEntered numbers : ");
    print(start);
    printf("\nEnter the no.of numbers to be inserted in above the above linked list: ");
    scanf("%d",&n);
    printf("\nEnter %d numbers that are to be inserted in the linked list: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        insert(start,value);
    }
    printf("\nFinal list: ");		
    print(start);
    
}
