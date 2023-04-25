#pragma once

#ifndef SequenceLIST  
#define SequenceLIST

#include "StatusCode.h"

#define MAXSIZE 100		// 多项式可能达到的最大值


// 顺序表定义
typedef struct {
	char elem;
}sequence;


typedef struct {
	sequence* data;		// 这里我用了动态分配，后续可以用malloc()动态分配空间
	int length;			// 多项式中当前项的个数
}sequenceList;



/*************************************函数声明*************************************/

// 初始化线性表
status initSequenceList(sequenceList* list);

// 销毁线性表
void destroySequenceList(sequenceList* list);

// 清空线性表
void clearSequenceList(sequenceList* list);

// 获取线性表的长度
int getSequenceListLength(sequenceList* list);

// 判断线性表是否为空
status isSequenceListEmpty(sequenceList* list);

// 获取线性表中第i个元素
status getSequenceListElement(sequenceList* list, int index, sequence* e);

// 获取线性表中第一个匹配到的元素
int locateSequenceListElement(sequenceList* list, char e);

// 在线性表中插入元素 e
status lastInsertSequenceListElement(sequenceList* list, sequence e);
status middleInsertSequenceListElement(sequenceList* list, int i, sequence e);
status firstInsertSequenceListElement(sequenceList* list, sequence e);
status insertSequenceListElement(sequenceList* list, int i, sequence e);

// 删除线性表中的元素
status deleteSequenceListElement(sequenceList* list, int i, sequence* e);

// 打印线性表中的元素
void printSequenceList(sequenceList* list);

// 主函数
void SequenceListMain();


#endif // !SequenceLIST

