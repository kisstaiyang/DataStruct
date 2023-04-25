#include <iostream>
#include <algorithm>
#include "MinSpanningTree.h"
using namespace std;


void MinSpanningTree_Main()
{
	/** 创建无向网
	*	0 6 1 5 0 0
	*   6 0 5 0 3 0
	*	1 5 0 5 6 4
	*	5 0 5 0 0 2
	*	0 3 6 0 0 6
	*	0 0 4 2 6 0
	*/

	adjacencyMatrixGraph G;
	createUDN_ByAM(&G);
	cout << "\nPrim算法：" << endl;
	MiniSpanTree_Prim(G);
	cout << "\nKruskal算法：" << endl;
	MiniSpanTree_Kruskal(G);
}





/*******************************************************************************************************************************
 * @description：Prim算法，生成最小生成树
 * @param：G
 */
void MiniSpanTree_Prim(adjacencyMatrixGraph G) {
	int min, i, j, k;
	int adjvex[MAX_VERTEX_NUM];		// 保存相关顶点下标
	int lowCost[MAX_VERTEX_NUM];	// 保存相关顶点间边的权值
	lowCost[0] = 0;					// 初始化第一个权值为0，即v0加入生成树
	adjvex[0] = 0;					// 初始化第一个顶点下标为0
	for (i = 1; i < G.vexNum; i++) {
		lowCost[i] = G.arcs[0][i];	// 将v0顶点与之有边的权值存入数组
		adjvex[i] = 0;				// 初始化都为v0的下标
	}
	for (i = 1; i < G.vexNum; i++) {
		min = maxInt;				// 初始化最小权值为∞
		j = 1; k = 0;
		while (j < G.vexNum) {
			if (lowCost[j] != 0 && lowCost[j] < min) {
				min = lowCost[j];	// 找出当前最小的
				k = j;				// 将当前最小权值的下标存入k
			}
			j++;
		}
		cout << "(" << adjvex[k] << "," << k << ")" << endl;	// 打印当前顶点边中权值最小的边
		lowCost[k] = 0;	// 将当前顶点的权值设置为0，表示此顶点已经完成任务
		for (j = 1; j < G.vexNum; j++) {
			if (lowCost[j] != 0 && G.arcs[k][j] < lowCost[j]) {
				lowCost[j] = G.arcs[k][j];	// 将v0顶点与之有边的权值存入数组
				adjvex[j] = k;	// 初始化都为v0的下标
			}
		}
	}
}







/*******************************************************************************************************************************
 * @description：sort()所需的比较函数
 * @param：a
 * @param：b
 * @return：
 */
static bool cmp(edge a, edge b) {
	return a.weight < b.weight;
}






/*******************************************************************************************************************************
 * @description：用于查找连线顶点的尾部下标
 * @param：parent
 * @param：f
 * @return：
 */
static int find(int* parent, int f) {
	while (parent[f] > 0) {
		f = parent[f];
	}
	return f;
}






/*******************************************************************************************************************************
 * @description：Kruskal算法，生成最小生成树
 * @param：G
 */
void MiniSpanTree_Kruskal(adjacencyMatrixGraph G) {
	int i, j, n, m;
	int k = 0;	// 用于统计当前生成树边数
	int adjvex[MAX_VERTEX_NUM];	// 保存相关顶点下标
	edge edges[MAX_VERTEX_NUM];	// 定义边集数组，edge的结构为{begin,end,weight}
	for (i = 0; i < G.vexNum; i++) {
		for (j = i; j < G.vexNum; j++) {
			if (G.arcs[i][j] != 0 && G.arcs[i][j] < maxInt) {
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.arcs[i][j];
				k++;
			}
		}
	}
	sort(edges, edges + G.arcNum, cmp);	// 按权值大小排序，从小到大
	for (i = 0; i < G.vexNum; i++) {
		adjvex[i] = 0;
	}
	for (i = 0; i < G.arcNum; i++) {
		n = find(adjvex, edges[i].begin);
		m = find(adjvex, edges[i].end);
		if (n != m) {
			adjvex[n] = m;
			cout << "(" << edges[i].begin << "," << edges[i].end << ")" << endl;
		}
	}
}
