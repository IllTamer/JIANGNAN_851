#include "../../main.h"

#define datatype int
#define MAX_SIZE 128
// 顺序存储结构（数组）
// 可以在非完全二叉树中添加空节点使之变成完全二叉树（会浪费空间
// 所以顺序储存一般只用于完全二叉树或满二叉树
void CreateTreeArray(const datatype *nodes, int len)
{
    int tree[MAX_SIZE] = {0};
    int deep = 1;
    for (int i = 0, j; i < len;)
    {
        j = 0;
        // 每层有2^(deep-1)个节点
        while (j != 1<<(deep-1))
        {
            if (i+j == len) break;
            // 第n层起点 = 2^(deep-1)-1
            tree[(1<<(deep-1))-1 + j] = nodes[i+j];
            ++ j;
        }
        ++deep;
        i += j; // 一层的叶子节点全部添加完毕
    }
    printf("%d", tree);
}

// 链式存储结构（指针）
typedef struct Node
{
    datatype data;
    // 二叉链表定义，三叉链表多一个 *parent
    struct Node *left, *right;
} BTree;

BTree* creatNode(datatype data)
{
    BTree *node = (BTree *)malloc(sizeof(BTree));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

void addNode(BTree *parent, datatype data)
{
    if (data <= parent->data) {
        if (parent->left == NULL) {
            parent->left = creatNode(data);
        } else addNode(parent->left, data);
    } else {
        if (parent->right == NULL) {
            parent->right = creatNode(data);
        } else addNode(parent->right, data);
    }
}
BTree* CreateTreeList(int *nodes, int len)
{
    BTree *root = creatNode(nodes[0]);
    for (int i = 1; i < len; ++ i) {
        addNode(root, nodes[i]);
    }
    return root;
}

// 线索二叉树
// 节点数为n的二叉树一共有2n个指针，但仅使用了n-1个指针（边）
// 故存在 2n-(n-1) = n+1 个空闲指针
// 将该 n+1 个空闲指针指向一定规则下对应的前驱/后继节点，便于该种规则的遍历
// 该种重复利用的指针叫线索，这样的二叉树叫线索二叉树，这样的二叉链表叫线索链表
enum Type {
    CHILD = 0, // 该指针指向孩子节点
    THREAD = 1 // 该指针为线索
};
typedef struct ThreadNode
{
    datatype data;
    struct ThreadNode *left, *right;
    enum Type lType, rType;
} ThreadTree;

int main() {
    int nodes[] = {4,2,6,1,3,5, 7};
//    CreateTreeArray(nodes, sizeof(nodes)/sizeof(nodes[0]));
    BTree *root = CreateTreeList(nodes, sizeof(nodes)/sizeof(nodes[0]));
    printf("");
}