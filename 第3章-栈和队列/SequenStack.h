#pragma once

#ifndef _STATUSCODE_H_
#define _STATUSCODE_H_



#include "StatusCode.h"


#define MAXSIZE 100

typedef struct {
	char* base;		// ջ��ָ��
	char* top;		// ջ��ָ��
	int stackSize;	// ջ�Ĵ�С

}sequenStack;



/*************************************��������*************************************/


// ��ʼ��
status initSequenStack(sequenStack* s);

// �ж��Ƿ�Ϊ��
status isSequenStackEmpty(sequenStack s);

// �󳤶�
int getSequenStackLength(sequenStack s);

// ���
status clearSequenStack(sequenStack* s);

// ����
status destroySequenStack(sequenStack s);

// ��ջ
status pushSequenStack(sequenStack* s, char e);

// ��ջ
status popSequenStack(sequenStack* s, char* e);

// ��ӡ
void printSequenStack(sequenStack s);

// ������
void SequenStackMain();



#endif // !_STATUSCODE_H_
