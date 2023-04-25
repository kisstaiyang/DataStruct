#pragma warning(disable:4996)	// 关闭4996警告

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Graph.h"
using namespace std;




/*******************************************************************************************************************************
 * @description：返回顶点u在图G中的位置
 * @param：G
 * @param：u
 * @return：
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
 * @description：用邻接矩阵创建无向网
 * @param：G
 * @return：
 */
status createUDN_ByAM(adjacencyMatrixGraph* G)
{
	vertexType v1, v2;
	int i, j, w;
	printf("请输入顶点数和边数：");
	cin >> G->vexNum >> G->arcNum;
	printf("请输入顶点信息：");
	for (i = 0; i < G->vexNum; i++) {
		cin >> G->vexs[i];
	}

	for (i = 0; i < G->vexNum; i++) {
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = 0;
		}
	}

	for (int k = 0; k < G->arcNum; k++) {
		cout << "\n请输入一条边所依附的顶点和权值w：";
		cin >> v1 >> v2 >> w;
		i = locateVex_ByAM(G, v1);
		j = locateVex_ByAM(G, v2);
		G->arcs[i][j] = w;
		//G->arcs[j][i] = G->arcs[i][j];	// 无向图对称
	}
	return OK;
}






/*******************************************************************************************************************************
 * @description：返回顶点u在图G中的位置
 * @param：G
 * @param：u
 * @return：
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
 * @description：用邻接表创建无向网
 * @param：G
 * @return：
 */
status createUDN_ByAL(adjacencyListGraph* G)
{
	vertexType v1, v2;
	int i, j, k, w;
	arcNode* p;
	printf("请输入顶点数和边数：");
	scanf("%d,%d", &G->vexNum, &G->arcNum);
	printf("请输入顶点信息：");
	for (i = 0; i < G->vexNum; i++) {
		scanf("%c", &G->vertices[i].data);
		G->vertices[i].firstArc = NULL;
	}// 初始化邻接表结束

	for (k = 0; k < G->arcNum; k++) {
		printf("请输入一条边所依附的顶点和权值w：");
		scanf("%c,%c,%d", &v1, &v2, &w);
		i = locateVex_ByAL(G, v1);
		j = locateVex_ByAL(G, v2);
		// 采用头插法插入边结点
		p = (arcNode*)malloc(sizeof(arcNode));
		p->adjVex = j;
		p->info = w;
		p->nextArc = G->vertices[i].firstArc;
		G->vertices[i].firstArc = p;
		// 无向图对称；若为有向网下面可省略
		// 同理：只要下面的不要上面的就可以建立逆邻接表，即入度
		p = (arcNode*)malloc(sizeof(arcNode));
		p->adjVex = i;
		p->info = w;
		p->nextArc = G->vertices[j].firstArc;
		G->vertices[j].firstArc = p;
	}
	return OK;
}
