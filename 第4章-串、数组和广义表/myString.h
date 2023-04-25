#pragma once

#ifndef _SEQUENSTRING__H_
#define _SEQUENSTRING__H_


#include "StatusCode.h"		// 状态码



#define MAXSTRINGSIZE 255

typedef struct {
	char ch[MAXSTRINGSIZE + 1];		// 存储串的一维数组
	int length;						// 串的当前长度
}mystring;






/*************************************块链式串*************************************/

#define MAXBLOCKLINKSTRINGSIZE 80

typedef struct BlockLinkString {
	char ch[MAXBLOCKLINKSTRINGSIZE];		// 存储串的一维数组
	struct BlockLinkString* next;			// 指向下一个块的指针
}Block;


typedef struct {
	Block* head;		// 指向串的头块
	Block* tail;		// 指向串的尾块
	int length;			// 串的当前长度
}blockLinkString;

/*************************************块链式串*************************************/



/*************************************函数声明*************************************/

// BF算法
int index_BF(mystring S, mystring T, int pos);

// KMP算法
int index_KMP(mystring S, mystring T, int pos);

// 打印
void printString(mystring S);

// 主函数
void StringMain();











#endif // !_SEQUENSTRING__H_
