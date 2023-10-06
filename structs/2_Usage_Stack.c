#include "../main.h"
// 栈 经典应用

// 以下为应用中用到的栈实现，无需关注
typedef int datatype;
typedef struct{
    datatype data[128];
    int top; // 顺序栈栈顶位置
} SeqStack;
SeqStack* init(){
    SeqStack *SS;
    SS = (SeqStack *) malloc(sizeof(SeqStack));
    SS -> top = -1;
    return SS;
}
void push(datatype data, SeqStack* SS){
    SS->data[++SS->top]=data;
}
datatype pop(SeqStack* SS){
    if (SS->top == -1) return -1;
    return SS->data[SS->top--];
}
int empty(SeqStack* SS) {
    if (SS->top == -1) return 0;
    return -1;
}

// 数制转换（求余法）
// 10进制->b进制
void Conversion(int num, int b) {
    SeqStack * stack = init();
    while (num) {
        push(num % b, stack);
        num = num / b;
    }
    while (!empty(stack)) {
        printf("%d ", pop(stack));
    }
}

// 括号匹配
// 输入仅包含括号
int BracketMatch(char* string) {
    SeqStack * stack = init();
    for (int i = 0; i < strlen(string); ++i) {
        char c = string[i];
        char prior;
        switch (c) {
            case ')':
                prior = pop(stack);
                if (prior != '(') return -1;
                break;
            case ']':
                prior = pop(stack);
                if (prior != '[') return -1;
                break;
            case '}':
                prior = pop(stack);
                if (prior != '{') return -1;
                break;
            default:
                push(c, stack);
        }
    }
    return empty(stack);
}

// 表达式求值
// 理解思想即可（运算符间优先关系）
// https://blog.csdn.net/qq_37083857/article/details/109721880

// 行编辑程序、迷宫求解
// 个人认为非重点

int main() {
//    Conversion(1348, 8);
//    printf("%d", BracketMatch("[]{}("));
}

