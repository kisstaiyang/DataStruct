#include <iostream>
#include <queue>		// 队列
#include "BFS.h"		// 广度优先搜索
using namespace std;


void BFSMain()
{
	adjacencyMatrixGraph G;
	createUDN_ByAM(&G);
	cout << "\n广度优先搜索：";
	BFS(&G, 0);

	/**	0 1 1 0 0 0 0 0
		1 0 0 1 1 0 0 0
		1 0 0 0 0 1 1 0
		0 1 0 0 0 0 0 1
		0 1 0 0 0 0 0 1
		0 0 1 0 0 0 1 0
		0 0 1 0 0 1 0 0
		0 0 0 1 1 0 0 0 **/

}





/*******************************************************************************************************************************
 * @description：查找第一个邻接点
 * @param：G
 * @param：v
 * @return：
 */
static int firstAdjVex(adjacencyMatrixGraph* G, int v)
{
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[v][i] != 0) {
			return i;
		}
	}
	return -1;
}





/*******************************************************************************************************************************
 * @description：查找下一个邻接点
 * @param：G
 * @param：v
 * @param：w
 * @return：
 */
static int nextAdjVex(adjacencyMatrixGraph* G, int v, int w)
{
	for (int i = w + 1; i < G->vexNum; i++) {
		if (G->arcs[v][i] != 0) {
			return i;
		}
	}
	return -1;
}





/*******************************************************************************************************************************
 * @description：广度优先搜索
 * @param：G
 * @param：v
 */
void BFS(adjacencyMatrixGraph* G, int v)
{
	int w;
	// 初始化辅助数组
	for (int i = 0; i < G->vexNum; i++) {
		visited_BFS[i] = 0;
	}
	// 初始化队列
	queue<int> Q;
	// 访问顶点v
	printf("%c ", G->vexs[v]);
	visited_BFS[v] = 1;
	// 顶点v入队
	Q.push(v);
	// 队列非空
	while (!Q.empty()) {
		// 出队
		v = Q.front();
		Q.pop();
		// 查找v的邻接点
		for (w = firstAdjVex(G, v); w >= 0; w = nextAdjVex(G, v, w)) {
			// 未访问过
			if (!visited_BFS[w]) {
				// 访问顶点w
				printf("%c ", G->vexs[w]);
				visited_BFS[w] = 1;
				// 顶点w入队
				Q.push(w);
			}
		}
	}
}
