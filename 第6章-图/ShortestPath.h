#pragma once

#ifndef _SHORTESTPATH__H
#define _SHORTESTPATH__H


#include "StatusCode.h"		// 状态码
#include "Graph.h"			// 图的邻接矩阵存储表示





/*************************************函数声明*************************************/

// Dijkstra算法
status Dijkstra(adjacencyMatrixGraph* G, int v0, int* P, int* D);







#endif // !_SHORTESTPATH__H
