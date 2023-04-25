#pragma once

#ifndef _SEQUENSEARCH__H_
#define _SEQUENSEARCH__H_

#include "StatusCode.h"

#define keyType int


typedef struct {
	keyType key;	// �ؼ���
	// ����������
} ElemType;

typedef struct {
	ElemType* elem;		// �洢�ռ��ַ
	int length;			// ��ǰ����
} SequenSearchList;





/*************************************��������*************************************/

// ˳����� 
int sequensSearchList(SequenSearchList list, keyType key);

// �۰����--�ǵݹ��㷨
int binarySearchList_notRecursion(SequenSearchList list, keyType key);

// �۰����--�ݹ��㷨
int binarySearchList_recursion(SequenSearchList list, keyType key, int low, int high);

// ��ʼ��˳���
status initSequenSearchList(SequenSearchList& list);

// ����˳���
status createSequenSearchList(SequenSearchList& list);

// ��ӡ˳���
void printSequenSearchList(SequenSearchList list);


// ������
void SequenSearchMain();








#endif // !_SEQUENSEARCH__H_
