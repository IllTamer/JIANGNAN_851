#include "../main.h"
// 线性链表
typedef int datatype;
typedef struct List
{
    datatype element;
    struct List * next;
} List;

// 设置首元节点 不赋值，方便头插
List* Init()
{
    List *link;
    link = (List *) malloc(sizeof(List));
    return link;
}

void Add(datatype element, List* link) {
    List * temp = link;
    while (temp->next != NULL)
        temp = temp->next;
    List * new = (List *) malloc(sizeof(List));
    new->element = element;
    temp->next = new;
}

void Insert(datatype element, int index, List* link) {
    List * temp = link;
    // 遍历到上个节点
    for (int i = 0; i < index; ++ i) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    List * new = (List *) malloc(sizeof(List));
    new->element = element;
    new->next = temp->next;
    temp->next = new;
}

// 注意 free 节点
void Delete(int index, List* link)
{
    List * temp = link;
    // 遍历到上个节点
    for (int i = 0; i < index; ++ i) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    List * del = temp->next;
    temp->next = temp->next->next;
    free(del); // 手动释放结点，防止内存泄漏
}

void Set(datatype element, int index, List* link)
{
    List * temp = link;
    int i = -1;
    while (temp != NULL) {
        if (i == index) {
            temp->element = element;
            return;
        }
        temp = temp->next;
        ++ i;
    }
}

datatype Get(int index, List* link)
{
    List * temp = link;
    int i = -1;
    while (temp != NULL) {
        if (i == index) {
            return temp->element;
        }
        temp = temp->next;
        ++ i;
    }
    return -1;
}

void display(List * link){
    List * temp = link->next;
    while (temp != NULL) {
        printf("%d", temp->element);
        temp=temp->next;
    }
    printf("\n");
}

//int main() {
//    List * link = Init();
//    for (int i = 1; i <= 5; ++ i)
//        Insert(i, 0, link);
//    display(link); // 054321
//    Delete(3, link);
//    display(link); // 05431
//    printf("%d\n", Get(1, link)); // 4
//    Add(8, link);
//    display(link);
//    Set(9, 2, link);
//    display(link);
//}
