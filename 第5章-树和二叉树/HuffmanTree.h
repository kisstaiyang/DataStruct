#pragma once

#ifndef _HUFFMAN__H_
#define _HUFFMAN__H_


#include "StatusCode.h"


// ���
typedef struct {
	int weight;		// Ȩֵ
	int parent;		// �����
	int leftchild;	// ����
	int rightchild; // �Һ���
}HTNode, * HuffmanTree;



typedef char* HuffmanCode;






/*************************************��������*************************************/













#endif // !_HUFFMAN__H_
