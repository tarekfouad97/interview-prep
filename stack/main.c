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
    if (isFull() == 1)
    {
        printf("Error Stack is Full!\n");
    }
    else if (isFull() == 0)
    {   top++;
        stack[top] = data;
        
    }
}

int pop(void)
{
    int data;
    if (isEmpty() == 1)
    {
        printf("Error Stack is Empty!\n");
    }
    else if (isEmpty() == 0)
    {
        data = stack[top];
        top--;
    }
    return data;
}

int peek()
{
    if (isEmpty)
    {
        printf("Stack is Empty!\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}
int main(void)
{
    pop();
    push(12);
    push(13);
    push(14);
    pop();
    push(15);
    printf("top = %d\n",stack[1]);
    pop();
    pop();
    pop();
    printf("top = %d\n",peek());
}