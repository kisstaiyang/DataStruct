#include <iostream>
#include "ShortestPath.h"
using namespace std;


/*******************************************************************************************************************************
 * @description��Dijkstra�㷨
 * @param��G
 * @param��v0
 * @param��P
 * @param��D
 * @return��
 */
status Dijkstra(adjacencyMatrixGraph* G, int v0, int* P, int* D)
{
	int final[MAX_VERTEX_NUM];	// final[i] = 1��ʾ��ö���vi�����·��
	int v, w, k, min;
	for (v = 0; v < G->vexNum; v++) {	// ��ʼ��
		final[v] = 0;	// ȫ�������ʼ��Ϊδ֪���·��״̬
		D[v] = G->arcs[v0][v];	// ����v0�������ߵĶ������Ȩֵ
		P[v] = 0;	// ��ʼ��·������PΪ0
	}
	D[v0] = 0;	// v0��v0·��Ϊ0
	final[v0] = 1;	// v0��v0����Ҫ��·��
	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
	for (v = 1; v < G->vexNum; v++) {
		min = INFINITY;	// ��ǰ��֪��v0������������
		for (w = 0; w < G->vexNum; w++) {	// Ѱ����v0����Ķ���
			if (!final[w] && D[w] < min) {
				k = w;
				min = D[w];	// w������v0�������
			}
		}
		final[k] = 1;	// ��Ŀǰ�ҵ�������Ķ�����Ϊ1
		for (w = 0; w < G->vexNum; w++) {	// ������ǰ���·��������
			if (!final[w] && (min + G->arcs[k][w] < D[w])) {
				D[w] = min + G->arcs[k][w];	// �޸ĵ�ǰ·������
				P[w] = k;
			}
		}
	}
	return OK;
}