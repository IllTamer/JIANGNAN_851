#include "../main.h"
// 顺序栈（先进先出）
// 本质是数组
typedef int datatype;
typedef struct
{
    datatype data[100];
    int top; // 顺序栈栈顶位置
} SeqStack;

SeqStack* Init()
{
    SeqStack *SS;
    SS = (SeqStack *) malloc(sizeof(SeqStack));
    SS -> top = -1;
    return SS;
}

void Push(datatype data, SeqStack* SS)
{
    SS->data[++SS->top]=data;
}

datatype Pop(SeqStack* SS)
{
    if (SS->top == -1) return -1;
    return SS->data[SS->top--];
}

//int main()
//{
//    SeqStack* SS = Init();
//    Push(6, SS);
//    printf("%d\n", Pop(SS));
//    printf("%d\n", Pop(SS));
//    return 0;
//}