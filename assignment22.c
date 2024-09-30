#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct 
{
    int value;
    int priority;
    
}Element;
Element createElement(int val, int pri) // hàm khởi tạo phần tử element
{
    Element e;
    e.value = val;
    e.priority = pri;
    return e;
}
typedef struct 
{
    Element data[MAX];
    int size;
}priQueue;


void intialize(priQueue *Q) //khởi tạo hàng đợi
{
    Q->size=0;
}

bool isEmpty(priQueue *Q)
{
    return(Q->size==0);
}

bool isFull(priQueue *Q)
{
    return(Q->size==MAX);
}

void enQueue(priQueue *Q, Element k) //nhập dữ liệu cho hàng đợi
{
    if(isEmpty(Q))
    {
        Q->size++;
        Q->data[0]=k;
    }
    else if(isFull(Q))
    {
        printf("Hang doi day");
        return;
    }
    else 
    {
        int i=Q->size-1;
        while(i>=0 && k.priority>Q->data[i].priority)
        {
            Q->data[i+1]=Q->data[i];
            i--; 
        }
        
        Q->data[i+1]=k;
        Q->size++;
    
    }
}

void deQueue(priQueue *Q) //xóa phần tử trong hàng đợi (xóa phần tử lớn nhất)
{
    if(isEmpty(Q))
    {
        printf("hang doi rong\n");
        return;
    }
    for(int i=0;i<=Q->size;i++)
    {
        Q->data[i]=Q->data[i+1];
    }
    Q->size--;
}
void display(priQueue *Q) //hàm hiển thị
{
    if(isEmpty(Q))
    {
        printf("hang doi rong\n");
        return;
    }
    if(isFull(Q))
    {
        printf("hang doi day\n");
        return;
    }

    for(int i=0;i<Q->size;i++)
    {
        printf("Phan tu [%d], uu tien %d\n", Q->data[i].value, Q->data[i].priority);
    }
}


int main()
{
    priQueue Q;
    intialize(&Q);
    Element a = createElement(1,2);
    Element b = createElement(2,3);
    Element c = createElement(3,4);
    Element d = createElement(5,1);
    enQueue(&Q,a);
    enQueue(&Q,b);
    enQueue(&Q,c);
    enQueue(&Q,d);
    deQueue(&Q);
    display(&Q);

    
}