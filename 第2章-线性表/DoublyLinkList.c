#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkList.h"





void DoublyLinkListMain()
{
	/*******************************************************************************************************************************
	 * @description：测试创建双向循环链表
	 */
	doublyLinkList doubly_link_list;
	createDoublyLinkList(&doubly_link_list, 5);
	printf("双向循环链表中元素为：");
	printDoublyLinkList(doubly_link_list);
	// 输出：双向循环链表中元素为：A B C D E



	/*******************************************************************************************************************************
	 * @description：测试插入操作，在第3个元素前插入 Z
	 */
	insertdoublyLinkList(&doubly_link_list, 3, 'Z');
	printf("\n插入Z后，双向循环链表中元素为：");
	printDoublyLinkList(doubly_link_list);
	// 输出：插入Z后，双向循环链表中元素为：A B Z C D E



	/*******************************************************************************************************************************
	 * @description：测试删除操作，删除第3个元素 Z
	 */
	char delDoublylinkchar;
	deletedoublyLinkList(&doubly_link_list, 3, &delDoublylinkchar);
	printf("\n删除Z后，双向循环链表中元素为：");
	printDoublyLinkList(doubly_link_list);
	// 输出：删除Z后，双向循环链表中元素为：A B C D E
	printf("\n被删除的元素为：%c\n", delDoublylinkchar);
	// 输出：被删除的元素为：Z

}





/*******************************************************************************************************************************
 * @description：在带头结点的双向循环链表L中第i个位置之前插入元素e
 * @param：L		头指针
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status insertdoublyLinkList(doublyLinkList* L, int i, char e)
{
	doublyLinkList p, s;
	int j;

	// 1.判断i是否合法
	if (i < 1) {
		return ERROR;
	}

	// 2.找到第i个结点
	p = *L;
	j = 0;
	while (p && j < i) {
		p = p->next;
		++j;
	}

	// 3.判断i是否合法
	if (!p || j > i) {
		return ERROR;
	}

	// 这时候以及找到第i个结点了

	// 4.分配内存
	s = (doublyLinkList)malloc(sizeof(doublynode));
	if (!s) {
		return ERROR;
	}

	// 5.插入
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}




/*******************************************************************************************************************************
 * @description：在带头结点的双向循环链表L中删除第i个元素，并用e返回其值
 * @param：L		头指针
 * @param：i		要删除第几个元素
 * @param：e		用于接收删除的元素
 * @return：		状态码
 */
status deletedoublyLinkList(doublyLinkList* L, int i, char* e)
{
	doublyLinkList p;
	int j;
	// 1.判断i是否合法
	if (i < 1) {
		return ERROR;
	}
	// 2.找到第i个结点
	p = *L;
	j = 0;
	while (p->next && j < i) {
		p = p->next;
		++j;
	}
	// 3.判断i是否合法
	if (!p->next || j > i) {
		return ERROR;
	}
	// 这时候以及找到第i个结点了

	// 4.删除
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}




/*******************************************************************************************************************************
 * @description：创建双向循环链表
 * @param：L	头指针
 * @param：n	要创建几个元素
 * @return：	状态码
 */
status createDoublyLinkList(doublyLinkList* L, int n)
{
	doublyLinkList p, r;
	*L = (doublyLinkList)malloc(sizeof(doublynode));
	if (!(*L)) {
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;
	r = *L;
	for (int i = 0; i < n; i++) {
		p = (doublyLinkList)malloc(sizeof(doublynode));
		if (!p) {
			return ERROR;
		}
		p->data = i + 65;	// data char类型：A B C D E
		r->next = p;
		p->prior = r;
		r = p;
	}
	r->next = *L;
	(*L)->prior = r;
	return OK;
}




/*******************************************************************************************************************************
 * @description：打印元素
 * @param：L	头结点
 */
void printDoublyLinkList(doublyLinkList L)
{
	doublyLinkList p;
	p = L->next;
	while (p != L) {
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}



