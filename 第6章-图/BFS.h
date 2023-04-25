#pragma once

#ifndef _BFS__H_
#define _BFS__H_

#include "Graph.h"		// 图
#include "StatusCode.h"	// 状态码



// 辅助数组
static int visited_BFS[MAX_VERTEX_NUM];	// 访问标志数组




/*************************************函数声明*************************************/

// 广度优先搜索
void BFS(adjacencyMatrixGraph* G, int v);

// 主函数
void BFSMain();


#endif // !_BFS__H_
