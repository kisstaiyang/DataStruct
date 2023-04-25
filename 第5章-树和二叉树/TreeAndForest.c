#include <stdio.h>
#include <stdlib.h>
#include "SequenQueue.h"
#include "TreeAndForest.h"



void TreeAndForestMain()
{
	// �ú����ֵܱ�ʾ��
	childSiblingTree tree;

	// ������
	createTree(&tree);
	printf("\n��������Ϊ��");
	printTree(tree);

	// �����ȸ�����
	printf("\n\n�����ȸ�����Ϊ��");
	preOrderTraverseTree(tree);

	// ���ĺ������
	printf("\n\n���ĺ������Ϊ��");
	postOrderTraverseTree(tree);

	// ���Ĳ�α���
	printf("\n\n���Ĳ�α���Ϊ��");
	levelOrderTraverseTree(tree);


	// ��תΪ������
	linkBinaryTree binaryTree;
	convertTreeToBinaryTree(tree, &binaryTree);
	printf("\n\n��תΪ������Ϊ��");
	printBinaryTree(binaryTree);


	// ������תΪ��
	childSiblingTree tree2;
	convertBinaryTreeToTree(binaryTree, &tree2);
	printf("\n\n������תΪ��Ϊ��");
	printTree(tree2);

	// �ȸ�����
	printf("\n\n�ȸ�����Ϊ��");
	preOrderTraverseTree(tree2);


	printf("\n");
}





/*******************************************************************************************************************************
 * @description������ת��Ϊ������
 * @param��tree
 * @param��binaryTree
 * @return��
 */
status convertTreeToBinaryTree(childSiblingTree tree, linkBinaryTree* binaryTree)
{

	if (tree == NULL) {
		return ERROR;
	}
	// ������ڵ�
	*binaryTree = (linkBinaryTree)malloc(sizeof(binaryNode));
	if (*binaryTree == NULL) {
		return OVERFLOW;
	}
	// ���ڵ㸳ֵ
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
 * @description����������ת��Ϊ��
 * @param��binaryTree
 * @param��tree
 * @return��
 */
status convertBinaryTreeToTree(linkBinaryTree binaryTree, childSiblingTree* tree) {
	if (binaryTree == NULL) {
		return ERROR;
	}
	// ������ڵ�
	*tree = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (*tree == NULL) {
		return OVERFLOW;
	}
	// ���ڵ㸳ֵ
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
 * @description�������ȸ�����
 * @param��tree
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
 * @description�����ĺ������
 * @param��tree
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
 * @description�����Ĳ�α���
 * @param��tree
 */
void levelOrderTraverseTree(childSiblingTree tree) {
	if (tree == NULL) {
		return;
	}
	// �������
	suquenQueue queue;
	initSequenQueue(&queue);
	// ���ڵ����
	enSequenQueue(&queue, tree);
	// ���в�Ϊ��
	while (queue.front != queue.rear) {
		// ����
		childSiblingTree node;
		deSequenQueue(&queue, &node);
		// ����
		printf("%c", node->data);

		// ͬʱ���ֵܺͺ����Ƚ��ֵ����
		if (node->firstChild != NULL && node->nextSibling != NULL) {
			// �ֵܽڵ����
			if (node->nextSibling != NULL) {
				enSequenQueue(&queue, node->nextSibling);
			}
			// ���ӽڵ����
			if (node->firstChild != NULL) {
				enSequenQueue(&queue, node->firstChild);
			}

		}
		else {
			// ���ӽڵ����
			if (node->firstChild != NULL) {
				enSequenQueue(&queue, node->firstChild);
			}
			// �ֵܽڵ����
			if (node->nextSibling != NULL) {
				enSequenQueue(&queue, node->nextSibling);
			}
		}
	}
}





/*******************************************************************************************************************************
 * @description��������
 * @param��tree
 * @return��
 */
status createTree(childSiblingTree* tree) {
	// ������ڵ�
	*tree = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (*tree == NULL) {
		return OVERFLOW;
	}
	// ���ڵ㸳ֵ
	(*tree)->data = 'A';
	(*tree)->nextSibling = NULL;
	// ���뺢�ӽڵ�
	childSiblingTree childNode_B = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_B == NULL) {
		return OVERFLOW;
	}
	// ���ӽڵ㸳ֵ
	childNode_B->data = 'B';
	childNode_B->firstChild = NULL;
	(*tree)->firstChild = childNode_B;

	// �����ֵܽڵ�
	childSiblingTree siblingNode_C = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (siblingNode_C == NULL) {
		return OVERFLOW;
	}
	// �ֵܽڵ㸳ֵ
	siblingNode_C->data = 'C';
	childNode_B->nextSibling = siblingNode_C;

	// ���뺢�ӽڵ�
	childSiblingTree childNode_D = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_D == NULL) {
		return OVERFLOW;
	}
	// ���ӽڵ㸳ֵ
	childNode_D->data = 'D';
	siblingNode_C->firstChild = childNode_D;
	childNode_D->firstChild = NULL;
	childNode_D->nextSibling = NULL;

	// �����ֵܽڵ�
	childSiblingTree siblingNode_E = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (siblingNode_E == NULL) {
		return OVERFLOW;
	}
	// �ֵܽڵ㸳ֵ
	siblingNode_E->data = 'E';
	siblingNode_C->nextSibling = siblingNode_E;
	siblingNode_E->firstChild = NULL;
	siblingNode_E->nextSibling = NULL;


	// ���뺢�ӽڵ�
	childSiblingTree childNode_F = (childSiblingTree)malloc(sizeof(childSiblingTreeNode));
	if (childNode_F == NULL) {
		return OVERFLOW;
	}

	return OK;
}





/*******************************************************************************************************************************
 * @description����ӡ��
 * @param��tree
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
