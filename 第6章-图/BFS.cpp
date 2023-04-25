#include <iostream>
#include <queue>		// ����
#include "BFS.h"		// �����������
using namespace std;


void BFSMain()
{
	adjacencyMatrixGraph G;
	createUDN_ByAM(&G);
	cout << "\n�������������";
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
 * @description�����ҵ�һ���ڽӵ�
 * @param��G
 * @param��v
 * @return��
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
 * @description��������һ���ڽӵ�
 * @param��G
 * @param��v
 * @param��w
 * @return��
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
 * @description�������������
 * @param��G
 * @param��v
 */
void BFS(adjacencyMatrixGraph* G, int v)
{
	int w;
	// ��ʼ����������
	for (int i = 0; i < G->vexNum; i++) {
		visited_BFS[i] = 0;
	}
	// ��ʼ������
	queue<int> Q;
	// ���ʶ���v
	printf("%c ", G->vexs[v]);
	visited_BFS[v] = 1;
	// ����v���
	Q.push(v);
	// ���зǿ�
	while (!Q.empty()) {
		// ����
		v = Q.front();
		Q.pop();
		// ����v���ڽӵ�
		for (w = firstAdjVex(G, v); w >= 0; w = nextAdjVex(G, v, w)) {
			// δ���ʹ�
			if (!visited_BFS[w]) {
				// ���ʶ���w
				printf("%c ", G->vexs[w]);
				visited_BFS[w] = 1;
				// ����w���
				Q.push(w);
			}
		}
	}
}
