#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef struct 
{
    int front;
    int rear;
    int infor[MAX];
}Queue;

void initialize(Queue *Q)
{
    Q->front=-1;
    Q->rear=-1;
}

void  enQueue(Queue *Q,int k)
{
    if(Q->front==-1)
    {
        Q->front=0;
        Q->rear=0;
        Q->infor[0]=k;
    }
    else if(Q->rear==MAX-1)
    {
        printf("Hang doi day");
        return;
    }
    else 
    {
        Q->rear++;
        Q->infor[Q->rear]=k;
    }
}

void deQueue(Queue *Q)
{
    if(Q->front==-1)
    {
        printf("Hang doi rong");
        return;
    }
    else
    {
        Q->front++;
    }
}

void display(Queue *Q)
{
    for(int i=Q->front; i<=Q->rear;i++)
    {
        printf("[%d]",Q->infor[i]);
    }
}

int popQueue(Queue *Q)
{
    Q->front++;
    Q->infor[Q->front];
}

int main()
{
    Queue Q1;
    initialize (&Q1);
    enQueue(&Q1,2);
    enQueue(&Q1,3);
    enQueue(&Q1,4);
    enQueue(&Q1,5);
    display(&Q1);
    popQueue(&Q1);
    display(&Q1);

}