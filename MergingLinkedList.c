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
    int i,n,value,no_of_LL;
    printf("Enter the no.of linked lists to be created: ");
    scanf("%d",&no_of_LL);
    printf("Enter the size of first linked list to be created: ");
    scanf("%d",&n);
    printf("Enter %d numbers of 1 linked list: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        present->data=value;
        present->next=newnode();
        present=present->next;
    }
    // printf("\nEntered numbers in first linked list: ");
    // print(start);
    int count=1;
    while(count<no_of_LL){
        count++;
        printf("\nEnter the size of %d linked list: ",count);
        scanf("%d",&n);
        printf("\nEnter %d numbers of %d linked list: ",n,count);
        for(i=0;i<n;i++){
            scanf("%d",&value);
            insert(start,value);
        }
        print(start);
    }
    printf("\nFinal linked list: ");		
    print(start);
    
}
