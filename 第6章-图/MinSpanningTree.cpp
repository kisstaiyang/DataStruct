#include <iostream>
#include <algorithm>
#include "MinSpanningTree.h"
using namespace std;


void MinSpanningTree_Main()
{
	/** ����������
	*	0 6 1 5 0 0
	*   6 0 5 0 3 0
	*	1 5 0 5 6 4
	*	5 0 5 0 0 2
	*	0 3 6 0 0 6
	*	0 0 4 2 6 0
	*/

	adjacencyMatrixGraph G;
	createUDN_ByAM(&G);
	cout << "\nPrim�㷨��" << endl;
	MiniSpanTree_Prim(G);
	cout << "\nKruskal�㷨��" << endl;
	MiniSpanTree_Kruskal(G);
}





/*******************************************************************************************************************************
 * @description��Prim�㷨��������С������
 * @param��G
 */
void MiniSpanTree_Prim(adjacencyMatrixGraph G) {
	int min, i, j, k;
	int adjvex[MAX_VERTEX_NUM];		// ������ض����±�
	int lowCost[MAX_VERTEX_NUM];	// ������ض����ߵ�Ȩֵ
	lowCost[0] = 0;					// ��ʼ����һ��ȨֵΪ0����v0����������
	adjvex[0] = 0;					// ��ʼ����һ�������±�Ϊ0
	for (i = 1; i < G.vexNum; i++) {
		lowCost[i] = G.arcs[0][i];	// ��v0������֮�бߵ�Ȩֵ��������
		adjvex[i] = 0;				// ��ʼ����Ϊv0���±�
	}
	for (i = 1; i < G.vexNum; i++) {
		min = maxInt;				// ��ʼ����СȨֵΪ��
		j = 1; k = 0;
		while (j < G.vexNum) {
			if (lowCost[j] != 0 && lowCost[j] < min) {
				min = lowCost[j];	// �ҳ���ǰ��С��
				k = j;				// ����ǰ��СȨֵ���±����k
			}
			j++;
		}
		cout << "(" << adjvex[k] << "," << k << ")" << endl;	// ��ӡ��ǰ�������Ȩֵ��С�ı�
		lowCost[k] = 0;	// ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
		for (j = 1; j < G.vexNum; j++) {
			if (lowCost[j] != 0 && G.arcs[k][j] < lowCost[j]) {
				lowCost[j] = G.arcs[k][j];	// ��v0������֮�бߵ�Ȩֵ��������
				adjvex[j] = k;	// ��ʼ����Ϊv0���±�
			}
		}
	}
}







/*******************************************************************************************************************************
 * @description��sort()����ıȽϺ���
 * @param��a
 * @param��b
 * @return��
 */
static bool cmp(edge a, edge b) {
	return a.weight < b.weight;
}






/*******************************************************************************************************************************
 * @description�����ڲ������߶����β���±�
 * @param��parent
 * @param��f
 * @return��
 */
static int find(int* parent, int f) {
	while (parent[f] > 0) {
		f = parent[f];
	}
	return f;
}






/*******************************************************************************************************************************
 * @description��Kruskal�㷨��������С������
 * @param��G
 */
void MiniSpanTree_Kruskal(adjacencyMatrixGraph G) {
	int i, j, n, m;
	int k = 0;	// ����ͳ�Ƶ�ǰ����������
	int adjvex[MAX_VERTEX_NUM];	// ������ض����±�
	edge edges[MAX_VERTEX_NUM];	// ����߼����飬edge�ĽṹΪ{begin,end,weight}
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
	sort(edges, edges + G.arcNum, cmp);	// ��Ȩֵ��С���򣬴�С����
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
