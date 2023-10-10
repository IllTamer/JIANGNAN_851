#include "../../main.h"

#define INF (1e9+7)
#define datatype int
#define MAX_SIZE 8
typedef struct {
    datatype vertex[MAX_SIZE]; // 顶点数组（顶点表）
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    int vertexNum, // 顶点数
    arcNum; // 边数
} AdjMatrixGraph;
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

// 最小生成树

// Prim算法（最小边
// https://www.cnblogs.com/skywang12345/p/3711506.html
// TODO 算法实现，优先理解思想
void Prim(AdjMatrixGraph* graph);

// Kruskal算法
/**
 * 1. 从小到大按权重将边排序
 * 2. 依次考察各条边，若该边的两顶点不在同一棵树中，则选取，否则舍去（避免产生回路）
 * 3. 当选取的边数为n-1时，终止（一颗节点数n的树共有n-1条边）
 * */
// TODO 算法实现，优先理解思想
void Kruskal(AdjMatrixGraph* graph);

// Dijkstra算法 - 找有权图中的所有的最短路
// https://www.cnblogs.com/skywang12345/p/3711512.html
/**
 * 1. 初始化优先队列，dist[]，path[]
 * 2. 选择起点v，依次考察相邻顶点vi，若从v->vi路径短于dist[i]，更新记录，将顶点数据入队
 * 3. 出队节点（优先队列中dist最小者），重复操作2、3,直至队空
 * */
// 真题！！！
void Dijkstra(AdjMatrixGraph *graph, int start)
{
    int dist[MAX_SIZE]; // v到其余vi的路径长度
    int path[MAX_SIZE]; // v到vi路径上的前一个顶点（前驱顶点）
    int find[MAX_SIZE]; // 标记
    // 数组初始化
    for (int i = 0; i < graph->vertexNum; ++ i) {
        path[i] = 0;
        // 最短路径初始化为其余点到起点的长度（断开为无穷）
        dist[i] = graph->adjMatrix[start][i];
    }
    // 起点初始化
    dist[start] = 0;

    // 遍历总次数固定
    for (int i = 0; i < graph->vertexNum; ++ i) {
        int min = INF, k;
        // 寻找当前最小的路径
        // 在未获取最短路径的顶点中，找到离vs最近的顶点(k)
        for (int j = 0; j < graph->vertexNum; ++ j) {
            if (find[j] == 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        find[k] = 1;

        // 更新当前最短路径和前驱顶点
        for (int j = 0; j < graph->vertexNum; ++ j) {
            // 防止溢出
            int newDist = graph->adjMatrix[k][j] == INF ? INF : (min + graph->adjMatrix[k][j]);
            if (find[j] == 0 && (newDist < dist[j])) {
                dist[j] = newDist;
                path[j] = k;
            }
        }
    }
}



// Floyd算法

int main() {

}