#pragma once

#ifndef SINGLELINKLIST__H
#define SINGLELINKLIST__H

#include "StatusCode.h"		// 状态码


typedef struct Node {
	char data;				// 结点的数据域
	struct Node* next;		// 结点的指针域

}node, * singleLinkList;	// node: 结点类型, singleLinkList: 结点指针类型



/*************************************函数声明*************************************/

// 初始化单链表
status initSingleLinkList(singleLinkList* L);

// 判断单链表是否为空
status isSingleLinkListEmpty(singleLinkList L);

// 销毁单链表
status destroySingleLinkList(singleLinkList* L);

// 清空单链表
status clearSingleLinkList(singleLinkList* L);

// 获取单链表的长度
int getSingleLinkListLength(singleLinkList L);

// 获取单链表中第i个结点的值
status getSingleLinkListElement(singleLinkList L, int i, char* e);

// 根据指定数据获取该数据所在的位置（地址）
singleLinkList getSingleLinkListElementAddress(singleLinkList L, char e);

// 根据指定数据获取该数据所在的位置序号
int getSingleLinkListElementIndex(singleLinkList L, char e);

// 在第 i 个结点前插入值为e的新结点
status insertSingleLinkListElement(singleLinkList L, int i, char e);

// 删除第 i 个结点
status deleteSingleLinkListElement(singleLinkList L, int i, char* e);

// 单链表的建立--头插法
status createSingleLinkList_Head(singleLinkList* L, int n);

// 单链表的建立--尾插法
status createSingleLinkList_Tail(singleLinkList* L, int n);

// 打印单链表中的元素
void printSingleLinkList(singleLinkList L);

// 主函数
void SingleListMain();


#endif // !SINGLELINKLIST__H
