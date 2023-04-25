#pragma once

#ifndef _SEQUENQUEUE__H_
#define _SEQUENQUEUE__H_


#include "StatusCode.h"		// ״̬��
#include "TreeAndForest.h"

#define MAXQUEUESIZE 100


typedef struct {
	childSiblingTree* base;	// ��ʼ���Ķ�̬����洢�ռ�
	int front;	// ͷָ��
	int rear;	// βָ��
}suquenQueue;



/*************************************��������*************************************/

// ��ʼ������
status initSequenQueue(suquenQueue* Q);

// ����еĳ���
int getSequenQueueLength(suquenQueue Q);

// ���
status enSequenQueue(suquenQueue* Q, childSiblingTree e);

// ����
status deSequenQueue(suquenQueue* Q, childSiblingTree* e);

// ȡ��ͷԪ��
childSiblingTree getSequenQueueHead(suquenQueue Q);

// ��ӡ�����е�Ԫ��
void printSequenQueue(suquenQueue Q);


#endif // !_SEQUENQUEUE__H_
