#include <stdio.h>
#define MAX 10
typedef struct 
{
    int data;
    int priority;
}Element;

typedef struct 
{
    Element infor[MAX];
    int size;
}priorityQ;

void initial(priorityQ *Q)
{
    Q->size=0;
    Q->infor[MAX];
}

void enQ(priorityQ *Q,Element k)
{
    if(Q->size==MAX-1)
    {
        printf("Hang doi day");
        return;
    }
    //tìm vị trí để chèn phần tử mới dựa trên mức độ ưu tiên
    int i=Q->size-1;
    while (i>=0 && Q->infor[i].priority<k.priority)
        {
            Q->infor[i+1]=Q->infor[i];//dịch chuyển phần tử có ưu tiên
            i--;
        }
    Q->infor[i+1]=k;
    Q->size++;
    
}
Element deQ(priorityQ *Q, Element removeItem)
{
    if(Q->size==0)
    {
        printf("hang doi rong");
        Element defaultitem = {-1,-1};
        return defaultitem;
    }
    Element removeItem = Q->infor[0];
    for(int i=0;i<Q->size-1;i++)
    {
        Q->infor[i].data=Q->infor[i+1].data;
        Q->infor[i].priority=Q->infor[i+1].priority;
    }
    return removeItem;
}

void display(priorityQ *Q)
{
    if(Q->size=0)
    {
        printf("Ham doi rong\n");
        return;
    }
    printf("Hang doi uu tien hien tai:\n");
    for(int i=0;i<Q->size;i++)
    {
        printf("Phan tu: %d,do uu tien: %d\n",Q->infor[i].data, Q->infor[i].priority);
    }

}

int main()
{
    priorityQ Q;
    Element k;
}

//viết một hàm chuyển đổi một số ở hệ 10 sang hệ b dùng stack