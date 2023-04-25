#pragma once

#ifndef _SEQUENQUEUE__H_
#define _SEQUENQUEUE__H_


#include "StatusCode.h"		// 状态码
#include "TreeAndForest.h"

#define MAXQUEUESIZE 100


typedef struct {
	childSiblingTree* base;	// 初始化的动态分配存储空间
	int front;	// 头指针
	int rear;	// 尾指针
}suquenQueue;



/*************************************函数声明*************************************/

// 初始化队列
status initSequenQueue(suquenQueue* Q);

// 求队列的长度
int getSequenQueueLength(suquenQueue Q);

// 入队
status enSequenQueue(suquenQueue* Q, childSiblingTree e);

// 出队
status deSequenQueue(suquenQueue* Q, childSiblingTree* e);

// 取队头元素
childSiblingTree getSequenQueueHead(suquenQueue Q);

// 打印队列中的元素
void printSequenQueue(suquenQueue Q);


#endif // !_SEQUENQUEUE__H_
