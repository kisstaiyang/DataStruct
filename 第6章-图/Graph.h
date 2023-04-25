#pragma once

#ifndef _GRAPH__H_
#define _GRAPH__H_

#include "StatusCode.h"		// ״̬��




/*****************************ͼ���ڽӾ���洢��ʾ**************************************/

#define MAX_VERTEX_NUM 20	// ��󶥵���
#define maxInt 65535		// �����
typedef char vertexType;	// ��������
typedef int arcType;		// ���ϵ�Ȩֵ����

typedef struct {
	vertexType vexs[MAX_VERTEX_NUM];	// ���㼯��
	arcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	// �ڽӾ���
	int vexNum, arcNum;	// ͼ�ĵ�ǰ�������ͻ���
}adjacencyMatrixGraph;







/*****************************ͼ���ڽӱ�洢��ʾ**************************************/

typedef struct arcNode {
	int adjVex;					// �û���ָ��Ķ����λ��
	struct arcNode* nextArc;	// ָ����һ������ָ��
	arcType info;				// �û��������Ϣ
}arcNode;


typedef struct {
	vertexType data;	// ������Ϣ
	arcNode* firstArc;	// ָ���һ�������ö���Ļ���ָ��
}adjacencyListVertexNode;


typedef struct {
	adjacencyListVertexNode vertices[MAX_VERTEX_NUM];	// ��������
	int vexNum, arcNum;	// ͼ�ĵ�ǰ�������ͻ���
}adjacencyListGraph;







/*****************************ͼ��ʮ������洢��ʾ**************************************/

// �����
typedef struct arcNode_CrossLinkedList {
	int tailVex, headVex;						// �û���β��ͷ�����λ��
	struct arcNode_CrossLinkedList* headLink;	// ָ��ͷ��ͬ����һ������ָ��
	struct arcNode_CrossLinkedList* tailLink;	// ָ��β��ͬ����һ������ָ��
	arcType info;								// �û��������Ϣ
}arcNode_CrossLinkedList;


// ������
typedef struct vertexNode_CrossLinkedList {
	vertexType data;					// ������Ϣ
	arcNode_CrossLinkedList* firstIn;	// ָ���һ���뻡��ָ��
	arcNode_CrossLinkedList* firstOut;	// ָ���һ��������ָ��
}vertexNode_CrossLinkedList;


// ʮ������
typedef struct {
	vertexNode_CrossLinkedList xlist[MAX_VERTEX_NUM];	// ��������
	int vexNum, arcNum;	// ͼ�ĵ�ǰ�������ͻ���
}crossLinkListGraph;






/*****************************ͼ���ڽӶ��ر�洢��ʾ**************************************/

// �����
typedef struct arcNode_AdjacencyMultipleList {
	int ivex, jvex;									// �û����������������λ��
	struct arcNode_AdjacencyMultipleList* ilink;	// ָ����������ivex����һ������ָ��
	struct arcNode_AdjacencyMultipleList* jlink;	// ָ����������jvex����һ������ָ��
	arcType info;									// �û��������Ϣ
	int mark;										// �û��Ƿ��Ѿ����ʹ��ı�־
}arcNode_AdjacencyMultipleList;



// ������
typedef struct vertexNode_AdjacencyMultipleList {
	vertexType data;	// ������Ϣ
	arcNode_AdjacencyMultipleList* firstArc;	// ָ���һ�������ö���Ļ���ָ��
}vertexNode_AdjacencyMultipleList;


// �ڽӶ��ر�
typedef struct {
	vertexNode_AdjacencyMultipleList vNodes[MAX_VERTEX_NUM];	// ��������
	int vexNum, arcNum;	// ͼ�ĵ�ǰ�������ͻ���
}adjacencyMultipleList;






/*************************************��������*************************************/

// ͼ���ڽӾ���洢��ʾ����ͼ
status createUDN_ByAM(adjacencyMatrixGraph* G);

// ͼ���ڽӱ�洢��ʾ����ͼ
status createUDN_ByAL(adjacencyListGraph* G);



#endif // !_GRAPH__H_