#include "../../main.h"
// 队列
// 先进先出：一端插入，一端删除

// 链队列
// 节点定义
typedef int datatype;
typedef struct QNode
{
    datatype data;
    struct QNode* next;
} QNode, LinkQueue;

// 链队列一般带首部
LinkQueue* Init()
{
    LinkQueue *queue;
    queue = (LinkQueue *) malloc(sizeof(LinkQueue));
    return queue;
}

// 入队，传入尾节点
void EnQueue(datatype data, QNode * rear);
// 出队，传入头尾节点
// 当头尾节点指向相同时，队列为空
void DeQueue(QNode * top, QNode * rear);

// 一个链队列需要两个分别指示队头和队尾的指针才能唯一确定
// 也即采用头插、尾插、删除等涉及头尾节点的方法时应同步更新指针
int main() {
    LinkQueue * queue;
    QNode *top, *rear;
    queue = top = rear = Init();//创建头结点
}