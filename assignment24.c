#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int compare(char c)
{
    if (c == '^')
        return 5;
    if (c == '*' || c == '%' || c == '/')
        return 4;
    if (c == '+' || c == '-')
        return 3;
    return 2;
}

typedef struct
{
    char data[MAX];
    int top;
} Stack;

// Hàm kh?i t?o stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Hàm ki?m tra stack r?ng
int isEmptyS(Stack *s)
{
    return s->top == -1;
}

// Hàm ki?m tra stack d?y
int isFullS(Stack *s)
{
    return s->top == MAX - 1;
}

// Hàm d?y ph?n t? vào stack
void pushS(Stack *s, char value)
{
    if (isFullS(s))
    {
        printf("Stack d?y!\n");
        return;
    }
    s->data[++s->top] = value;
}

// Hàm l?y ph?n t? kh?i stack
char popS(Stack *s)
{
    if (isEmptyS(s))
    {
        printf("Stack r?ng!\n");
        return -1;
    }
    return s->data[s->top--];
}

// Hàm xem ph?n t? d?u tiên c?a stack
char peekS(Stack *s)
{
    if (isEmptyS(s))
    {
        printf("Stack r?ng!\n");
        return -1;
    }
    return s->data[s->top];
}

typedef struct
{
    char data[MAX];
    int front, rear;
} Queue;

// Hàm kh?i t?o queue
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

// Hàm ki?m tra queue r?ng
int isEmptyQ(Queue *q)
{
    return q->front > q->rear;
}

// Hàm ki?m tra queue d?y
int isFullQ(Queue *q)
{
    return q->rear == MAX - 1;
}

// Hàm thêm ph?n t? vào queue
void enqueue(Queue *q, char value)
{
    if (isFullQ(q))
    {
        printf("Queue d?y!\n");
        return;
    }
    q->data[++q->rear] = value;
}

// Hàm l?y ph?n t? ra kh?i queue
char dequeue(Queue *q)
{
    if (isEmptyQ(q))
    {
        printf("Queue r?ng!\n");
        return -1;
    }
    return q->data[q->front++];
}

// Hàm xem ph?n t? d?u tiên c?a queue
char peekQ(Queue *q)
{
    if (isEmptyQ(q))
    {
        printf("Queue r?ng!\n");
        return -1;
    }
    return q->data[q->front];
}

void displayQueue(Queue *queue) // hàm hi?n th? queue
{
    if (isEmptyQ(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%c ", queue->data[i]);
    }
    printf("\n");
}

void breakdown(char *s, Stack *S1, Queue *Q1)
{
    char input[100];
    char temp;
    strcpy(input, s);
    int i = 0;
    while (input[i] != '\0' && input[i] != '\n')
    {

        if (isdigit(input[i]))
        {
            enqueue(Q1, input[i]);
        }
        else if (input[i] == '(')
            pushS(S1, input[i]);
        else if (input[i] == ')')
        {
            while (!isEmptyS(S1) && S1->data[S1->top] != '(')
            {
                enqueue(Q1, popS(S1));
            }
            popS(S1);
        }

        else if (strchr("+-*/%^", input[i]))
        {
            while (!isEmptyS(S1) && compare(peekS(S1)) >= compare(input[i]))
            {
                enqueue(Q1, popS(S1));
            }
            pushS(S1, input[i]);
        }
        i++;
    }
    while (!isEmptyS(S1))
    {
        enqueue(Q1, popS(S1));
    }
}

int main()
{
    char input[100];
    printf("nhap phep tinh\n");
    fgets(input, 100, stdin);
    Stack S1;
    initStack(&S1);
    Queue Q1;
    initQueue(&Q1);
    breakdown(input, &S1, &Q1);
    displayQueue(&Q1);
}