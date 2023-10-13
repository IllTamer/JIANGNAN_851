#include "../../main.h"

// 二叉排序树
// 左 < 根 < 右 / 空
// 平均：O(log2n) 特殊：O(n) —— 斜树

// 平衡二叉树（二叉排序树plus

#define datatype int
// 平衡二叉树 —— AVL实现
// 简答题：https://www.bilibili.com/video/BV16m4y1F7do

// https://www.cnblogs.com/skywang12345/p/3576969.html
typedef struct AVLTNode {
    datatype data;
    // 平衡因子 表示节点左子树深度同右子树深度的差
    int height;
    struct AVLTNode *left, *right;
} AVLTree;
// 节点创建
AVLTree* create(datatype data, AVLTree *left, AVLTree *right) {
    AVLTree *node = (AVLTree *) malloc(sizeof(AVLTree));
    node->data = data;
    node->left = left;
    node->right = right;
    node->height = 0;
    return node;
}
int height(AVLTree *node) {
    return node == NULL ? 0 : node->height;
}
int max(int v1, int v2) {
    return v1 >= v2 ? v1 : v2;
}

// AVL有四种失去平衡的姿态：LL、LR、RL、RR
// 节点x插入在根节点的(?)子树的(?)孩子上
// https://images0.cnblogs.com/i/497634/201403/281625317193879.jpg
// LL —— 往右旋：https://images0.cnblogs.com/i/497634/201403/281626153129361.jpg
AVLTree* LL(AVLTree *k2) {
    AVLTree* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    // 更新高度
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    // 返回新的根节点
    return k1;
}
// RR(LL镜像) —— 往左旋：https://images0.cnblogs.com/i/497634/201403/281626410316969.jpg
AVLTree* RR(AVLTree *k1) {
    AVLTree* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    // 更新高度
    k1->height = max(height(k1->right), height(k1->left)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    // 返回新的根节点
    return k2;
}
// LR = RR + LL —— (左子树)先往左(根)再往右旋：https://images0.cnblogs.com/i/497634/201403/281627088127150.jpg
AVLTree* LR(AVLTree *k3) {
    k3->left = RR(k3->left);
    return LL(k3);
}
// RL = LL + RR —— (右子树)先往右(根)再往左旋：https://images0.cnblogs.com/i/497634/201403/281628118447060.jpg
AVLTree* RL(AVLTree *k1) {
    k1->right = LL(k1->right);
    return RR(k1);
}

