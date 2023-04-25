#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkList.h"



void CircularLinkListMain()
{
	// 1. 创建两个循环链表Ta，Tb，并把尾结点返回
	circularLinkList Ta;
	circularLinkList Tb;

	circularLinkList Ta_tail = createCircularLinkList(&Ta, 5);	// 元素：A B C D E
	printf("循环链表 Ta 中元素为：");
	printCircularLinkList(Ta);
	// 输出：循环链表Ta中元素为：A B C D E

	circularLinkList Tb_tail = createCircularLinkList(&Tb, 5);	// 元素：A B C D E
	printf("\n循环链表 Tb 中元素为：");
	printCircularLinkList(Tb);
	// 输出：循环链表Tb中元素为：A B C D E


	// 2. 将Tb拼接在Ta后
	mergeCircularLinkList(Ta_tail, Tb_tail);
	printf("\n拼接后循环链表中元素为：");
	//printCircularLinkList(ret);
	printCircularLinkList(Ta);
	// 输出：拼接后循环链表中元素为：A B C D E A B C D E

}





/*******************************************************************************************************************************
 * @description：初始化带头结点的循环链表
 * @param：L		指向头结点的头指针
 * @return：状态码
 */
status initCircularLinkList(circularLinkList* L)
{
	*L = (circularLinkList)malloc(sizeof(circularNode));
	if (!*L) {
		return ERROR;
	}
	(*L)->next = *L;
	return OK;
}






/*******************************************************************************************************************************
 * @description：带尾指针循环链表的合并（将Tb合并在Ta之后）
 * @param：Ta_tail	尾结点
 * @param：Tb_tail	尾结点
 * @return：
 */
status mergeCircularLinkList(circularLinkList Ta_tail, circularLinkList Tb_tail)
{
	circularLinkList p;
	circularLinkList temp;

	// 1. p存表头结点
	p = Ta_tail->next;

	// 2. 将Ta的尾结点的指针域指向Tb的首元结点
	temp = Tb_tail->next;	//	借用临时变量找到Tb的头结点
	Ta_tail->next = temp->next;

	// 3. 将Tb的尾结点的指针域指向Ta的头结点
	Tb_tail->next = p;

	// 4. 释放Tb的头结点
	free(temp);

	return OK;
}





/*******************************************************************************************************************************
 * @description：循环链表的建立--尾插法
 * @param：L		头指针
 * @param：n		要创建几个元素
 * @return：		状态码
 */
circularLinkList createCircularLinkList(circularLinkList* L, int n)
{
	circularLinkList p, r;
	// 初始化循环链表，调用之前写的初始化函数
	if (!initCircularLinkList(L)) {
		exit(ERROR);
	}
	r = *L;	// r 指向尾结点
	for (int i = 0; i < n; i++) {
		p = (circularLinkList)malloc(sizeof(circularNode));
		if (!p) {
			exit(ERROR);
		}
		// scanf("%c", p->data);
		p->data = i + 65;	// A B C D E ......
		r->next = p;
		r = p;	// r 指向新的尾结点
	}
	r->next = *L;	// 将尾结点的指针域指向头结点

	return r;	// 返回尾结点
}





/*******************************************************************************************************************************
 * @description：打印循环链表中的元素
 * @param：L		头结点
 */
void printCircularLinkList(circularLinkList L)
{
	circularLinkList p = L->next;
	while (p != L) {
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}