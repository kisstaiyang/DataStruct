#pragma once

#ifndef _DOUBLYLINKLIST_H_
#define _DOUBLYLINKLIST_H_

#include "StatusCode.h"



typedef struct DoublyNode
{
	struct DoublyNode* prior;
	char data;
	struct DoublyNode* next;
}doublynode, * doublyLinkList;




/*************************************��������*************************************/

// ����Ԫ��
status insertdoublyLinkList(doublyLinkList* L, int i, char e);

// ɾ��Ԫ��
status deletedoublyLinkList(doublyLinkList* L, int i, char* e);

// ����˫��ѭ������
status createDoublyLinkList(doublyLinkList* L, int n);

// ��ӡ˫��ѭ������
void printDoublyLinkList(doublyLinkList L);

// ������
void DoublyLinkListMain();



#endif // !_DOUBLYLINKLIST_H_
