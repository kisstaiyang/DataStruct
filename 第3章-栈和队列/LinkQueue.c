#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"



void LinkQueueMain()
{
	// ��ʼ��
	linkQueue Q;
	initLinkQueue(&Q);
	printf("��ͷԪ��Ϊ��%c\n", getLinkQueueHead(Q));


	// ���
	printf("���Ԫ�أ�");
	for (int i = 0; i < 10; i++)
	{
		enLinkQueue(&Q, 'a' + i);
		printf("%c ", 'a' + i);
	}
	printf("\n");
	printf("��ͷԪ��Ϊ��%c\n", getLinkQueueHead(Q));
	printf("�����е�Ԫ��Ϊ��");
	printLinkQueue(Q);


	// ����
	printf("\n����Ԫ�أ�");
	char e;
	for (int i = 0; i < 5; i++)
	{
		deLinkQueue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");
	printf("��ͷԪ��Ϊ��%c\n", getLinkQueueHead(Q));
	printf("�����е�Ԫ��Ϊ��");
	printLinkQueue(Q);

}





/*******************************************************************************************************************************
 * @description����ʼ��
 * @param��Q		ָ����е�ָ��
 * @return��		״̬��
 */
status initLinkQueue(linkQueue* Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(linkQueueNode));
	if (!(*Q).front) {
		exit(OVERFLOW);
	}
	(*Q).front->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description������
 * @param��Q		ָ����е�ָ��
 * @return��		״̬��
 */
status destroyLinkQueue(linkQueue* Q)
{
	while ((*Q).front)
	{
		QueuePtr temp;
		temp = (*Q).front->next;
		free((*Q).front);
		(*Q).front = temp;
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description�����
 * @param��Q		ָ����е�ָ��
 * @param��e		Ҫ��ӵ�Ԫ��
 * @return��		״̬��
 */
status enLinkQueue(linkQueue* Q, char e)
{
	QueuePtr temp;
	temp = (QueuePtr)malloc(sizeof(linkQueueNode));
	if (!temp) {
		exit(OVERFLOW);
	}
	temp->data = e;
	temp->next = NULL;
	(*Q).rear->next = temp;
	(*Q).rear = temp;
	return OK;
}





/*******************************************************************************************************************************
 * @description������
 * @param��Q		ָ����е�ָ��
 * @param��e		���ڽ��ճ��ӵ�Ԫ��
 * @return��		״̬��
 */
status deLinkQueue(linkQueue* Q, char* e)
{
	if ((*Q).front == (*Q).rear)
	{	// �ӿ�
		return ERROR;
	}
	QueuePtr temp;
	temp = (*Q).front->next;
	*e = temp->data;
	(*Q).front->next = temp->next;

	if ((*Q).rear == temp)
	{	// ���������ֻ��һ��Ԫ��
		(*Q).rear = (*Q).front;
	}
	free(temp);
	return OK;
}





/*******************************************************************************************************************************
 * @description��ȡ��ͷԪ��
 * @param��Q		����
 * @return��		��ͷԪ��
 */
char getLinkQueueHead(linkQueue Q)
{
	if (Q.front == Q.rear)
	{	// �ӿ�
		return ERROR;
	}
	return Q.front->next->data;
}





/*******************************************************************************************************************************
 * @description����ӡ����Ԫ��
 * @param��Q
 */
void printLinkQueue(linkQueue Q)
{
	QueuePtr temp;
	temp = Q.front->next;
	while (temp)
	{
		printf("%c ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
