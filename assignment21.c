#include <stdio.h>
#include <stdbool.h>
#define MAX 10


typedef struct 
{
    int data[MAX];
    int rear;
    int front;
}cirQueue;

void initialize(cirQueue *Q)
{
    Q->front=-1;
    Q->rear=-1;
}

bool isEmpty(cirQueue *Q)
{
    return(Q->front==-1);
}

bool isFull(cirQueue *Q)
{
    return (Q->front==(Q->rear+1)%MAX);
}

void enQueue(cirQueue *Q,int k)
{
    if(isFull(Q))
    {
    printf("Hang doi day");
    return;
    }
    else if(isEmpty(Q))
    {
        Q->front=0;
        Q->rear=0;
        Q->data[Q->rear]=k;
    }
    else 
    {
        if(Q->rear==MAX-1)
        {
            Q->rear=0;
            Q->data[Q->rear]=k;
        }
        else
        {
            Q->rear++;
            Q->data[Q->rear]=k;
        }
    }
}

void deQueue(cirQueue *Q)
{
    if(isEmpty(Q))
    {
        printf("Hang doi rong");
        return;
    }
    else 
    {
        if(Q->front==MAX-1)
        {
            Q->front=0;
        }
        else Q->front++;
    }
}

void display(cirQueue *Q)
{
    if(isEmpty(Q))
    {
        printf("hang doi rong");
        return;
    }
    else if(Q->front<=Q->rear)
    {
        for(int i=Q->front;i<=Q->rear;i++)
        {
            printf("Phan tu thu %d [%d]\n",i,Q->data[i]);
        }
    }
    else
    {
        for(int i=0;i<=Q->rear;i++)
        {
            printf("Phan tu thu %d [%d]\n",i,Q->data[i]);
        }
        for(int i=Q->front;i<=MAX-1;i++)
        {
            printf("Phan tu thu %d [%d]\n",i,Q->data[i]);
        }
    }
}
int main()
{
    cirQueue Q;
    initialize(&Q);
    enQueue(&Q,2);
    enQueue(&Q,3);
    enQueue(&Q,4);
    enQueue(&Q,5);
    enQueue(&Q,6);
    enQueue(&Q,7);
    enQueue(&Q,8);
    enQueue(&Q,8);
    enQueue(&Q,8);
    enQueue(&Q,8);
    
    

    deQueue(&Q);
    deQueue(&Q);
    deQueue(&Q);

    

    enQueue(&Q,8);
    enQueue(&Q,8);
    enQueue(&Q,8);

    display(&Q);




    return;
}