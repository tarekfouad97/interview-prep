#include <stdio.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

// Check if top == -1
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
        
    }
    else
    {
        printf("Error Stack is Full!\n");
    }
}

int pop(void)
{
    int data;
    if (!isEmpty())
    {
    
    data = stack[top];
    top--;
    return data;    
    }
    else
    {
          printf("Error Stack is Empty!\n");
    }
    
}

int peek()
{

    return stack[top];
}
int main(void)
{
    pop();
    push(12);
    push(13);
    push(14);
    pop();
    push(15);
    printf("top = %d\n", peek());
    pop();
    pop();
    pop();
    
    printf("top = %d\n", peek());
}