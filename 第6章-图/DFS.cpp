#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"



void DFSMain()
{
	adjacencyMatrixGraph G = { 0 };
	// ͵��ֱ�����ڽӾ��󴴽�����ͼ
	G.vexs[0] = '1';
	G.vexs[1] = '2';
	G.vexs[2] = '3';
	G.vexs[3] = '4';
	G.vexs[4] = '5';
	G.vexs[5] = '6';

	/* ��������
	*  0 1 1 1 0 0
	*  1 0 0 0 1 0
	*  1 0 0 0 1 0
	*  1 0 0 0 0 1
	*  0 1 1 0 0 0
	*  0 0 0 1 0 0
	*/

	G.arcs[0][0] = 0; G.arcs[0][1] = 1; G.arcs[0][2] = 1; G.arcs[0][3] = 1; G.arcs[0][4] = 0; G.arcs[0][5] = 0;
	G.arcs[1][0] = 1; G.arcs[1][1] = 0; G.arcs[1][2] = 0; G.arcs[1][3] = 0; G.arcs[1][4] = 1; G.arcs[1][5] = 0;
	G.arcs[2][0] = 1; G.arcs[2][1] = 0; G.arcs[2][2] = 0; G.arcs[2][3] = 0; G.arcs[2][4] = 1; G.arcs[2][5] = 0;
	G.arcs[3][0] = 1; G.arcs[3][1] = 0; G.arcs[3][2] = 0; G.arcs[3][3] = 0; G.arcs[3][4] = 0; G.arcs[3][5] = 1;
	G.arcs[4][0] = 0; G.arcs[4][1] = 1; G.arcs[4][2] = 1; G.arcs[4][3] = 0; G.arcs[4][4] = 0; G.arcs[4][5] = 0;
	G.arcs[5][0] = 0; G.arcs[5][1] = 0; G.arcs[5][2] = 0; G.arcs[5][3] = 1; G.arcs[5][4] = 1; G.arcs[5][5] = 0;

	G.arcNum = 6;
	G.vexNum = 6;


	printf("�������������");
	DFS(G, 1);

}







/*******************************************************************************************************************************
 * @description�������������
 * @param��G
 * @param��v
 */
void DFS(adjacencyMatrixGraph G, int v)
{
	// ���ʶ���v
	visited_DFS[v] = TRUE;
	printf("%c ", G.vexs[v]);
	// ��v��ÿ���ڽӶ���w
	for (int w = 0; w < G.vexNum; w++)
		if (G.arcs[v][w] == 1 && !visited_DFS[w])
			DFS(G, w);

}