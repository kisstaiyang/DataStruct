#pragma once

#ifndef _SHORTESTPATH__H
#define _SHORTESTPATH__H


#include "StatusCode.h"		// ״̬��
#include "Graph.h"			// ͼ���ڽӾ���洢��ʾ





/*************************************��������*************************************/

// Dijkstra�㷨
status Dijkstra(adjacencyMatrixGraph* G, int v0, int* P, int* D);







#endif // !_SHORTESTPATH__H
