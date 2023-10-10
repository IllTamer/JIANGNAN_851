#include "../../main.h"

#define datatype int
#define MAX_SIZE 64

// 邻接矩阵 -> 表示图
typedef struct {
    datatype vertex[MAX_SIZE]; // 顶点数组（顶点表）
    // 邻接矩阵
    // - 无向图：邻接为1,否则为0
    // - 有向图：w有连接，i=j时为0,无连接为无穷️
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    int vertexNum, // 顶点数
    arcNum; // 边数
} AdjMatrixGraph;

// 邻接表 -> 表示图
// 边表节点
typedef struct ArcNode {
    int adjVex; // 储存该顶点在顶点表中下标
    int weight; // 权重
    struct ArcNode *next; // 指向下一个邻接点
} ArcNode;
// 顶点表节点
typedef struct VertexNode {
    datatype data; // 储存顶点数据
    ArcNode  *firstArc; // 边表头指针
} VertexNode;
// 邻接表
typedef struct {
    VertexNode *adjList[MAX_SIZE]; //邻接表
    int vertexNum, // 图的顶点数
    arcNum; // 图的边数
} AdjListGraph;