#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"



void LinkQueueMain()
{
	// 初始化
	linkQueue Q;
	initLinkQueue(&Q);
	printf("队头元素为：%c\n", getLinkQueueHead(Q));


	// 入队
	printf("入队元素：");
	for (int i = 0; i < 10; i++)
	{
		enLinkQueue(&Q, 'a' + i);
		printf("%c ", 'a' + i);
	}
	printf("\n");
	printf("队头元素为：%c\n", getLinkQueueHead(Q));
	printf("队列中的元素为：");
	printLinkQueue(Q);


	// 出队
	printf("\n出队元素：");
	char e;
	for (int i = 0; i < 5; i++)
	{
		deLinkQueue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");
	printf("队头元素为：%c\n", getLinkQueueHead(Q));
	printf("队列中的元素为：");
	printLinkQueue(Q);

}





/*******************************************************************************************************************************
 * @description：初始化
 * @param：Q		指向队列的指针
 * @return：		状态码
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
 * @description：销毁
 * @param：Q		指向队列的指针
 * @return：		状态码
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
 * @description：入队
 * @param：Q		指向队列的指针
 * @param：e		要入队的元素
 * @return：		状态码
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
 * @description：出队
 * @param：Q		指向队列的指针
 * @param：e		用于接收出队的元素
 * @return：		状态码
 */
status deLinkQueue(linkQueue* Q, char* e)
{
	if ((*Q).front == (*Q).rear)
	{	// 队空
		return ERROR;
	}
	QueuePtr temp;
	temp = (*Q).front->next;
	*e = temp->data;
	(*Q).front->next = temp->next;

	if ((*Q).rear == temp)
	{	// 如果队列中只有一个元素
		(*Q).rear = (*Q).front;
	}
	free(temp);
	return OK;
}





/*******************************************************************************************************************************
 * @description：取队头元素
 * @param：Q		队列
 * @return：		队头元素
 */
char getLinkQueueHead(linkQueue Q)
{
	if (Q.front == Q.rear)
	{	// 队空
		return ERROR;
	}
	return Q.front->next->data;
}





/*******************************************************************************************************************************
 * @description：打印队列元素
 * @param：Q
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
