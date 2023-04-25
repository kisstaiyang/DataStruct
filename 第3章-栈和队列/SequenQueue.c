#include <stdio.h>
#include <stdlib.h>
#include "SequenQueue.h"



void SequenQueueMain()
{
	// ��ʼ��
	suquenQueue Q;
	initSequenQueue(&Q);

	// ���
	printf("���еĳ���Ϊ��%d\n", getSequenQueueLength(Q));
	printf("��ͷԪ��Ϊ��%c\n", getSequenQueueHead(Q));
	printf("���Ԫ�أ�");
	for (int i = 0; i < 10; i++)
	{
		enSequenQueue(&Q, 'a' + i);
		printf("%c ", 'a' + i);
	}
	printf("\n");
	printf("���еĳ���Ϊ��%d\n", getSequenQueueLength(Q));
	printf("��ͷԪ��Ϊ��%c\n", getSequenQueueHead(Q));
	printf("�����е�Ԫ��Ϊ��");
	printSequenQueue(Q);


	// ����
	printf("\n����Ԫ�أ�");
	char e;
	for (int i = 0; i < 5; i++)
	{
		deSequenQueue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");
	printf("���еĳ���Ϊ��%d\n", getSequenQueueLength(Q));
	printf("��ͷԪ��Ϊ��%c\n", getSequenQueueHead(Q));
	printf("�����е�Ԫ��Ϊ��");
	printSequenQueue(Q);
}







/*******************************************************************************************************************************
 * @description����ʼ������
 * @param��		ָ����е�ָ��
 * @return��		״̬��
 */
status initSequenQueue(suquenQueue* Q)
{
	(*Q).base = (char*)malloc(MAXQUEUESIZE * sizeof(char));
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
status enSequenQueue(suquenQueue* Q, char e)
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
status deSequenQueue(suquenQueue* Q, char* e)
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
char getSequenQueueHead(suquenQueue Q)
{
	if (Q.front == Q.rear)
	{	// �ӿ�
		return ERROR;
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
		printf("%c ", Q.base[i]);
		i = (i + 1) % MAXQUEUESIZE;
	}
	printf("\n");
}
