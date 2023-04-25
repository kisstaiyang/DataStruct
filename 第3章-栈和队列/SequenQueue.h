#pragma once

#ifndef _SEQUENQUEUE__H_
#define _SEQUENQUEUE__H_


#include "StatusCode.h"		// ״̬��


#define MAXQUEUESIZE 100


typedef struct {
	char* base;	// ��ʼ���Ķ�̬����洢�ռ�
	int front;	// ͷָ��
	int rear;	// βָ��
}suquenQueue;



/*************************************��������*************************************/

// ��ʼ������
status initSequenQueue(suquenQueue* Q);

// ����еĳ���
int getSequenQueueLength(suquenQueue Q);

// ���
status enSequenQueue(suquenQueue* Q, char e);

// ����
status deSequenQueue(suquenQueue* Q, char* e);

// ȡ��ͷԪ��
char getSequenQueueHead(suquenQueue Q);

// ��ӡ�����е�Ԫ��
void printSequenQueue(suquenQueue Q);

// ������
void SequenQueueMain();


#endif // !_SEQUENQUEUE__H_
