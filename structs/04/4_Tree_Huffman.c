#include "../../main.h"
// Huffman树
// 当用 n 个结点（都做叶子结点且都有各自的权值）试图构建一棵树时，
// 如果构建的这棵树的带权路径长度最小，称这棵树为“最优二叉树”，也叫“Huffman树”
// http://data.biancheng.net/view/33.html
// 【哈弗曼树的构造方法】 https://www.bilibili.com/video/BV1na4y1v7FM

// 由于哈夫曼树的构建是从叶子结点开始，不断地构建新的父结点，直至树根，
// 所以结点中应包含指向父结点的指针。但是在使用哈夫曼树时是从树根开始，
// 根据需求遍历树中的结点，因此每个结点需要有指向其左孩子和右孩子的指针
typedef struct {
    int weight; // 节点权重
    // 采用数组方式储存树，更好写
    int parent, left, right; // 节点索引，初始-1
} HTree;

// 构建原则：权重越大的结点离树根越近
/**
 * 1. 在 n 个权值中选出两个最小的权值，对应的两个结点组成一个新的二叉树，且新二叉树的根结点的权值为左右孩子权值的和；<br>
 * 2. 在原有的 n 个权值中删除那两个最小的权值，同时将新的权值加入到 n–2 个权值的行列中，以此类推；<br>
 * 3. 重复 1 和 2 ，直到所有的结点构建成了一棵二叉树为止<br>
 * */
// 查询算法，找出最小的两个叶子节点
void Select(int *min1, int *min2, int range, HTree* nodes[]) {
    HTree *res1 = NULL, *res2 = NULL;
    for (int i = 0; i < range; ++ i) {
        HTree *node = nodes[i];
        // 有根说明不是叶子节点 跳过
        if (node->parent != -1) continue;
        if (res1 == NULL) {
            res1 = node;
            *min1 = i;
            continue;
        }
        if (res2 == NULL) {
            res2 = node;
            *min2 = i;
            continue;
        }
        if (node->weight < res1->weight) {
            res2 = res1;
            *min2 = *min1;
            // min1 <= min2，当min1更新前，min2需继承min1坐标
            res1 = node;
            *min1 = i;
        } else if (node->weight < res2->weight) {
            res2 = node;
            *min2 = i;
        }
    }
}
void Create(const int inputs[], int len) {
    // Huffman数叶子节点数 len（输入）,总节点数 m=2*len-1
    int m = 2*len-1;
    HTree* nodes[m];
    // 初始化各叶子节点
    for (int i = 0; i < len; ++ i) {
        nodes[i] = (HTree *) malloc(sizeof (HTree));
        nodes[i]->parent = -1;
        nodes[i]->left = -1;
        nodes[i]->right = -1;
        nodes[i]->weight = inputs[i];
    }
    // 初始化各级父节点
    for (int i = len; i < m; ++ i) {
        nodes[i] = (HTree *) malloc(sizeof (HTree));
        nodes[i]->parent = -1;
        nodes[i]->left = -1;
        nodes[i]->right = -1;
        nodes[i]->weight = 0;
    }
    // 构建Huffman数，从下标len开始计算，直到m-1即为根节点
    for (int i = len; i < m; ++ i) {
        int min1, min2;
        Select(&min1, &min2, i, nodes);
        nodes[i]->weight = nodes[min1]->weight+nodes[min2]->weight;
        nodes[i]->left = min1;
        nodes[i]->right = min2;
        nodes[min1]->parent = i;
        nodes[min2]->parent = i;
        printf("%d(%d),%d(%d)\n", min1, nodes[min1]->weight, min2, nodes[min2]->weight);
    }
}

// TODO Huffman编码

int main() {
    int inputs[] = {3,5,7,8,11,14,23,29};
    Create(inputs, 8);
}