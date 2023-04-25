#include <stdio.h>
#include <stdlib.h>
#include "SequenQueue.h"
#include "TreeAndForest.h"



void TreeAndForestMain()
{
	// 用孩子兄弟表示法
	childSiblingTree tree;

	// 创建树
	createTree(&tree);
	printf("\n创建的树为：");
	printTree(tree);

	// 树的先根遍历
	printf("\n\n树的先根遍历为：");
	preOrderTraverseTree(tree);

	// 树的后根遍历
	printf("\n\n树的后根遍历为：");
	postOrderTraverseTree(tree);

	// 树的层次遍历
	printf("\n\n树的层次遍历为：");
	levelOrderTraverseTree(tree);


	// 树转为二叉树
	linkBinaryTree binaryTree;
	convertTreeToBinaryTree(tree, &binaryTree);
	printf("\n\n树转为二叉树为：");
	printBinaryTree(binaryTree);


	// 二叉树转为树
	childSiblingTree tree2;
	convertBinaryTreeToTree(binaryTree, &tree2);
	printf("\n\n二叉树转为树为：");
	printTree(tree2);

	// 先根遍历
	printf("\n\n先根遍历为：");
	preOrderTraverseTree(tree2);


	printf("\n");
}





/*******************************************************************************************************************************
 * @description：将树转换为二叉树
 * @param：tree
 * @param：binaryTree
 * @return：
 */
status convertTreeToBinaryTree(childSiblingTree tree, linkBinaryTree* binaryTree)
{

	if (tree == NULL) {
		return ERROR;
	}
	// 申请根节点
	*binaryTree = (linkBinaryTree)malloc(sizeof(binaryNode));
	if (*binaryTree == NULL) {
		return OVERFLOW;
	}
	// 根节点赋值
	(*binaryTree)->data = tree->data;
	if (tree->firstChild != NULL) {
		convertTreeToBinaryTree(tree->firstChild, &((*binaryTree)->leftChild));
	}
	else {
		(*binaryTree)->leftChild = NULL;
	}
	if (tree->nextSibling != NULL) {
		convertTreeToBinaryTree(tree->nextSibling, &((*binaryTree)->rightChild));
	}
	else {
		(*binaryTree)->rightChild = NULL;
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：将二叉树转换为树
 * @param：binaryTree
 * @param：tree
 * @return：
 */
status convertBinaryTreeToTree(linkBinaryTree binaryTree, childSiblingTree* tree) {
	if (binaryTree == NULL) {
		return ERROR;
	}
	// 申请根节点
	*tree = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (*tree == NULL) {
		return OVERFLOW;
	}
	// 根节点赋值
	(*tree)->data = binaryTree->data;

	if (binaryTree->leftChild != NULL) {
		convertBinaryTreeToTree(binaryTree->leftChild, &((*tree)->firstChild));
	}
	else {
		(*tree)->firstChild = NULL;
	}

	if (binaryTree->rightChild != NULL) {
		convertBinaryTreeToTree(binaryTree->rightChild, &((*tree)->nextSibling));
	}
	else {
		(*tree)->nextSibling = NULL;
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：树的先根遍历
 * @param：tree
 */
void preOrderTraverseTree(childSiblingTree tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	preOrderTraverseTree(tree->firstChild);
	preOrderTraverseTree(tree->nextSibling);
}





/*******************************************************************************************************************************
 * @description：树的后根遍历
 * @param：tree
 */
void postOrderTraverseTree(childSiblingTree tree) {
	if (tree == NULL) {
		return;
	}
	postOrderTraverseTree(tree->firstChild);
	printf("%c", tree->data);
	postOrderTraverseTree(tree->nextSibling);
}






/*******************************************************************************************************************************
 * @description：树的层次遍历
 * @param：tree
 */
void levelOrderTraverseTree(childSiblingTree tree) {
	if (tree == NULL) {
		return;
	}
	// 申请队列
	suquenQueue queue;
	initSequenQueue(&queue);
	// 根节点入队
	enSequenQueue(&queue, tree);
	// 队列不为空
	while (queue.front != queue.rear) {
		// 出队
		childSiblingTree node;
		deSequenQueue(&queue, &node);
		// 访问
		printf("%c", node->data);

		// 同时有兄弟和孩子先将兄弟入队
		if (node->firstChild != NULL && node->nextSibling != NULL) {
			// 兄弟节点入队
			if (node->nextSibling != NULL) {
				enSequenQueue(&queue, node->nextSibling);
			}
			// 孩子节点入队
			if (node->firstChild != NULL) {
				enSequenQueue(&queue, node->firstChild);
			}

		}
		else {
			// 孩子节点入队
			if (node->firstChild != NULL) {
				enSequenQueue(&queue, node->firstChild);
			}
			// 兄弟节点入队
			if (node->nextSibling != NULL) {
				enSequenQueue(&queue, node->nextSibling);
			}
		}
	}
}





/*******************************************************************************************************************************
 * @description：创建树
 * @param：tree
 * @return：
 */
status createTree(childSiblingTree* tree) {
	// 申请根节点
	*tree = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (*tree == NULL) {
		return OVERFLOW;
	}
	// 根节点赋值
	(*tree)->data = 'A';
	(*tree)->nextSibling = NULL;
	// 申请孩子节点
	childSiblingTree childNode_B = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_B == NULL) {
		return OVERFLOW;
	}
	// 孩子节点赋值
	childNode_B->data = 'B';
	childNode_B->firstChild = NULL;
	(*tree)->firstChild = childNode_B;

	// 申请兄弟节点
	childSiblingTree siblingNode_C = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (siblingNode_C == NULL) {
		return OVERFLOW;
	}
	// 兄弟节点赋值
	siblingNode_C->data = 'C';
	childNode_B->nextSibling = siblingNode_C;

	// 申请孩子节点
	childSiblingTree childNode_D = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_D == NULL) {
		return OVERFLOW;
	}
	// 孩子节点赋值
	childNode_D->data = 'D';
	siblingNode_C->firstChild = childNode_D;
	childNode_D->firstChild = NULL;
	childNode_D->nextSibling = NULL;

	// 申请兄弟节点
	childSiblingTree siblingNode_E = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (siblingNode_E == NULL) {
		return OVERFLOW;
	}
	// 兄弟节点赋值
	siblingNode_E->data = 'E';
	siblingNode_C->nextSibling = siblingNode_E;
	siblingNode_E->firstChild = NULL;
	siblingNode_E->nextSibling = NULL;


	// 申请孩子节点
	childSiblingTree childNode_F = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_F == NULL) {
		return OVERFLOW;
	}

	return OK;
}





/*******************************************************************************************************************************
 * @description：打印树
 * @param：tree
 */
void printTree(childSiblingTree tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	if (tree->firstChild != NULL) {
		printf("(");
		printTree(tree->firstChild);
		printf(")");
	}
	if (tree->nextSibling != NULL) {
		printf(",");
		printTree(tree->nextSibling);
	}
}
