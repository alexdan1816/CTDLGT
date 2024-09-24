/*
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
    else if(Q->front==(Q->rear+1)%MAX) //nếu hàng đợi đầy hoặc là (front==0 && rear = max-1) || front==rear+1
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
        printf("[%d]",Q.infor[i]);
    }
}

int deQueue(Queue *Q)
{
    if(Q->front=-1)
    {
        printf("Hang doi rong");
        return -1;
    }
    else
    {
        Q->front++;
    return (0);
    }
}
int main()
{
    Queue Q;
    initialize(&Q);
    enQueue(&Q,1);
    enQueue(&Q,2);
    display(Q);
    return 0;
}

*/

//viết một hàm chuyển đổi một số ở hệ 10 sang hệ b dùng stack

#include <stdio.h>
#include <stdbool.h>

#define MAX 10
typedef struct 
{
    int infor[MAX];
    unsigned int n; //số phần tử của stack
}Stack;

void initialize(Stack *S) //khởi tạo ngăn xếp
{
    S->n=0;
}

bool isEmpty(Stack *S) //kiểm tra ngăn xếp rỗng
{
    return (S->n==0);
}

bool isFull(Stack *S) //kiểm tra ngăn xếp đầy
{
    return (S->n==MAX);
}

int push(Stack *S, int k) //thêm dữ liệu vào ngăn xếp
{
    if(isFull(S)) return -1;
    S->infor[S->n]=k;
    S->n++;
}

int pop(Stack *S) //lấy dữ liệu từ ngăn xếp
{
    if(isEmpty(S)) return -1;
    S->n--;
    return S->infor[S->n];
}

int top(Stack *S) //lấy dữ liệu ở đỉnh phần tử nhưng không làm mất phân tử đó
{
    if(isEmpty(S)) return -1;
    return S->infor[(S->n)-1];
}

void display(Stack *S)
{
    for(int i=S->n-1;i>=0;i--)
    {
        printf("%d",S->infor[i]);
    }
}

void transform(Stack*S,int x, int b)
{
    int thg=x;
    do
    {
    push(S,thg%b);
    thg=thg/b;
    }
    while(thg!=0);
    
    
}
int main()
{
    Stack S;
    initialize(&S);
    transform(&S,100,2);
    display(&S);

    return 0;
}