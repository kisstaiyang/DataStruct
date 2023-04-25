#pragma once

#ifndef _SEQUENBINARYTREE__H_
#define _SEQUENBINARYTREE__H_


#include "StatusCode.h"		// 状态码


#define MAXSQTREESIZE 100	// 二叉树的最大容量


// 二叉树的顺序存储
typedef struct {
	char data[MAXSQTREESIZE];	// 二叉树的数据
	int last;					// 二叉树的最后一个元素的下标
}sequenBinaryTree;



// 二叉树的链式存储
typedef struct BinaryNode {
	char data;							// 数据域
	struct BinaryNode* leftChild;		// 左孩子
	struct BinaryNode* rightChild;		// 右孩子
}binaryNode, * linkBinaryTree;



// 线索二叉树
typedef struct threadedBinaryTreeNode {
	char data;									// 数据域
	int leftTag;								// 左标志
	struct threadedBinaryTreeNode* leftChild;	// 左孩子
	int rightTag;								// 右标志
	struct threadedBinaryTreeNode* rightChild;	// 右孩子
}threadedBinaryTreeNode, * threadedBinaryTree;;




/*************************************函数声明*************************************/

// 先序遍历创建二叉树
status preCreateBinaryTree(linkBinaryTree* tree);

// 先序遍历
void preOrderTraverse(linkBinaryTree tree);

// 中序遍历
void inOrderTraverse(linkBinaryTree tree);

// 后序遍历
void postOrderTraverse(linkBinaryTree tree);

// 复制二叉树
status copyBinaryTree(linkBinaryTree tree, linkBinaryTree* copyTree);

// 计算二叉树深度
int depthBinaryTree(linkBinaryTree tree);

// 求结点总数
int countBinaryTree(linkBinaryTree tree);

// 求叶子结点数
int countLeafBinaryTree(linkBinaryTree tree);

// 打印二叉树
void printBinaryTree(linkBinaryTree tree);

// 主函数
void BinaryTreeMain();



#endif // !_SEQUENBINARYTREE__H_
