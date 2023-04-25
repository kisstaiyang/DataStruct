#pragma once

#ifndef _TREEANDFOREST__H_
#define _TREEANDFOREST__H_

#include "StatusCode.h"		// 状态码
#include "BinaryTree.h"		// linkBinaryTree




// 双亲表示法
#define MAX_TREE_SIZE 100

typedef struct {
	char data;		// 数据域
	int parent;		// 双亲位置
}parentTreeNode;

typedef struct {
	parentTreeNode nodes[MAX_TREE_SIZE];// 双亲表示法的节点
	int r;								// 根的位置
	int num;							// 节点数
}parentTree;





// 孩子表示法
typedef struct childTreeNode {
	char data;					// 数据域
	struct childTreeNode* next;	// 第一个孩子
}*childPtr;


typedef struct {
	char data;				// 数据域
	childPtr firstChild;	// 第一个孩子
}childLink;


typedef struct {
	childLink nodes[MAX_TREE_SIZE];	// 孩子表示法的节点
	int r;							// 根的位置
	int num;						// 节点数
}childTree;





// 孩子兄弟表示法
typedef struct childSiblingTreeNode {
	char data;									// 数据域
	struct childSiblingTreeNode* firstChild;	// 第一个孩子
	struct childSiblingTreeNode* nextSibling;	// 下一个兄弟
}childSiblingTreeNode, * childSiblingTree;



/*************************************函数声明*************************************/

// 将树转换为二叉树
status convertTreeToBinaryTree(childSiblingTree tree, linkBinaryTree* binaryTree);

// 将二叉树转换为树
status convertBinaryTreeToTree(linkBinaryTree binaryTree, childSiblingTree* tree);

// 树的先根遍历
void preOrderTraverseTree(childSiblingTree tree);

// 树的后根遍历
void postOrderTraverseTree(childSiblingTree tree);

// 树的层次遍历
void levelOrderTraverseTree(childSiblingTree tree);

// 创建树
status createTree(childSiblingTree* tree);

// 打印树
void printTree(childSiblingTree tree);

// 主函数
void TreeAndForestMain();







#endif // !_TREEANDFOREST__H_
