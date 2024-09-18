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
    for(int i=0;i<S->n;i++)
    {
        printf("[%d]",S->infor[i]);
    }
}
int main()
{
    Stack S;
    initialize(&S);
    push(&S, 10);
    push(&S, 12);
    printf("%d\n",pop(&S));
    display(&S);
    return 0;
}