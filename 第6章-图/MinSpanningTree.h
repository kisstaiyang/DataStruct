#pragma once

#ifndef _MINSPANNINGTREE___H_
#define _MINSPANNINGTREE___H_


#include "StatusCode.h"		// ״̬��
#include "Graph.h"			// ͼ���ڽӾ���洢��ʾ





// Kruskal�㷨����edge�ṹ
typedef struct {
	int begin;
	int end;
	int weight;
}edge;





/*************************************��������*************************************/

// Prim�㷨
void MiniSpanTree_Prim(adjacencyMatrixGraph G);

// Kruskal�㷨
void MiniSpanTree_Kruskal(adjacencyMatrixGraph G);

// ������
void MinSpanningTree_Main();


#endif // !_MINSPANNINGTREE___H_




