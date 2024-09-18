#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef struct 
{
    int num;
    char name[100];
}book;

typedef struct 
{
    book shelf[MAX];
    unsigned int n;
}Stack;

void initialize(Stack *S) //khởi tạo stack
{
    S->n=0;
}

bool isEmpty(Stack *S)  //check xem stack trống
{
    return (S->n==0);
}

bool isFull(Stack *S)   //check xem stack đầy
{
    return (S->n==MAX);
}

void display(Stack *S,int n)  //ham hiển thị sách
{
        printf("TT %d\n",S->shelf[n].num);
        printf("Name: %s",S->shelf[n].name);
}
void enterbook(Stack *S,int n)    //hàm nhập thông tin sách
{
    printf("Nhap ten sach\n");
    scanf("%s",&S->shelf[n].name);
    fflush(stdin);
    printf("Nhap ma so sach\n");
    scanf("%d",&S->shelf[n].num);
}

int push(Stack *S) //thêm sách vào stack
{
    if(isFull(S)) return -1;
    enterbook(&S,S->n-1);
    S->n++;
}

int pop(Stack *S) //lấy sách khỏi stack
{
    if(isEmpty(&S)) return -1;
    S->n--;
}

int top(Stack *S) //lấy thông tin sách
{
    if(isEmpty(&S)) return -1;
    display(&S,S->n-1);

}
int main()
{
    Stack S;
    initialize(&S);
    push(&S);
    push(&S);
    top(&S);

}