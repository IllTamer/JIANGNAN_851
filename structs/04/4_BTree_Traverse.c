#include "../../main.h"
// 遍历二叉树
#define datatype int
// 用到的树
typedef struct Node {
    datatype data;
    struct Node *left, *right;
} BTree;
BTree* creatNode(datatype data) {
    BTree *node = (BTree *)malloc(sizeof(BTree));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}
void addNode(BTree *parent, datatype data) {
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
BTree* CreateTreeList(int *nodes, int len) {
    BTree *root = creatNode(nodes[0]);
    for (int i = 1; i < len; ++ i) {
        addNode(root, nodes[i]);
    }
    return root;
}
// 用到的队列
#define MAX_SIZE 64
typedef struct {
    BTree* data[MAX_SIZE];
    int front; // 始终指向队列头元素
    int rear; // 始终指向队尾元素
    int num; // 记录队列中数据个数
} CircQueue;
int empty(CircQueue *queue) {
    return queue->num == 0;
}
void insert(CircQueue *queue, BTree *data) {
    // 新队尾元素地址：队尾+1取模
    int pos = (queue->rear + 1) % MAX_SIZE;
    // 装满
    if (queue->num == MAX_SIZE) return;
    queue->data[queue->rear] = data;
    queue->rear = pos;
    ++queue->num;
}
BTree* delete(CircQueue *queue) {
    // 队列为空
    if(empty(queue)) return NULL;
    BTree *data = queue->data[queue->front];
    // 新队头元素地址：队头+1取模
    queue->front = (queue->front + 1) % MAX_SIZE;
    --queue->num;
    return data;
}

// 二叉树
//     4
//   2   6
// 1  3 5  7

// 前序遍历（递归）
// 根->左->右
// 4 2 1 3 6 5 7
void Pre(BTree *parent)
{
    if (parent == NULL) return;
    printf("%d ", parent->data);
    Pre(parent->left);
    Pre(parent->right);
}

// 中序遍历（递归）
// 左->根->右
// 1 2 3 4 5 6 7
void In(BTree *parent)
{
    if (parent == NULL) return;
    In(parent->left);
    printf("%d ", parent->data);
    In(parent->right);
}

// 后序遍历（递归）
// 左->右->根
// 1 3 2 5 7 6 4
void Post(BTree *parent)
{
    if (parent == NULL) return;
    Post(parent->left);
    Post(parent->right);
    printf("%d ", parent->data);
}

// 层序遍历（队列）
// 一层一层遍历
// 4 2 6 1 3 5 7
void Level(BTree *parent)
{
    if (parent == NULL) return;
    // 初始化一个用于存放每层节点的队列
    CircQueue *queue = (CircQueue *) malloc(sizeof(CircQueue));
    insert(queue, parent);
    BTree *node = NULL;
    while (!empty(queue))
    {
        // 取出当前父节点
        node = delete(queue);
        if (node != NULL)
        {
            printf("%d ", node->data);
            // 按顺序插入左右孩子节点
            // 先入先出，孩子节点会先于孙子节点打印
            if (node->left != NULL) insert(queue, node->left);
            if (node->right != NULL) insert(queue, node->right);
        }
    }
}

int main() {
    int nodes[] = {4,2,6,1,3,5, 7};
    BTree *root = CreateTreeList(nodes, sizeof(nodes)/sizeof(nodes[0]));
    Pre(root);
    printf("\n");
    In(root);
    printf("\n");
    Post(root);
    printf("\n");
    Level(root);
}