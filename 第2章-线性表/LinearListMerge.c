#include <stdio.h>
#include <stdlib.h>
#include "LinearListMerge.h"



void LinearListMergeMain()
{
	mergelinearList La, Lb;

	// 创建单链表
	printf("输入La中的元素，用空格分割，以-1结束：");
	createMergeLinearList(&La);
	printf("\n输入Lb中的元素，用空格分割，以-1结束：");
	createMergeLinearList(&Lb);

	// 打印单链表
	printf("\nLa = ");
	printMergelinearList(La);
	printf("\nLb = ");
	printMergelinearList(Lb);

	// 合并单链表
	unioLinearList(&La, Lb);

	// 打印单链表
	printf("\n合并后La = ");
	printMergelinearList(La);
}





/*******************************************************************************************************************************
 * @description：合并单链表
 * @param：La
 * @param：Lb
 * @return：
 */
status unioLinearList(mergelinearList* La, mergelinearList Lb)
{
	int La_len = getMergeLinearListLength(*La);
	int Lb_len = getMergeLinearListLength(Lb);

	for (int i = 1; i <= Lb_len; i++) {
		int e = getMergelinearListElement(Lb, i);

		if (!(locateMergeLinearListElement(*La, e))) {
			insertMergelinearListElement(*La, ++La_len, e);
		}
	}
	return OK;
}






/*******************************************************************************************************************************
 * @description：尾插法创建一个单链表
 * @param：L		头指针
 * @return：
 */
status createMergeLinearList(mergelinearList* L)
{
	mergelinearList p, r;
	int x;
	*L = (mergelinearList)malloc(sizeof(lmnode));
	if (*L == NULL) {
		printf("内存分配失败");
		exit(ERROR);
	}
	(*L)->next = NULL;
	r = *L;
	scanf_s("%d ", &x);
	while (x != -1)
	{
		p = (mergelinearList)malloc(sizeof(lmnode));
		if (p == NULL) {
			printf("内存分配失败");
			exit(ERROR);
		}
		p->data = x;
		r->next = p;
		r = p;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：获取链表表长
 * @param：L		头结点
 * @return：		表长
 */
int getMergeLinearListLength(mergelinearList L)
{
	int count = 0;
	mergelinearList p = L->next;	// p 指向第一个结点，即首元结点
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}





/*******************************************************************************************************************************
 * @description：取单链表中的第 i 个元素的内容
 * @param：L		单链表头结点
 * @param：i		第几个元素
 * @param：e		元素的内容，由于我定义时是 int 类型，所以这边用 int
 * @return：		状态码
 */
int getMergelinearListElement(mergelinearList L, int i)
{
	int count = 1;
	mergelinearList p = L->next;	// p 指向第一个结点，即首元结点
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	int e = p->data;
	return e;
}





/*******************************************************************************************************************************
 * @description：按值查找，找元素与给定元素相同的那一项的位置
 * @param：L		头结点
 * @param：e		字符
 * @return：找到返回位置；没找到返回 0
 */
int locateMergeLinearListElement(mergelinearList L, int e)
{
	int count = 1;
	mergelinearList p = L->next;	// p 指向第一个结点，即首元结点
	while (p) {
		if (p->data == e) {
			return count;
		}
		p = p->next;
		count++;
	}
	return 0;
}





/*******************************************************************************************************************************
 * @description：在第 i 个结点前插入值为e的新结点
 * @param：L		头结点
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status insertMergelinearListElement(mergelinearList L, int i, int e)
{
	int count = 1;
	mergelinearList p = L;
	mergelinearList s;
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	s = (mergelinearList)malloc(sizeof(lmnode));	// 创建一个新节点 s
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description：打印单链表中的元素
 * @param：L		头结点
 */
void printMergelinearList(mergelinearList L)
{
	mergelinearList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}