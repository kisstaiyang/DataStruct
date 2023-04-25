#pragma once

#ifndef _LINKQUEUE__H_
#define _LINKQUEUE__H_

#include "StatusCode.h"		// ״̬��





typedef struct Qnode {
	char data;
	struct Qnode* next;
}linkQueueNode, * QueuePtr;


typedef struct {
	QueuePtr front;	// ͷָ��
	QueuePtr rear;		// βָ��
}linkQueue;




/*************************************��������*************************************/

// ��ʼ��
status initLinkQueue(linkQueue* Q);

// ����
status destroyLinkQueue(linkQueue* Q);

// ���
status enLinkQueue(linkQueue* Q, char e);

// ����
status deLinkQueue(linkQueue* Q, char* e);

// ��ȡ��ͷԪ��
char getLinkQueueHead(linkQueue Q);

// ��ӡ����Ԫ��
void printLinkQueue(linkQueue Q);

// ������
void LinkQueueMain();


#endif // !_LINKQUEUE__H_
