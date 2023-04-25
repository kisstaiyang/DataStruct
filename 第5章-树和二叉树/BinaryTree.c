#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#pragma warning(disable:4996)	// 关闭4996警告


void BinaryTreeMain()
{
	linkBinaryTree tree = NULL;

	/**
	* 先序遍历顺序为：ABCDEGF
	* 输入：ABC##DE#G##F###
	*/
	printf("\n输入先序序列，以#表示空结点：");
	preCreateBinaryTree(&tree);
	printf("\n二叉树中的元素为：");
	printBinaryTree(tree);

	printf("\n\n先序遍历：");
	preOrderTraverse(tree);
	printf("\n\n中序遍历：");
	inOrderTraverse(tree);
	printf("\n\n后序遍历：");
	postOrderTraverse(tree);

	printf("\n\n二叉树的深度为：%d", depthBinaryTree(tree));
	printf("\n\n二叉树的结点总数为：%d", countBinaryTree(tree));
	printf("\n\n二叉树的叶子结点数为：%d\n", countLeafBinaryTree(tree));
}






/*******************************************************************************************************************************
 * @description：先序遍历创建二叉树
 * @return：
 */
status preCreateBinaryTree(linkBinaryTree* tree)
{
	char ch;
	/*printf("输入先序序列，以#表示空结点：");*/
	scanf("%c", &ch);
	if (ch == '#') {
		*tree = NULL;
	}
	else {
		*tree = (linkBinaryTree)malloc(sizeof(binaryNode));
		if (*tree == NULL) {
			exit(OVERFLOW);
		}
		(*tree)->data = ch;		// 生成根结点
		preCreateBinaryTree(&(*tree)->leftChild);	// 构造左子树
		preCreateBinaryTree(&(*tree)->rightChild);	// 构造右子树
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：先序遍历
 * @param：tree	链式树
 */
void preOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);			// 根
	preOrderTraverse(tree->leftChild);	// 左
	preOrderTraverse(tree->rightChild);	// 右
}





/*******************************************************************************************************************************
 * @description：中序遍历
 * @param：tree	链式树
 */
void inOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	inOrderTraverse(tree->leftChild);	// 左
	printf("%c", tree->data);			// 根
	inOrderTraverse(tree->rightChild);	// 右
}





/*******************************************************************************************************************************
 * @description：后序遍历
 * @param：tree	链式树
 */
void postOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	postOrderTraverse(tree->leftChild);		// 左
	postOrderTraverse(tree->rightChild);	// 右
	printf("%c", tree->data);				// 根
}





/*******************************************************************************************************************************
 * @description： 复制二叉树
 * @param：tree
 * @param：copyTree
 * @return：
 */
status copyBinaryTree(linkBinaryTree tree, linkBinaryTree* copyTree)
{
	if (copyTree == NULL) {
		tree = NULL;
	}
	else {
		*copyTree = (linkBinaryTree)malloc(sizeof(binaryNode));
		if (*copyTree == NULL) {
			exit(OVERFLOW);
		}
		(*copyTree)->data = tree->data;
		copyBinaryTree(tree->leftChild, &((*copyTree)->leftChild));
		copyBinaryTree(tree->rightChild, &((*copyTree)->rightChild));
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：计算二叉树深度
 * @param：tree
 * @return：
 */
int depthBinaryTree(linkBinaryTree tree)
{
	int depth = 0;
	if (tree != NULL) {
		int leftDepth = depthBinaryTree(tree->leftChild);
		int rightDepth = depthBinaryTree(tree->rightChild);
		depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	return depth;
}





/*******************************************************************************************************************************
 * @description：求结点总数
 * @param：tree
 * @return：
 */
int countBinaryTree(linkBinaryTree tree)
{
	int count = 0;
	if (tree != NULL) {
		count = 1 + countBinaryTree(tree->leftChild) + countBinaryTree(tree->rightChild);
	}
	return count;
}





/*******************************************************************************************************************************
 * @description：求叶子结点的总数
 * @param：tree
 * @return：
 */
int countLeafBinaryTree(linkBinaryTree tree)
{
	if (tree != NULL) {
		if (tree->leftChild == NULL && tree->rightChild == NULL) {
			return  1;
		}
		else {
			return  countLeafBinaryTree(tree->leftChild) + countLeafBinaryTree(tree->rightChild);
		}
	}
	return 0;
}






/*******************************************************************************************************************************
 * @description：打印二叉树
 * @param：tree
 */
void printBinaryTree(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	if (tree->leftChild != NULL || tree->rightChild != NULL) {
		printf("(");
		printBinaryTree(tree->leftChild);
		if (tree->rightChild != NULL) {
			printf(",");
		}
		printBinaryTree(tree->rightChild);
		printf(")");
	}
}
