#pragma once

#ifndef _MINSPANNINGTREE___H_
#define _MINSPANNINGTREE___H_


#include "StatusCode.h"		// 状态码
#include "Graph.h"			// 图的邻接矩阵存储表示





// Kruskal算法所需edge结构
typedef struct {
	int begin;
	int end;
	int weight;
}edge;





/*************************************函数声明*************************************/

// Prim算法
void MiniSpanTree_Prim(adjacencyMatrixGraph G);

// Kruskal算法
void MiniSpanTree_Kruskal(adjacencyMatrixGraph G);

// 主函数
void MinSpanningTree_Main();


#endif // !_MINSPANNINGTREE___H_




