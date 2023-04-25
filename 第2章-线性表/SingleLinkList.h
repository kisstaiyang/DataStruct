#pragma once

#ifndef SINGLELINKLIST__H
#define SINGLELINKLIST__H

#include "StatusCode.h"		// ״̬��


typedef struct Node {
	char data;				// ����������
	struct Node* next;		// ����ָ����

}node, * singleLinkList;	// node: �������, singleLinkList: ���ָ������



/*************************************��������*************************************/

// ��ʼ��������
status initSingleLinkList(singleLinkList* L);

// �жϵ������Ƿ�Ϊ��
status isSingleLinkListEmpty(singleLinkList L);

// ���ٵ�����
status destroySingleLinkList(singleLinkList* L);

// ��յ�����
status clearSingleLinkList(singleLinkList* L);

// ��ȡ������ĳ���
int getSingleLinkListLength(singleLinkList L);

// ��ȡ�������е�i������ֵ
status getSingleLinkListElement(singleLinkList L, int i, char* e);

// ����ָ�����ݻ�ȡ���������ڵ�λ�ã���ַ��
singleLinkList getSingleLinkListElementAddress(singleLinkList L, char e);

// ����ָ�����ݻ�ȡ���������ڵ�λ�����
int getSingleLinkListElementIndex(singleLinkList L, char e);

// �ڵ� i �����ǰ����ֵΪe���½��
status insertSingleLinkListElement(singleLinkList L, int i, char e);

// ɾ���� i �����
status deleteSingleLinkListElement(singleLinkList L, int i, char* e);

// ������Ľ���--ͷ�巨
status createSingleLinkList_Head(singleLinkList* L, int n);

// ������Ľ���--β�巨
status createSingleLinkList_Tail(singleLinkList* L, int n);

// ��ӡ�������е�Ԫ��
void printSingleLinkList(singleLinkList L);

// ������
void SingleListMain();


#endif // !SINGLELINKLIST__H
