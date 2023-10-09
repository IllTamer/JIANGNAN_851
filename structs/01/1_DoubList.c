#include "../../main.h"
// 双向链表
typedef int datatype;
typedef struct DoubList
{
    datatype element;
    struct DoubList * prior;
    struct DoubList * next;
} DoubList;

// 有首元节点（题中指出）
DoubList* Init()
{
    DoubList *head;
    head = (DoubList *) malloc(sizeof(DoubList));
    return head;
}

// 其余操作基本同单链表