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
	if(front->data==-2){
        front=front->next;
    }
    if(front->data==-1){
        printf("Queue is empty.");
        return front;
    }
    else{
    	printf("%d is deleted from the Queue.",front->data);
    	//printf("---%d---",front->next->data);
//    	front=front->next;
        return front;
    }
}
int display(struct Queue *front){
//    if(front->data==-2){
//        front=front->next;
//    }
    if(front->data==-1){
        printf("Queue is empty.");
    }
    else{
        front=front->next;
        printf("\nThe following elements are in the Queue: ");
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
    while(choice!=0){
        printf("\n1-Enqueue\t2-Dequeue\t3-Display\t0-Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
        	if(front->data==-1){
        		front->data=-2;
			}
			rear=Enqueue(rear);
		}
        else if(choice==2){
        	front=Dequeue(front);
        	//printf("===%d===",front->data);
		}
        else if(choice==3)
            display(front);
        else if(choice==0)
            return 0;
        else
            printf("Enter a vaid choice.");                
    }
}
