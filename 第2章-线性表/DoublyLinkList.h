#pragma once

#ifndef _DOUBLYLINKLIST_H_
#define _DOUBLYLINKLIST_H_

#include "StatusCode.h"



typedef struct DoublyNode
{
	struct DoublyNode* prior;
	char data;
	struct DoublyNode* next;
}doublynode, * doublyLinkList;




/*************************************函数声明*************************************/

// 插入元素
status insertdoublyLinkList(doublyLinkList* L, int i, char e);

// 删除元素
status deletedoublyLinkList(doublyLinkList* L, int i, char* e);

// 创建双向循环链表
status createDoublyLinkList(doublyLinkList* L, int n);

// 打印双向循环链表
void printDoublyLinkList(doublyLinkList L);

// 主函数
void DoublyLinkListMain();



#endif // !_DOUBLYLINKLIST_H_
