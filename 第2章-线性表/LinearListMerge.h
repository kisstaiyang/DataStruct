#pragma once

#ifndef LINEARLISTMERGE__H
#define LINEARLISTMERGE__H


#include "StatusCode.h"


typedef struct LinearListMergeNode {
	int data;
	struct LinearListMergeNode* next;
}lmnode, * mergelinearList;



/*************************************函数声明*************************************/

// 尾插法创建一个单链表
status createMergeLinearList(mergelinearList* L);

// 获取链表表长
int getMergeLinearListLength(mergelinearList L);

// 取单链表中的第 i 个元素的内容
int getMergelinearListElement(mergelinearList L, int i);

// 按值查找，找元素与给定元素相同的那一项的位置
int locateMergeLinearListElement(mergelinearList L, int e);

// 在第 i 个结点前插入值为e的新结点
status insertMergelinearListElement(mergelinearList L, int i, int e);

// 合并单链表
status unioLinearList(mergelinearList* La, mergelinearList Lb);

// 打印单链表
void printMergelinearList(mergelinearList L);

// 主函数
void LinearListMergeMain();



#endif // !LINEARLISTMERGE__H
