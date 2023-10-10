#include "../../main.h"

#define datatype int
#define MAX_SIZE 8
typedef struct {
    datatype vertex[MAX_SIZE]; // 顶点数组（顶点表）
    // 邻接矩阵
    // - 无向图：邻接为1,否则为0
    // - 有向图：w有连接，i=j时为0,无连接为无穷️
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    int vertexNum, // 顶点数
    arcNum; // 边数
} AdjMatrixGraph;
// 全局数组，标记放问过的节点
int visited[MAX_SIZE] = {0};
// 无向图：https://img-blog.csdn.net/20161121123207864
// \ 1 2 3 4 5 6 7 8
// 1 0 1 1 0 0 0 0 0
// 2 1 0 0 1 1 0 0 0
// 3 1 0 0 0 0 1 1 0
// 4 0 1 0 0 0 0 0 1
// 5 0 1 0 0 0 0 0 1
// 6 0 0 1 0 0 0 0 1
// 7 0 0 1 0 0 0 0 1
// 8 0 0 0 1 1 1 1 0
AdjMatrixGraph* create() {
    AdjMatrixGraph *graph = (AdjMatrixGraph *) malloc(sizeof(AdjMatrixGraph));
    graph->vertexNum = 8;
    graph->arcNum = 10;
    int matrix[8][8] = {
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 1, 1, 0},
            {0, 1, 0, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 1, 1, 1, 0}
    };
    for (int i = 0; i < 8; ++ i)
        for (int j = 0; j < 8; ++ j)
            graph->adjMatrix[i][j] = matrix[i][j];
    int vertex[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 8; ++ i)
        graph->vertex[i] = vertex[i];
    return graph;
}

// 深度优先遍历（dfs
/**
 * 1. 访问顶点v
 * 2. 从v的未被访问的邻接点中选取一个顶点w
 * 3. 重复1、2（直至图中所有和v路径相通的顶点都被访问到）
 * */
void dfs(AdjMatrixGraph *graph, int i)
{
    printf("%d->", graph->vertex[i]);
    visited[i] = 1;
    for (int j = 0; j < graph->vertexNum; ++ j) {
        // 当前节点索引：i,目标节点索引：j
        if (graph->adjMatrix[i][j] == 1 && visited[j] == 0)
            dfs(graph, j);
    }
}

// 广度优先遍历（bfs
/**
 * 1. 访问顶点v
 * 2. 依次访问v的各个未被访问的邻接点v1、v2...
 * 3. 分别从v1、v2...出发依次访问它们未被访问的邻接点（直至图中所有和v路径相通的顶点都被访问到）
 * */
// 相当于层序遍历，借助队列，自行实现
void bfs(AdjMatrixGraph *graph, int i);

int main()
{
    AdjMatrixGraph *graph = create();
    dfs(graph, 0);
    printf("\n");
}