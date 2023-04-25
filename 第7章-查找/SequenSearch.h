#pragma once

#ifndef _SEQUENSEARCH__H_
#define _SEQUENSEARCH__H_

#include "StatusCode.h"

#define keyType int


typedef struct {
	keyType key;	// 关键字
	// 其他数据域
} ElemType;

typedef struct {
	ElemType* elem;		// 存储空间基址
	int length;			// 当前长度
} SequenSearchList;





/*************************************函数声明*************************************/

// 顺序查找 
int sequensSearchList(SequenSearchList list, keyType key);

// 折半查找--非递归算法
int binarySearchList_notRecursion(SequenSearchList list, keyType key);

// 折半查找--递归算法
int binarySearchList_recursion(SequenSearchList list, keyType key, int low, int high);

// 初始化顺序表
status initSequenSearchList(SequenSearchList& list);

// 创建顺序表
status createSequenSearchList(SequenSearchList& list);

// 打印顺序表
void printSequenSearchList(SequenSearchList list);


// 主函数
void SequenSearchMain();








#endif // !_SEQUENSEARCH__H_
