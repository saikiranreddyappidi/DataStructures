#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
int push(struct Stack* stack)

{
    if (isFull(stack)){
    	printf("Stack is full.\nPop the top value to store another element.");
        return 0;
    }
    int item;
    printf("Enter an element: ");
    scanf("%d",&item);
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    printf("poped element: %d\n",stack->array[stack->top--]);
}

int display(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    else{
    	int i,max=stack->top;
    	for(i=0;i<=max;i++)
    printf("%d ",stack->array[i]);
	}
	return 0;
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("Stack is empty.");
        return 0;
    }
    printf("Top element: %d",stack->array[stack->top]);
}

int main()
{
    printf("Enter the size of stack to be created: ");
    int size;
    scanf("%d",&size);
    struct Stack* stack = createStack(size);
    while(1==1){
  	printf("\n1-push\n2-pop\n3-peek\n4-display\n5-exit\nEnter your choice: ");
  	int choice;
	  scanf("%d",&choice);
  	if(choice==1){
  		push(stack);
	  }
	  else if(choice==2)
	  pop(stack);
	  else if(choice==3)
	  peek(stack);
	  else if (choice==4)
	  display(stack);
	  else if(choice==5)
	  exit(2);
	  else
	  printf("Enter a valid choice.");
	  
	}
    return 0;
}
