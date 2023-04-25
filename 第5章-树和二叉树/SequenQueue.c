#include <stdio.h>
#include <stdlib.h>
#include "SequenQueue.h"




/*******************************************************************************************************************************
 * @description����ʼ������
 * @param��		ָ����е�ָ��
 * @return��		״̬��
 */
status initSequenQueue(suquenQueue* Q)
{
	(*Q).base = (childSiblingTree*)malloc(MAXQUEUESIZE * sizeof(childSiblingTree));
	if (!(*Q).base)
	{
		exit(OVERFLOW);
	}
	(*Q).front = (*Q).rear = 0;
	return OK;
}





/*******************************************************************************************************************************
 * @description������еĳ���
 * @param��Q		����
 * @return��		���еĳ���
 */
int getSequenQueueLength(suquenQueue Q)
{
	return (Q.rear - Q.front + MAXQUEUESIZE) % MAXQUEUESIZE;
}





/*******************************************************************************************************************************
 * @description�����
 * @param��Q		����ָ��
 * @param��e		Ҫ��ӵ�Ԫ��
 * @return��		״̬��
 */
status enSequenQueue(suquenQueue* Q, childSiblingTree e)
{
	if (((*Q).rear + 1) % MAXQUEUESIZE == (*Q).front)
	{	// ����
		return ERROR;
	}
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear + 1) % MAXQUEUESIZE;
	return OK;
}





/*******************************************************************************************************************************
 * @description������
 * @param��Q		����ָ��
 * @param��e		���ڷ���ɾ����Ԫ��
 * @return��		״̬��
 */
status deSequenQueue(suquenQueue* Q, childSiblingTree* e)
{
	if ((*Q).front == (*Q).rear)
	{	// �ӿ�
		return ERROR;
	}
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQUEUESIZE;
	return OK;
}





/*******************************************************************************************************************************
 * @description��ȡ��ͷԪ��
 * @param��Q		����
 * @return��		��ͷԪ��
 */
childSiblingTree getSequenQueueHead(suquenQueue Q)
{
	if (Q.front == Q.rear)
	{	// �ӿ�
		exit(ERROR);
	}
	return  Q.base[Q.front];
}






/*******************************************************************************************************************************
 * @description����ӡ�����е�Ԫ��
 * @param��Q		����
 */
void printSequenQueue(suquenQueue Q)
{
	int i = Q.front;
	while (i != Q.rear)
	{
		printf("%c ", Q.base[i]->data);
		i = (i + 1) % MAXQUEUESIZE;
	}
	printf("\n");
}
