#include "../../main.h"
// 循环队列
// 与顺序栈类似，需设置两指针额外指示队列头尾元素位置
#define MAX_SIZE 128
typedef int datatype;
typedef struct
{
    datatype data[MAX_SIZE];
    int front; // 始终指向队列头元素
    int rear; // 始终指向队尾元素
    int num; // 记录队列中数据个数
} CircQueue;

int Empty(CircQueue *queue)
{
    return queue->num == 0;
}

void Insert(CircQueue *queue, datatype data)
{
    // 新队尾元素地址：队尾+1取模
    int pos = (queue->rear + 1) % MAX_SIZE;
    // 装满
    if (queue->num == MAX_SIZE) return;
    queue->data[queue->rear] = data;
    queue->rear = pos;
    ++queue->num;
}

datatype Delete(CircQueue *queue)
{
    // 队列为空
    if(Empty(queue)) return -1;
    datatype data = queue->data[queue->front];
    // 新队头元素地址：队头+1取模
    queue->front = (queue->front + 1) % MAX_SIZE;
    --queue->num;
    return data;
}