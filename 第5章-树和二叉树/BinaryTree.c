#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

#pragma warning(disable:4996)	// �ر�4996����


void BinaryTreeMain()
{
	linkBinaryTree tree = NULL;

	/**
	* �������˳��Ϊ��ABCDEGF
	* ���룺ABC##DE#G##F###
	*/
	printf("\n�����������У���#��ʾ�ս�㣺");
	preCreateBinaryTree(&tree);
	printf("\n�������е�Ԫ��Ϊ��");
	printBinaryTree(tree);

	printf("\n\n���������");
	preOrderTraverse(tree);
	printf("\n\n���������");
	inOrderTraverse(tree);
	printf("\n\n���������");
	postOrderTraverse(tree);

	printf("\n\n�����������Ϊ��%d", depthBinaryTree(tree));
	printf("\n\n�������Ľ������Ϊ��%d", countBinaryTree(tree));
	printf("\n\n��������Ҷ�ӽ����Ϊ��%d\n", countLeafBinaryTree(tree));
}






/*******************************************************************************************************************************
 * @description�������������������
 * @return��
 */
status preCreateBinaryTree(linkBinaryTree* tree)
{
	char ch;
	/*printf("�����������У���#��ʾ�ս�㣺");*/
	scanf("%c", &ch);
	if (ch == '#') {
		*tree = NULL;
	}
	else {
		*tree = (linkBinaryTree)malloc(sizeof(binaryNode));
		if (*tree == NULL) {
			exit(OVERFLOW);
		}
		(*tree)->data = ch;		// ���ɸ����
		preCreateBinaryTree(&(*tree)->leftChild);	// ����������
		preCreateBinaryTree(&(*tree)->rightChild);	// ����������
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description���������
 * @param��tree	��ʽ��
 */
void preOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	printf("%c", tree->data);			// ��
	preOrderTraverse(tree->leftChild);	// ��
	preOrderTraverse(tree->rightChild);	// ��
}





/*******************************************************************************************************************************
 * @description���������
 * @param��tree	��ʽ��
 */
void inOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	inOrderTraverse(tree->leftChild);	// ��
	printf("%c", tree->data);			// ��
	inOrderTraverse(tree->rightChild);	// ��
}





/*******************************************************************************************************************************
 * @description���������
 * @param��tree	��ʽ��
 */
void postOrderTraverse(linkBinaryTree tree)
{
	if (tree == NULL) {
		return;
	}
	postOrderTraverse(tree->leftChild);		// ��
	postOrderTraverse(tree->rightChild);	// ��
	printf("%c", tree->data);				// ��
}





/*******************************************************************************************************************************
 * @description�� ���ƶ�����
 * @param��tree
 * @param��copyTree
 * @return��
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
 * @description��������������
 * @param��tree
 * @return��
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
 * @description����������
 * @param��tree
 * @return��
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
 * @description����Ҷ�ӽ�������
 * @param��tree
 * @return��
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
 * @description����ӡ������
 * @param��tree
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
