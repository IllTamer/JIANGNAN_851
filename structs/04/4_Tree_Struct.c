#include "../../main.h"
// 树的存储结构
#define MAX_SIZE 128
#define datatype int

// 双亲表示法（顺序表/数组）
// 节点结构
typedef struct {
    datatype data;
    int parent; // 双亲位置域，若为根节点则为-1
} PTNode;
// 树结构
typedef struct  {
    PTNode* nodes[MAX_SIZE];
    int root, // 根的位置
    num; // 节点数
} PTree;

// 孩子表示法（顺序表+链表）
// 孩子节点
typedef struct CTNode {
    int child; // 数据在数组中储存位置的下标
    struct CTNode *next;
} ChildPtr;
typedef struct {
    datatype data;
    ChildPtr *firstChild; // 孩子链表头指针
} CTBox;
typedef struct {
    CTBox* nodes[MAX_SIZE];
    int root, // 根的位置
    num; // 节点数
} CTree;

// 孩子兄弟表示法（链表）
typedef struct CBNode {
    datatype data;
    struct CBNode *firstChild, // 指向该节点的第一个孩子
    *nextBrother; // 指向该节点的右兄弟
} CBTree;