#include <iostream>

typedef struct 
{
    int info [10];
    unsigned int n; 
} Stack;

void Initialize (Stack &S)
{
    S.n =0;
}

bool IsEmpty (Stack S)
{
    return (S.n == 0);
}

bool IsFull (Stack S)
{
    return (S.n == 10);
}
void Push (int K, Stack & S)
{
if (IsFull(S)) return;
S.info[S.n] = K;
S.n++;}
int Pop (Stack & S){
if (IsEmpty(S)) return NULL;
S.n--;
return S.info[S.n];}
int Top (Stack S){
if (IsEmpty(S)) return NULL;
return S.info[S.n - 1];
}

int main()
{
    
}