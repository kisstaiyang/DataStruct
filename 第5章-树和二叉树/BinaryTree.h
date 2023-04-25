#pragma once

#ifndef _SEQUENBINARYTREE__H_
#define _SEQUENBINARYTREE__H_


#include "StatusCode.h"		// ״̬��


#define MAXSQTREESIZE 100	// ���������������


// ��������˳��洢
typedef struct {
	char data[MAXSQTREESIZE];	// ������������
	int last;					// �����������һ��Ԫ�ص��±�
}sequenBinaryTree;



// ����������ʽ�洢
typedef struct BinaryNode {
	char data;							// ������
	struct BinaryNode* leftChild;		// ����
	struct BinaryNode* rightChild;		// �Һ���
}binaryNode, * linkBinaryTree;



// ����������
typedef struct threadedBinaryTreeNode {
	char data;									// ������
	int leftTag;								// ���־
	struct threadedBinaryTreeNode* leftChild;	// ����
	int rightTag;								// �ұ�־
	struct threadedBinaryTreeNode* rightChild;	// �Һ���
}threadedBinaryTreeNode, * threadedBinaryTree;;




/*************************************��������*************************************/

// �����������������
status preCreateBinaryTree(linkBinaryTree* tree);

// �������
void preOrderTraverse(linkBinaryTree tree);

// �������
void inOrderTraverse(linkBinaryTree tree);

// �������
void postOrderTraverse(linkBinaryTree tree);

// ���ƶ�����
status copyBinaryTree(linkBinaryTree tree, linkBinaryTree* copyTree);

// ������������
int depthBinaryTree(linkBinaryTree tree);

// ��������
int countBinaryTree(linkBinaryTree tree);

// ��Ҷ�ӽ����
int countLeafBinaryTree(linkBinaryTree tree);

// ��ӡ������
void printBinaryTree(linkBinaryTree tree);

// ������
void BinaryTreeMain();



#endif // !_SEQUENBINARYTREE__H_
