#pragma once

#ifndef _TREETABLELOOKUP__H_
#define _TREETABLELOOKUP__H_


#include "StatusCode.h"

typedef int keyType;

typedef struct {
	keyType key;	// �ؼ�����
	// InfoType otherInfo;	// ����������
} elemType;


typedef struct node {
	elemType data;	// ������
	struct node* leftChild, * righrChild;	// ���Һ���ָ��
} BSTNode, * BSTree;






#endif // !_TREETABLELOOKUP__H_
