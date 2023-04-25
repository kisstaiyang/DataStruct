#pragma once

#ifndef _HUFFMAN__H_
#define _HUFFMAN__H_


#include "StatusCode.h"


// 结点
typedef struct {
	int weight;		// 权值
	int parent;		// 父结点
	int leftchild;	// 左孩子
	int rightchild; // 右孩子
}HTNode, * HuffmanTree;



typedef char* HuffmanCode;






/*************************************函数声明*************************************/













#endif // !_HUFFMAN__H_
