#pragma once

#ifndef _BFS__H_
#define _BFS__H_

#include "Graph.h"		// ͼ
#include "StatusCode.h"	// ״̬��



// ��������
static int visited_BFS[MAX_VERTEX_NUM];	// ���ʱ�־����




/*************************************��������*************************************/

// �����������
void BFS(adjacencyMatrixGraph* G, int v);

// ������
void BFSMain();


#endif // !_BFS__H_
