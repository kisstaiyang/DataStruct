#pragma once

#ifndef _TREEANDFOREST__H_
#define _TREEANDFOREST__H_

#include "StatusCode.h"		// ״̬��
#include "BinaryTree.h"		// linkBinaryTree




// ˫�ױ�ʾ��
#define MAX_TREE_SIZE 100

typedef struct {
	char data;		// ������
	int parent;		// ˫��λ��
}parentTreeNode;

typedef struct {
	parentTreeNode nodes[MAX_TREE_SIZE];// ˫�ױ�ʾ���Ľڵ�
	int r;								// ����λ��
	int num;							// �ڵ���
}parentTree;





// ���ӱ�ʾ��
typedef struct childTreeNode {
	char data;					// ������
	struct childTreeNode* next;	// ��һ������
}*childPtr;


typedef struct {
	char data;				// ������
	childPtr firstChild;	// ��һ������
}childLink;


typedef struct {
	childLink nodes[MAX_TREE_SIZE];	// ���ӱ�ʾ���Ľڵ�
	int r;							// ����λ��
	int num;						// �ڵ���
}childTree;





// �����ֵܱ�ʾ��
typedef struct childSiblingTreeNode {
	char data;									// ������
	struct childSiblingTreeNode* firstChild;	// ��һ������
	struct childSiblingTreeNode* nextSibling;	// ��һ���ֵ�
}childSiblingTreeNode, * childSiblingTree;



/*************************************��������*************************************/

// ����ת��Ϊ������
status convertTreeToBinaryTree(childSiblingTree tree, linkBinaryTree* binaryTree);

// ��������ת��Ϊ��
status convertBinaryTreeToTree(linkBinaryTree binaryTree, childSiblingTree* tree);

// �����ȸ�����
void preOrderTraverseTree(childSiblingTree tree);

// ���ĺ������
void postOrderTraverseTree(childSiblingTree tree);

// ���Ĳ�α���
void levelOrderTraverseTree(childSiblingTree tree);

// ������
status createTree(childSiblingTree* tree);

// ��ӡ��
void printTree(childSiblingTree tree);

// ������
void TreeAndForestMain();







#endif // !_TREEANDFOREST__H_
