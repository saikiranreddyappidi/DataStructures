#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue *next;
};
struct Queue *newnode(){
    struct Queue *ptr;
    ptr=malloc(sizeof(struct Queue));
    ptr->next=NULL;
    return ptr;
}
struct Queue *Enqueue(struct Queue *rear){
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    rear->data=value;
    rear->next=newnode();
    return rear->next;
}
struct Queue *Dequeue(struct Queue *front){
    if(front->data!=-1){
        printf("Queue is empty.");
        return front;
    }
    else{
        return front->next;
    }
}
int display(struct Queue *front){
    if(front->data!=-1){
        printf("Queue is empty.");
    }
    else{
        front=front->next;
        while(front->next !=NULL){
            printf("%d ",front->data);
            front=front->next;
        }
    }
    return 0;
}
int main(){
    int choice=1;
    struct Queue *front=newnode();
    front->data=-1;
    struct Queue *rear=newnode();
    front->next=rear;
    rear->data=-1;
    while(choice!=0){
        printf("\n1-Enqueue\t2-Dequeue\t3-Display\t0-Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            rear=Enqueue(rear);
        else if(choice==2)
            front=Dequeue(front);
        else if(choice==3)
            display(front);
        else if(choice==0)
            return 0;
        else
            printf("Enter a vaid choice.");                
    }
}
