#pragma once

#ifndef _LINKSTACK__H_
#define _LINKSTACK__H_



#include "StatusCode.h"


typedef struct StackNode {
	char data;
	struct StackNode* next;
}linkStackNode, * linkStack;



/*************************************函数声明*************************************/

// 初始化链式栈
status initLinkStack(linkStack* s);

// 判空
status isLinkStackEmpty(linkStack* s);

// 入栈
status pushLinkStack(linkStack* s, char e);

// 出栈
status popLinkStack(linkStack* s, char* e);

// 取栈顶元素
char getLinkStackTopElement(linkStack* s);

// 打印链式栈内元素
void printLinkStack(linkStack* s);


#endif // !_LINKSTACK__H_
