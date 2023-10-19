#include "../../main.h"

#define INF (1e9+7)
#define datatype int
#define MAX_SIZE 7
typedef struct {
    datatype vertex[MAX_SIZE]; // 顶点数组（顶点表）
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    int vertexNum, // 顶点数
    arcNum; // 边数
} AdjMatrixGraph;
// https://github.com/wangkuiwu/datastructs_and_algorithm/blob/master/pictures/graph/dijkstra/01.jpg
AdjMatrixGraph* create() {
    AdjMatrixGraph *graph = (AdjMatrixGraph *) malloc(sizeof(AdjMatrixGraph));
    graph->vertexNum = MAX_SIZE;
    graph->arcNum = 12;
    int matrix[MAX_SIZE][MAX_SIZE] = {
            {0, 12, INF, INF, INF, 16, 14},
            {12, 0, 10, INF, INF, 7, INF},
            {INF, 10, 0, 3, 5, 6, INF},
            {INF, INF, 3, 0, 4, INF, INF},
            {INF, INF, 5, 4, 0, 2, 8},
            {16, 7, 6, INF, 2, 0, 9},
            {14, INF, INF, INF, 8, 9, 0},
    };
    for (int i = 0; i < MAX_SIZE; ++ i)
        for (int j = 0; j < MAX_SIZE; ++ j)
            graph->adjMatrix[i][j] = matrix[i][j];
    int vertex[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < MAX_SIZE; ++ i)
        graph->vertex[i] = vertex[i];
    return graph;
}

// 最小生成树

// Prim算法（最小边
// https://www.cnblogs.com/skywang12345/p/3711506.html
// TODO 算法实现，优先理解思想
// O(n^2)
void Prim(AdjMatrixGraph* graph);

// Kruskal算法（最小边排序
/**
 * 1. 从小到大按权重将边排序
 * 2. 依次考察各条边，若该边的两顶点不在同一棵树中，则选取，否则舍去（避免产生回路）
 * 3. 当选取的边数为n-1时，终止（一颗节点数n的树共有n-1条边）
 * */
// TODO 算法实现，优先理解思想
// O(eloge) e为边数
void Kruskal(AdjMatrixGraph* graph);

// Dijkstra算法 - 找有权图中的所有的最短路
// https://www.cnblogs.com/skywang12345/p/3711512.html
/**
 * 1. 初始化优先队列，dist[]，path[]
 * 2. 选择起点v，依次考察相邻顶点vi，若从v->vi路径短于dist[i]，更新记录，将顶点数据入队
 * 3. 出队节点（优先队列中dist最小者），重复操作2、3,直至队空
 * */
// O(n^2)
// 真题！！！
void Dijkstra(AdjMatrixGraph *graph, int start)
{
    int dist[MAX_SIZE] = {0}; // v到其余vi的路径长度
    int path[MAX_SIZE] = {0}; // v到vi路径上的前一个顶点（前驱顶点）
    int find[MAX_SIZE] = {0}; // 标记
    // 数组初始化
    for (int i = 0; i < graph->vertexNum; ++ i) {
        path[i] = -1;
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

        // 更新当前（未获取最短路径的顶点的）最短路径和前驱顶点
        for (int j = 0; j < graph->vertexNum; ++ j) {
            // 防止溢出
            int newDist = graph->adjMatrix[k][j] == INF ? INF : (min + graph->adjMatrix[k][j]);
            // 如果距离判断没有等号，则本就与起点相邻的节点dist将不会被更新
            if (find[j] == 0 && (newDist <= dist[j])) {
                dist[j] = newDist;
                path[j] = k;
            }
        }
    }

    for (int i = 0; i < graph->vertexNum; ++ i)
        printf("index:%c, path:%c, dist:%d\n", ('A'+i), ('A'+path[i]), dist[i]);
}

// Floyd算法（三重循环、邻接矩阵迭代、全图最短路
// https://www.cnblogs.com/skywang12345/p/3711523.html
void Floyd(AdjMatrixGraph *graph) {
    // path 路径，path[i][j]=k表示，"顶点i"到"顶点j"的最短路径会经过顶点k。
    // dist 长度数组，即dist[i][j]=sum表示，"顶点i"到"顶点j"的最短路径的长度是sum。
    int dist[MAX_SIZE][MAX_SIZE], path[MAX_SIZE][MAX_SIZE];
    // 初始化
    for (int i = 0; i < graph->vertexNum; ++ i) {
        for (int j = 0; j < graph->vertexNum; ++ j) {
            dist[i][j] = graph->adjMatrix[i][j];
            path[i][j] = -1;
        }
    }

    // 每个顶点都计算一边
    for (int i = 0; i < graph->vertexNum; ++ i) {
        // 遍历整张图
        for (int r = 0; r < graph->vertexNum; ++ r) {
            for (int h = 0; h < graph->vertexNum; ++ h) {
                // 经过某点如果距离更短 则更新
                // 顶点r->顶点i + 顶点i->顶点h < 顶点r->顶点h
                if ((dist[r][i] + dist[i][h]) < dist[r][h]) {
                    dist[r][h] = dist[r][i] + dist[i][h];
                    path[r][h] = i;
                }
            }
        }
    }

    for (int i = 0; i < graph->vertexNum; ++ i) {
        for (int j = 0; j < graph->vertexNum; ++ j) printf("%d ", dist[i][j]);
        printf("\n");
    }
}

int main() {
    AdjMatrixGraph *graph = create();
    Dijkstra(graph, 3);
//    Floyd(graph);
}