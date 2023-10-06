#include "../main.h"
// 循环队列
// 与顺序栈类似，需设置两指针额外指示队列头尾元素位置
typedef int datatype;
typedef struct
{
    datatype data;
    int front; // 始终指向队列头元素
    int rear;
} CircQueue;

// 有两种入队方式，顺序插入和分布插入（求余）