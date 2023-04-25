#include <iostream>
#include "ShortestPath.h"
using namespace std;


/*******************************************************************************************************************************
 * @description：Dijkstra算法
 * @param：G
 * @param：v0
 * @param：P
 * @param：D
 * @return：
 */
status Dijkstra(adjacencyMatrixGraph* G, int v0, int* P, int* D)
{
	int final[MAX_VERTEX_NUM];	// final[i] = 1表示求得顶点vi的最短路径
	int v, w, k, min;
	for (v = 0; v < G->vexNum; v++) {	// 初始化
		final[v] = 0;	// 全部顶点初始化为未知最短路径状态
		D[v] = G->arcs[v0][v];	// 将与v0点有连线的顶点加上权值
		P[v] = 0;	// 初始化路径数组P为0
	}
	D[v0] = 0;	// v0至v0路径为0
	final[v0] = 1;	// v0至v0不需要求路径
	// 开始主循环，每次求得v0到某个v顶点的最短路径
	for (v = 1; v < G->vexNum; v++) {
		min = INFINITY;	// 当前所知离v0顶点的最近距离
		for (w = 0; w < G->vexNum; w++) {	// 寻找离v0最近的顶点
			if (!final[w] && D[w] < min) {
				k = w;
				min = D[w];	// w顶点离v0顶点更近
			}
		}
		final[k] = 1;	// 将目前找到的最近的顶点置为1
		for (w = 0; w < G->vexNum; w++) {	// 修正当前最短路径及距离
			if (!final[w] && (min + G->arcs[k][w] < D[w])) {
				D[w] = min + G->arcs[k][w];	// 修改当前路径长度
				P[w] = k;
			}
		}
	}
	return OK;
}