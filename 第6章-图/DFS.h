#pragma once

#ifndef _DFS__H_
#define _DFS__H_

#include "Graph.h"		// ͼ
#include "StatusCode.h"	// ״̬��



// ��������
static int visited_DFS[MAX_VERTEX_NUM] = { 0 };





/*************************************��������*************************************/

// �����������
void DFS(adjacencyMatrixGraph G, int v);

// �����������������
void DFSMain();



#endif // !_DFS__H_
