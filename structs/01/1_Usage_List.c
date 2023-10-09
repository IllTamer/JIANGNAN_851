#include "../../main.h"

#define datatype char
typedef struct Node {
  datatype data;
  struct Node *next;
} LinkList;

// 头插法建立单链表（不带头节点，好写）
// 12345（输入）->54321（输出）
LinkList * Front()
{
    LinkList *head, *p;
    char c;
    head = NULL;
    printf("请输入数据，并以“#”结尾\n");
    while((c = getchar()) != '#')
    {
        p = (LinkList *) malloc(sizeof(LinkList));
        p->data = c;
        p->next = head;
        head = p;
    }
    return head;
}

// 尾插法建立单链表（带头节点，好写）
// 12345（输入）->12345（输出）
LinkList * End()
{
    LinkList *head, *p, *temp;
    head = (LinkList *) malloc(sizeof(LinkList));
    head->data = 0;
    head->next = NULL;
    p = head;
    char c;
    printf("请输入数据，并以“#”结尾\n");
    while((c = getchar()) != '#')
    {
        temp = (LinkList *) malloc(sizeof(LinkList));
        temp->data = c;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    if (p != NULL) p->next = NULL;
    return head;
}

// 带头节点的单链表就地逆置
// 空间复杂度O(1)
LinkList* Reverse(LinkList *list)
{
    LinkList *p,
    *temp; // temp 用于暂存头插时断开的节点
    p = list->next;
    list->next = NULL;
    while (p != NULL)
    {
        temp = list->next; // 暂存尾巴
        list->next = p; // 接上当前节点（以及一串还未逆置的节点）
        p = p->next; // 指针进位
        list->next->next = temp; // 接上尾巴顺便断开未逆置的节点
    }
    return list;
}

// 假设有两个按元素值递增排列的线性表，均是单链表，请将其合并归为一个
// 按元素值递减次序排列的单链表，并利用原来两个单链表的节点存放归并后的单链表

// 思路：a123、b1234 -> c4332211
// 默认有头节点，直接拿a*或b*->next头插比较后的节点即可，<=优先

int main() {
    Reverse(End());
    printf("end");
}