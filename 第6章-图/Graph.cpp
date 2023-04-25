#pragma warning(disable:4996)	// �ر�4996����

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Graph.h"
using namespace std;




/*******************************************************************************************************************************
 * @description�����ض���u��ͼG�е�λ��
 * @param��G
 * @param��u
 * @return��
 */
int locateVex_ByAM(adjacencyMatrixGraph* G, vertexType u)
{
	for (int i = 0; i < G->vexNum; i++) {
		if (G->vexs[i] == u) {
			return i;
		}
	}
	return -1;
}






/*******************************************************************************************************************************
 * @description�����ڽӾ��󴴽�������
 * @param��G
 * @return��
 */
status createUDN_ByAM(adjacencyMatrixGraph* G)
{
	vertexType v1, v2;
	int i, j, w;
	printf("�����붥�����ͱ�����");
	cin >> G->vexNum >> G->arcNum;
	printf("�����붥����Ϣ��");
	for (i = 0; i < G->vexNum; i++) {
		cin >> G->vexs[i];
	}

	for (i = 0; i < G->vexNum; i++) {
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = 0;
		}
	}

	for (int k = 0; k < G->arcNum; k++) {
		cout << "\n������һ�����������Ķ����Ȩֵw��";
		cin >> v1 >> v2 >> w;
		i = locateVex_ByAM(G, v1);
		j = locateVex_ByAM(G, v2);
		G->arcs[i][j] = w;
		//G->arcs[j][i] = G->arcs[i][j];	// ����ͼ�Գ�
	}
	return OK;
}






/*******************************************************************************************************************************
 * @description�����ض���u��ͼG�е�λ��
 * @param��G
 * @param��u
 * @return��
 */
int locateVex_ByAL(adjacencyListGraph* G, vertexType u)
{
	int i;
	for (i = 0; i < G->vexNum; i++) {
		if (G->vertices[i].data == u) {
			return i;
		}
	}
	return -1;
}






/*******************************************************************************************************************************
 * @description�����ڽӱ���������
 * @param��G
 * @return��
 */
status createUDN_ByAL(adjacencyListGraph* G)
{
	vertexType v1, v2;
	int i, j, k, w;
	arcNode* p;
	printf("�����붥�����ͱ�����");
	scanf("%d,%d", &G->vexNum, &G->arcNum);
	printf("�����붥����Ϣ��");
	for (i = 0; i < G->vexNum; i++) {
		scanf("%c", &G->vertices[i].data);
		G->vertices[i].firstArc = NULL;
	}// ��ʼ���ڽӱ����

	for (k = 0; k < G->arcNum; k++) {
		printf("������һ�����������Ķ����Ȩֵw��");
		scanf("%c,%c,%d", &v1, &v2, &w);
		i = locateVex_ByAL(G, v1);
		j = locateVex_ByAL(G, v2);
		// ����ͷ�巨����߽��
		p = (arcNode*)malloc(sizeof(arcNode));
		p->adjVex = j;
		p->info = w;
		p->nextArc = G->vertices[i].firstArc;
		G->vertices[i].firstArc = p;
		// ����ͼ�Գƣ���Ϊ�����������ʡ��
		// ͬ��ֻҪ����Ĳ�Ҫ����ľͿ��Խ������ڽӱ������
		p = (arcNode*)malloc(sizeof(arcNode));
		p->adjVex = i;
		p->info = w;
		p->nextArc = G->vertices[j].firstArc;
		G->vertices[j].firstArc = p;
	}
	return OK;
}
