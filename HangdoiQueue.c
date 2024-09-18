#include <stdio.h>
#define MAX 10
typedef struct 
{
int front; //chỉ số phần tử đầu hàng đợi
int rear;  //chỉ số phần tử cuối hàng đợi
int infor[MAX];
}Queue;
void initialize(Queue *Q)
{
    Q->front=-1;
    Q->rear=-1;
}

void enQueue(Queue *Q, int k)
{
    if(Q->front==-1) //nếu hàng đợi rỗng
    {
        Q->front=Q->rear=0;
        Q->infor[0]=k;
    }
    else if(Q->rear==MAX-1)
    {
        return;
    }
    else
    {
        Q->rear++;
        Q->infor[Q->rear]=k;
    }
}
void display(Queue Q)
{
    for(int i=Q.front;i<=Q.rear;i++)
    {
        printf("%d ",Q.infor[i]);
    }
}

int deQueue(queue *Q)
{
    if(Q->front=-1)
    {
        printf("Hang doi rong");
        return -1;
    }
    else
    {
        Q->front++;
    return (Q->infor[Q])
    }
}
int main()
{
    Queue Q;
    initialize(&Q);
    enQueue(&Q,1);
    enQueue(&Q,2);
    display(Q);
    printf("Hello world");
    return 0;
}