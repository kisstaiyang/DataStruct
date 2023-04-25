#pragma once

#ifndef CIRCULARLINKLIST__H
#define CIRCULARLINKLIST__H

#include "StatusCode.h"		// ״̬��





typedef struct CircularNode {
	char data;						// ����������
	struct CircularNode* next;		// ����ָ����
}circularNode, * circularLinkList;




/*************************************��������*************************************/

// ��ʼ����ͷ����ѭ������
status initCircularLinkList(circularLinkList* L);


// ��βָ��ѭ������ĺϲ�����Tb�ϲ���Ta֮��
status mergeCircularLinkList(circularLinkList Ta, circularLinkList Tb);


// ����ѭ������
circularLinkList createCircularLinkList(circularLinkList* L, int n);


// ��ӡѭ������
void printCircularLinkList(circularLinkList L);


// ������
void circularLinkListMain();



#endif // !CIRCULARLINKLIST__H
