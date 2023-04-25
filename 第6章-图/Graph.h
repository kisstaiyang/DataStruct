#pragma once

#ifndef _GRAPH__H_
#define _GRAPH__H_

#include "StatusCode.h"		// 状态码




/*****************************图的邻接矩阵存储表示**************************************/

#define MAX_VERTEX_NUM 20	// 最大顶点数
#define maxInt 65535		// 无穷大
typedef char vertexType;	// 顶点类型
typedef int arcType;		// 边上的权值类型

typedef struct {
	vertexType vexs[MAX_VERTEX_NUM];	// 顶点集合
	arcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	// 邻接矩阵
	int vexNum, arcNum;	// 图的当前顶点数和弧数
}adjacencyMatrixGraph;







/*****************************图的邻接表存储表示**************************************/

typedef struct arcNode {
	int adjVex;					// 该弧所指向的顶点的位置
	struct arcNode* nextArc;	// 指向下一条弧的指针
	arcType info;				// 该弧的相关信息
}arcNode;


typedef struct {
	vertexType data;	// 顶点信息
	arcNode* firstArc;	// 指向第一条依附该顶点的弧的指针
}adjacencyListVertexNode;


typedef struct {
	adjacencyListVertexNode vertices[MAX_VERTEX_NUM];	// 顶点向量
	int vexNum, arcNum;	// 图的当前顶点数和弧数
}adjacencyListGraph;







/*****************************图的十字链表存储表示**************************************/

// 弧结点
typedef struct arcNode_CrossLinkedList {
	int tailVex, headVex;						// 该弧的尾和头顶点的位置
	struct arcNode_CrossLinkedList* headLink;	// 指向弧头相同的下一条弧的指针
	struct arcNode_CrossLinkedList* tailLink;	// 指向弧尾相同的下一条弧的指针
	arcType info;								// 该弧的相关信息
}arcNode_CrossLinkedList;


// 顶点结点
typedef struct vertexNode_CrossLinkedList {
	vertexType data;					// 顶点信息
	arcNode_CrossLinkedList* firstIn;	// 指向第一条入弧的指针
	arcNode_CrossLinkedList* firstOut;	// 指向第一条出弧的指针
}vertexNode_CrossLinkedList;


// 十字链表
typedef struct {
	vertexNode_CrossLinkedList xlist[MAX_VERTEX_NUM];	// 顶点向量
	int vexNum, arcNum;	// 图的当前顶点数和弧数
}crossLinkListGraph;






/*****************************图的邻接多重表存储表示**************************************/

// 弧结点
typedef struct arcNode_AdjacencyMultipleList {
	int ivex, jvex;									// 该弧依附的两个顶点的位置
	struct arcNode_AdjacencyMultipleList* ilink;	// 指向依附顶点ivex的下一条弧的指针
	struct arcNode_AdjacencyMultipleList* jlink;	// 指向依附顶点jvex的下一条弧的指针
	arcType info;									// 该弧的相关信息
	int mark;										// 该弧是否已经访问过的标志
}arcNode_AdjacencyMultipleList;



// 顶点结点
typedef struct vertexNode_AdjacencyMultipleList {
	vertexType data;	// 顶点信息
	arcNode_AdjacencyMultipleList* firstArc;	// 指向第一条依附该顶点的弧的指针
}vertexNode_AdjacencyMultipleList;


// 邻接多重表
typedef struct {
	vertexNode_AdjacencyMultipleList vNodes[MAX_VERTEX_NUM];	// 顶点向量
	int vexNum, arcNum;	// 图的当前顶点数和弧数
}adjacencyMultipleList;






/*************************************函数声明*************************************/

// 图的邻接矩阵存储表示无向图
status createUDN_ByAM(adjacencyMatrixGraph* G);

// 图的邻接表存储表示无向图
status createUDN_ByAL(adjacencyListGraph* G);



#endif // !_GRAPH__H_