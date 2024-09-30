#include <stdio.h>
#define MAX 10

typedef struct 
{   
    int rear;
    int infor[MAX];
    unsigned int n;
}Stack;

void initialize(Stack *S) //hàm khởi tạo
{
    S->n=0;
    S->rear=-1;

}

void enStack(Stack *S,int k) //hàm thêm dữ liệu thông thường
{
    if(S->rear==-1)
    {
        S->rear=0;
        S->infor[0]=k;
    }
    else if(S->rear==MAX-1)
    {
        return;
    }
    else
    {
        S->rear++;
        S->infor[S->rear]=k;
    }
}

int insStack(Stack *S, int value, int position) //hàm chèn dữ liệu 
{
    if(S->rear==MAX-1)
    {
        printf("Ngan xep day\n");
        return -1;
    }
    else if(position>MAX-1)
    {
        printf("Vi tri khong hop le\n");
        return -1;
    }
    else if(position>S->rear)
    {
        S->rear++;
        S->infor[S->rear]=value;
    }
    else if(position<=S->rear)
    {
        int temp=S->rear+1;
        S->rear++;
        for (int i=S->rear;i>=position;i--)
        {
            if(i==position)
            {
                S->infor[i]=value;
                break;
            }
            int index=S->infor[i-1];
            S->infor[i]=index;        
        }
    }
}
int deStack(Stack *S,int position) //hàm xóa dữ liệu bất kì
{
    if(position>S->rear||position<0)
    {
        printf("Vi tri khong hop le");
        return -1;
    }
    else 
    {
        for(int i=position;i<S->rear;i++)
        {
            int index=S->infor[i+1];
            S->infor[i]=index;
        }
        S->rear--;
    }
}


void display(Stack *S) //hàm hiển thị
{
    
    for(int i=0;i<=S->rear;i++)
    {
        printf("[%d]",S->infor[i]);
    }
    printf("\n");
}


int main()
{
    Stack S;
    initialize(&S);
    enStack(&S,1);
    enStack(&S,2);
    enStack(&S,3);
    enStack(&S,4);
    enStack(&S,5);
    display(&S);
    insStack(&S,99,4);
    display(&S);
    deStack(&S,4);
    display(&S);

}