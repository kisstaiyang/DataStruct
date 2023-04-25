#pragma once

#ifndef _SEQUENSTRING__H_
#define _SEQUENSTRING__H_


#include "StatusCode.h"		// ״̬��



#define MAXSTRINGSIZE 255

typedef struct {
	char ch[MAXSTRINGSIZE + 1];		// �洢����һά����
	int length;						// ���ĵ�ǰ����
}mystring;






/*************************************����ʽ��*************************************/

#define MAXBLOCKLINKSTRINGSIZE 80

typedef struct BlockLinkString {
	char ch[MAXBLOCKLINKSTRINGSIZE];		// �洢����һά����
	struct BlockLinkString* next;			// ָ����һ�����ָ��
}Block;


typedef struct {
	Block* head;		// ָ�򴮵�ͷ��
	Block* tail;		// ָ�򴮵�β��
	int length;			// ���ĵ�ǰ����
}blockLinkString;

/*************************************����ʽ��*************************************/



/*************************************��������*************************************/

// BF�㷨
int index_BF(mystring S, mystring T, int pos);

// KMP�㷨
int index_KMP(mystring S, mystring T, int pos);

// ��ӡ
void printString(mystring S);

// ������
void StringMain();











#endif // !_SEQUENSTRING__H_
