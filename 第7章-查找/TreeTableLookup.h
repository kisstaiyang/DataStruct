#pragma once

#ifndef _TREETABLELOOKUP__H_
#define _TREETABLELOOKUP__H_


#include "StatusCode.h"

typedef int keyType;

typedef struct {
	keyType key;	// 关键字域
	// InfoType otherInfo;	// 其他数据域
} elemType;


typedef struct node {
	elemType data;	// 数据域
	struct node* leftChild, * righrChild;	// 左右孩子指针
} BSTNode, * BSTree;






#endif // !_TREETABLELOOKUP__H_
