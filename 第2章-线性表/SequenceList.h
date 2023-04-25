#pragma once

#ifndef SequenceLIST  
#define SequenceLIST

#include "StatusCode.h"

#define MAXSIZE 100		// ����ʽ���ܴﵽ�����ֵ


// ˳�����
typedef struct {
	char elem;
}sequence;


typedef struct {
	sequence* data;		// ���������˶�̬���䣬����������malloc()��̬����ռ�
	int length;			// ����ʽ�е�ǰ��ĸ���
}sequenceList;



/*************************************��������*************************************/

// ��ʼ�����Ա�
status initSequenceList(sequenceList* list);

// �������Ա�
void destroySequenceList(sequenceList* list);

// ������Ա�
void clearSequenceList(sequenceList* list);

// ��ȡ���Ա�ĳ���
int getSequenceListLength(sequenceList* list);

// �ж����Ա��Ƿ�Ϊ��
status isSequenceListEmpty(sequenceList* list);

// ��ȡ���Ա��е�i��Ԫ��
status getSequenceListElement(sequenceList* list, int index, sequence* e);

// ��ȡ���Ա��е�һ��ƥ�䵽��Ԫ��
int locateSequenceListElement(sequenceList* list, char e);

// �����Ա��в���Ԫ�� e
status lastInsertSequenceListElement(sequenceList* list, sequence e);
status middleInsertSequenceListElement(sequenceList* list, int i, sequence e);
status firstInsertSequenceListElement(sequenceList* list, sequence e);
status insertSequenceListElement(sequenceList* list, int i, sequence e);

// ɾ�����Ա��е�Ԫ��
status deleteSequenceListElement(sequenceList* list, int i, sequence* e);

// ��ӡ���Ա��е�Ԫ��
void printSequenceList(sequenceList* list);

// ������
void SequenceListMain();


#endif // !SequenceLIST

