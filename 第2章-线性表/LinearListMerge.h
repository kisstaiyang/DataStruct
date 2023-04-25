#pragma once

#ifndef LINEARLISTMERGE__H
#define LINEARLISTMERGE__H


#include "StatusCode.h"


typedef struct LinearListMergeNode {
	int data;
	struct LinearListMergeNode* next;
}lmnode, * mergelinearList;



/*************************************��������*************************************/

// β�巨����һ��������
status createMergeLinearList(mergelinearList* L);

// ��ȡ�����
int getMergeLinearListLength(mergelinearList L);

// ȡ�������еĵ� i ��Ԫ�ص�����
int getMergelinearListElement(mergelinearList L, int i);

// ��ֵ���ң���Ԫ�������Ԫ����ͬ����һ���λ��
int locateMergeLinearListElement(mergelinearList L, int e);

// �ڵ� i �����ǰ����ֵΪe���½��
status insertMergelinearListElement(mergelinearList L, int i, int e);

// �ϲ�������
status unioLinearList(mergelinearList* La, mergelinearList Lb);

// ��ӡ������
void printMergelinearList(mergelinearList L);

// ������
void LinearListMergeMain();



#endif // !LINEARLISTMERGE__H
