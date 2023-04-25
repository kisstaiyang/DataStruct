#pragma once

#ifndef _LINKSTACK__H_
#define _LINKSTACK__H_



#include "StatusCode.h"


typedef struct StackNode {
	char data;
	struct StackNode* next;
}linkStackNode, * linkStack;



/*************************************��������*************************************/

// ��ʼ����ʽջ
status initLinkStack(linkStack* s);

// �п�
status isLinkStackEmpty(linkStack* s);

// ��ջ
status pushLinkStack(linkStack* s, char e);

// ��ջ
status popLinkStack(linkStack* s, char* e);

// ȡջ��Ԫ��
char getLinkStackTopElement(linkStack* s);

// ��ӡ��ʽջ��Ԫ��
void printLinkStack(linkStack* s);


#endif // !_LINKSTACK__H_
