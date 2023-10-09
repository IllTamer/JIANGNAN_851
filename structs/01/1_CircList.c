#include "../../main.h"
// 循环链表
// 循环链表和单链表的主要差异就在于循环的判断条件上，
// 原本是判断 p->next 是否为空，现在则是 p-> next 不等于头结点，则循环未结束。
typedef int datatype;
typedef struct CircList
{
    datatype element;
    struct CircList * next;
} CircList;

// 头节点创建时指向自己，一般有首元节点（题中指出）
CircList* Init()
{
    CircList *head;
    head = (CircList *) malloc(sizeof(CircList));
    head->next = head;
    return head;
}

// 其余操作基本同单链表