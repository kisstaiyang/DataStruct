#pragma once

#ifndef _LINKQUEUE__H_
#define _LINKQUEUE__H_

#include "StatusCode.h"		// 状态码





typedef struct Qnode {
	char data;
	struct Qnode* next;
}linkQueueNode, * QueuePtr;


typedef struct {
	QueuePtr front;	// 头指针
	QueuePtr rear;		// 尾指针
}linkQueue;




/*************************************函数声明*************************************/

// 初始化
status initLinkQueue(linkQueue* Q);

// 销毁
status destroyLinkQueue(linkQueue* Q);

// 入队
status enLinkQueue(linkQueue* Q, char e);

// 出队
status deLinkQueue(linkQueue* Q, char* e);

// 获取队头元素
char getLinkQueueHead(linkQueue Q);

// 打印队列元素
void printLinkQueue(linkQueue Q);

// 主函数
void LinkQueueMain();


#endif // !_LINKQUEUE__H_
