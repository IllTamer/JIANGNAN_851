#include "../../main.h"
// 栈 经典应用

// 以下为应用中用到的栈实现，无需关注
typedef char datatype;
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
datatype pop(SeqStack *SS){
    if (SS->top == -1) return -1;
    return SS->data[SS->top--];
}
datatype peek(SeqStack *SS) {
    return SS->data[SS->top];
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

// 逆波兰表达式求值
// 将常规中缀表达式转为后缀表达式，便于求值
// 12+(7-3)*2+9/3 -> 12 7 3 - 2 * + 9 3 / +

// 优先级赋值函数，*/ > +-，括号直接操作
int priority(char opera) {
    return opera == '*' || opera == '/';
}
// 中缀表达式转后缀表达式
// 手动转换：【2分钟秒杀-中缀表达式转前后缀表达式】 https://www.bilibili.com/video/BV1aV4y1771G
// https://zq99299.github.io/dsalg-tutorial/dsalg-java-hsp/05/05.html
SeqStack* ReversePolish(char *string)
{
    SeqStack *res = init(),
    *opera = init(); // 临时储存操作符
    for (int i = 0; i < strlen(string); ++ i)
    {
        char c = string[i];
        // if 四种情况：操作数、运算符、左&右括号
        // 左：括号直接入符号栈
        if (c == '(') push(c, opera);
        // 运算符：判断当前运算符与栈顶优先级，优先级大则入符号栈，反之弹出至左括号/栈空，再入栈
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (1)
            {
                if (empty(opera) == 0 || peek(opera) == '(')
                {
                    push(c, opera);
                    break;
                }
                else {
                    // 同级默认优先值更低
                    if (priority(c) > priority(peek(opera)))
                    {
                        push(c, opera);
                        break;
                    }
                    else push(pop(opera), res);
                }
            }
        }
        // 右括号：弹出符号栈直至左括号
        else if (c == ')')
        {
            while (1)
            {
                char operaTop = pop(opera);
                if (operaTop == '(') break; // 丢弃括号
                push(operaTop, res);
            }
        }
        // 数：直接入结果栈
        // 注意：此处省略char->int的转化，如许实现可参考思路：
        // push(res, (pop(res)-48)*10 + (c-48))
        else push(c, res);
    }
    while (empty(opera) != 0) push(pop(opera), res);
    return res;
}
// 计算后缀表达式
// 借助单个栈直接计算即可

// 个人认为非重点
// 行编辑程序、迷宫求解

int main() {
//    Conversion(1348, 8);
//    ReversePolish("12+(7-3)*2+9/3");
//    printf("%d", BracketMatch("[]{}("));
}

