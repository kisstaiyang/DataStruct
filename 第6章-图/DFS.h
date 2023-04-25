#pragma once

#ifndef _DFS__H_
#define _DFS__H_

#include "Graph.h"		// 图
#include "StatusCode.h"	// 状态码



// 辅助数组
static int visited_DFS[MAX_VERTEX_NUM] = { 0 };





/*************************************函数声明*************************************/

// 深度优先搜索
void DFS(adjacencyMatrixGraph G, int v);

// 深度优先搜索主函数
void DFSMain();



#endif // !_DFS__H_
