#include <stdio.h>
#include <stdlib.h>
#include "SequenQueue.h"



void SequenQueueMain()
{
	// 初始化
	suquenQueue Q;
	initSequenQueue(&Q);

	// 入队
	printf("队列的长度为：%d\n", getSequenQueueLength(Q));
	printf("队头元素为：%c\n", getSequenQueueHead(Q));
	printf("入队元素：");
	for (int i = 0; i < 10; i++)
	{
		enSequenQueue(&Q, 'a' + i);
		printf("%c ", 'a' + i);
	}
	printf("\n");
	printf("队列的长度为：%d\n", getSequenQueueLength(Q));
	printf("队头元素为：%c\n", getSequenQueueHead(Q));
	printf("队列中的元素为：");
	printSequenQueue(Q);


	// 出队
	printf("\n出队元素：");
	char e;
	for (int i = 0; i < 5; i++)
	{
		deSequenQueue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");
	printf("队列的长度为：%d\n", getSequenQueueLength(Q));
	printf("队头元素为：%c\n", getSequenQueueHead(Q));
	printf("队列中的元素为：");
	printSequenQueue(Q);
}







/*******************************************************************************************************************************
 * @description：初始化队列
 * @param：		指向队列的指针
 * @return：		状态码
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
 * @description：求队列的长度
 * @param：Q		队列
 * @return：		队列的长度
 */
int getSequenQueueLength(suquenQueue Q)
{
	return (Q.rear - Q.front + MAXQUEUESIZE) % MAXQUEUESIZE;
}





/*******************************************************************************************************************************
 * @description：入队
 * @param：Q		队列指针
 * @param：e		要入队的元素
 * @return：		状态码
 */
status enSequenQueue(suquenQueue* Q, char e)
{
	if (((*Q).rear + 1) % MAXQUEUESIZE == (*Q).front)
	{	// 队满
		return ERROR;
	}
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear + 1) % MAXQUEUESIZE;
	return OK;
}





/*******************************************************************************************************************************
 * @description：出队
 * @param：Q		队列指针
 * @param：e		用于返回删除的元素
 * @return：		状态码
 */
status deSequenQueue(suquenQueue* Q, char* e)
{
	if ((*Q).front == (*Q).rear)
	{	// 队空
		return ERROR;
	}
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQUEUESIZE;
	return OK;
}





/*******************************************************************************************************************************
 * @description：取队头元素
 * @param：Q		队列
 * @return：		队头元素
 */
char getSequenQueueHead(suquenQueue Q)
{
	if (Q.front == Q.rear)
	{	// 队空
		return ERROR;
	}
	return  Q.base[Q.front];
}






/*******************************************************************************************************************************
 * @description：打印队列中的元素
 * @param：Q		队列
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
