#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
    int data[MAX];
    int size;
} Stack;

void initialize(Stack *S)
{
    S->size = 0;
}

bool isFull(Stack *S)
{
    return S->size == MAX;
}

bool isEmpty(Stack *S)
{
    return S->size == 0;
}

void push(Stack *S, int k)
{
    for (int i = S->size - 1; i >= 0; i--)
    {
        S->data[i + 1] = S->data[i];
    }
    S->data[0] = k;
    S->size++;
}

void pop(Stack *S)
{
    for (int i = 0; i < S->size - 1; i++)
    {
        S->data[i] = S->data[i + 1];
    }
    S->size--;
}

void convert(Stack *S, int b, int x)
{
    int thg = x;
    do
    {
        push(S, thg % b);
        thg = thg / b;
    } while (thg != 0);
}

void display(Stack *S)
{
    for (int i = 0; i < S->size; i++)
    {
        printf("%d", S->data[i]);
    }
}

int main()
{
    Stack S;
    initialize(&S);
    convert(&S, 2, 10);
    display(&S);
}