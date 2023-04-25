#pragma once

#ifndef _STATUSCODE_H_
#define _STATUSCODE_H_



#include "StatusCode.h"


#define MAXSIZE 100

typedef struct {
	char* base;		// 栈底指针
	char* top;		// 栈顶指针
	int stackSize;	// 栈的大小

}sequenStack;



/*************************************函数声明*************************************/


// 初始化
status initSequenStack(sequenStack* s);

// 判断是否为空
status isSequenStackEmpty(sequenStack s);

// 求长度
int getSequenStackLength(sequenStack s);

// 清空
status clearSequenStack(sequenStack* s);

// 销毁
status destroySequenStack(sequenStack s);

// 入栈
status pushSequenStack(sequenStack* s, char e);

// 出栈
status popSequenStack(sequenStack* s, char* e);

// 打印
void printSequenStack(sequenStack s);

// 主函数
void SequenStackMain();



#endif // !_STATUSCODE_H_
