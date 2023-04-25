#pragma once

#ifndef CIRCULARLINKLIST__H
#define CIRCULARLINKLIST__H

#include "StatusCode.h"		// 状态码





typedef struct CircularNode {
	char data;						// 结点的数据域
	struct CircularNode* next;		// 结点的指针域
}circularNode, * circularLinkList;




/*************************************函数声明*************************************/

// 初始化带头结点的循环链表
status initCircularLinkList(circularLinkList* L);


// 带尾指针循环链表的合并（将Tb合并在Ta之后）
status mergeCircularLinkList(circularLinkList Ta, circularLinkList Tb);


// 创建循环链表
circularLinkList createCircularLinkList(circularLinkList* L, int n);


// 打印循环链表
void printCircularLinkList(circularLinkList L);


// 主函数
void circularLinkListMain();



#endif // !CIRCULARLINKLIST__H
