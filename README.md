# 江南大学 851考纲分析

> 本仓库仅用于个人备考资料整理

## Notice

1. C语言与Java、Go等高级语言不同，涉及到指针等变量的初始化时一定记得手动赋`NULL`防止脏数据，也防止老师随心情扣你分！
2. 涉及到线性表的题，题中若无明确是否存在头节点（首部），则可自行决定。
3. 算法题若无明确指定算法，则复杂度更低者优先。

## 内容

### 数据结构

1. 线性表
   - [线性链表](structs/01/1_LineList.c)
   - [循环链表](structs/01/1_CircList.c)
   - [双向链表](structs/01/1_DoubList.c)
   - [线性表的应用举例](structs/01/1_Usage_List.c)
2. 栈、队列、数组
   - [顺序栈](structs/02/2_SeqStack.c)
   - [链队列](structs/02/2_LinkQueue.c)
   - [循环队列](structs/02/2_SeqQueue.c)
   - [栈的应用举例](structs/02/2_Usage_Stack.c)
3. 查找和内部排序
   - [基础查找](structs/03/03_Search.c)
   - [平衡二叉树](structs/03/03_BalancedTree.c)
   - [插入排序](structs/03/03_Sort_Insert.c)
   - [交换排序](structs/03/03_Sort_Exchange.c)
   - [选择排序](structs/03/03_Sort_Select.c)
   - [归并排序](structs/03/03_Sort_Merge.c)
   - [排序的应用举例](structs/03/03_USage_Sort.c)
4. 树和图
   - [二叉树的存储结构](structs/04/4_BTree.c)
   - [二叉树的遍历](structs/04/4_BTree_Traverse.c)
   - [树的结构](structs/04/4_Tree_Struct.c)
   - [Huffman树](structs/04/4_Tree_Huffman.c)
   - [图的结构](structs/04/4_Graph.c)
   - [图的遍历](structs/04/4_Graph_Traverse.c)
   - [最小生成树](structs/04/4_Graph_MinSpanning.c)

### 计算机算法设计
1. 递归与分治策略、回溯法
   - [二分搜索](structs/03/03_Search.c)
   - [大整数乘法](algorithm/01/01_LIMultiply.c)
   - [合(归)并排序](structs/03/03_Sort_Merge.c)
   - [快速排序](structs/03/03_Sort_Exchange.c#L25)
   - [最接近点问题(二维)](algorithm/01/01_ClosestPoint.cpp)
   - 棋盘覆盖
   - 递归生成全排列
2. 贪心算法、分支限界法、动态规划
   - 矩阵连乘
   - **动态规划最优子结构证明**
   - 最长公共子序列
   - 找零问题
   - 0-1 背包问题
   - 流线作业调度
   - 最优二叉搜索树
3. 算法设计中的数据结构运用

### 程序设计基础
1. 基本数据类型、各种运算符和表达式、基本控制结构。
2. 数组的定义、数组元素的引用、数组的初始化，掌握与字符串相关的库函数。
3. 函数的定义语法，函数调用中参数的传递机制；局部和全局变量的有效范围。
4. 结构体类型变量的定义、引用、初始化方法，结构体数组的定义、初始化和 应用，共同体变量的定义和使用方法。
5. 地址和指针的基本概念，如何使用指针来处理数组、字符串以及结构体，函 数指针的基本概念以及使用。
6. 文件的定义以及对文件进行的各种操作的库函数。

## 主要知识点

> 此部分主要收录各章中出现的公式及零散重要的知识点，对应题型为简答题

- [Hash冲突处理](kpoints/Hash.md)
- [**B-树和B+树(22年真题)**](structs/03/03_B&BPlusTree.c)
- [排序算法比较表](kpoints/CompareSort.md)

## 参考资料

- [《851·江南大学硕士研究生入学考试业务课考试大纲》](docs/2024_851.pdf)
- [《C 语言程序设计》，谭浩强主编，清华大学出版社](docs/C语言程序设计.pdf)
- [《数据结构（C 语言版）》，严蔚敏主编，清华大学出版社](docs/数据结构(C语言).pdf)
- [《计算机算法设计与分析》，王晓东主编，电子工业出版社](docs/计算机算法设计与分析.pdf)
- 《851算法与程序设计--重难点讲义》`by研学长`
- 《851算法与程序设计--真题及答案》`by研学长`
