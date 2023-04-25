#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkList.h"



void SingleListMain() {

	singleLinkList single_link_list_head;

	/*******************************************************************************************************************************
	 * @description：测试单链表的创建--头插法
	 */
	 // 用头插法创建一个单链表，里面元素为：e d c b a
	createSingleLinkList_Head(&single_link_list_head, 5);
	printf("用头插法创建的单链表中的元素为：");
	printSingleLinkList(single_link_list_head);
	// 输出：用头插法创建的单链表中的元素为：e d c b a



	singleLinkList single_link_list_tail;

	/*******************************************************************************************************************************
	 * @description：测试单链表的创建--尾插法
	 */
	createSingleLinkList_Tail(&single_link_list_tail, 5);
	printf("\n用尾插法创建的单链表中的元素为：");
	printSingleLinkList(single_link_list_tail);
	// 输出：用尾插法创建的单链表中的元素为：A B C D E



	/*******************************************************************************************************************************
	 * @description：测试清空操作，删除头插法创建的单链表 single_link_list_head
	 */
	clearSingleLinkList(&single_link_list_head);
	printf("\n清空头插法创建的单链表后，单链表中的元素为：");
	printSingleLinkList(single_link_list_head);
	// 输出：清空头插法创建的单链表后，单链表中的元素为：



	/*******************************************************************************************************************************
	 * @description：测试判断空表操作，上面已经将 single_link_list_head 清空
	 */
	if (isSingleLinkListEmpty(single_link_list_head)) {
		printf("\n头插法创建的单链表为空\n");
	}
	else {
		printf("\n头插法创建的单链表不为空\n");
	}
	// 输出：头插法创建的单链表为空



	/*******************************************************************************************************************************
	 * @description：测试销毁操作，销毁头插法创建的单链表 single_link_list_head，销毁成功返回 1
	 */
	if (destroySingleLinkList(&single_link_list_head)) {
		printf("\n成功销毁头插法创建的单链表\n");
	}
	else {
		printf("\n销毁头插法创建的单链表失败\n");
	}
	// 输出：成功销毁头插法创建的单链表



	/*******************************************************************************************************************************
	 * @description：测试获取表长操作，获取尾插法创建的链表的长度  single_link_list_tail
	 */
	int tailLinkListLength = getSingleLinkListLength(single_link_list_tail);
	printf("\n尾插法创建的单链表的长度为：%d\n", tailLinkListLength);
	// 输出：尾插法创建的单链表的长度为：5



	/*******************************************************************************************************************************
	 * @description：测试取值操作，查找在 single_link_list_tail 中 第 3 个元素的内容
	 */
	char c;
	getSingleLinkListElement(single_link_list_tail, 3, &c);
	printf("\n尾插法创建的单链表中的第 3 个元素为：%c\n", c);
	// 输出：尾插法创建的单链表中的第 3 个元素为：C




	/*******************************************************************************************************************************
	 * @description：测试取值操作--返回地址
	 */
	singleLinkList p = getSingleLinkListElementAddress(single_link_list_tail, 'C');
	printf("\n尾插法创建的单链表中的元素 C 的地址为：%p\n", p);
	// 输出：尾插法创建的单链表中的元素 C 的地址为：0x000000000061FEB0   ps：地址是会变化的




	/*******************************************************************************************************************************
	 * @description：测试取值操作--返回位置序号
	 */
	int num = getSingleLinkListElementIndex(single_link_list_tail, 'C');
	printf("\n尾插法创建的单链表中的元素 C 的位置序号为：%d\n", num);
	// 输出：尾插法创建的单链表中的元素 C 的位置序号为：3




	/*******************************************************************************************************************************
	 * @description：测试插入操作，在 C 前面插入 Z
	 */
	insertSingleLinkListElement(single_link_list_tail, 3, 'Z');
	printf("\n在 C 前面插入 Z 后，尾插法创建的单链表中的元素为：");
	printSingleLinkList(single_link_list_tail);
	// 输出：在 C 前面插入 Z 后，尾插法创建的单链表中的元素为：A B Z C D E




	/*******************************************************************************************************************************
	 * @description：测试删除操作，删除 single_link_list_tail 中第3个元素
	 */
	char deletedChar;
	deleteSingleLinkListElement(single_link_list_tail, 3, &deletedChar);
	printf("\n删除尾插法创建的单链表中的第 3 个元素后，单链表中的元素为：");
	printSingleLinkList(single_link_list_tail);
	// 输出：删除尾插法创建的单链表中的第 3 个元素后，单链表中的元素为：A B C D E
	printf("\n删除的元素为：%c\n", deletedChar);
	// 输出：删除的元素为：Z

}






/*******************************************************************************************************************************
 * @description：初始化带头结点的单链表
 * @param：L		指向头结点的头指针
 * @return：状态码
 */
status initSingleLinkList(singleLinkList* L)
{
	*L = (singleLinkList)malloc(sizeof(node));
	if (!*L) {
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：判断头结点的指针域是否为空
 * @param：L		头结点
 * @return：若为空，返回 1
 */
status isSingleLinkListEmpty(singleLinkList L)
{
	if (L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}





/*******************************************************************************************************************************
 * @description：销毁单链表
 * @param：L		指向头结点的指针
 * @return：状态码
 */
status destroySingleLinkList(singleLinkList* L)
{
	singleLinkList p;
	while (*L) {
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：清空单链表
 * @param：L		指向头结点的指针
 * @return：		状态码
 */
status clearSingleLinkList(singleLinkList* L)
{
	singleLinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	// 头结点指针域置空
	(*L)->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：获取链表表长
 * @param：L		头结点
 * @return：		表长
 */
int getSingleLinkListLength(singleLinkList L)
{
	int count = 0;
	singleLinkList p = L->next;	// p 指向第一个结点，即首元结点
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
 * @param：e		元素的内容，由于我定义时是 char 类型，所以这边用 char*
 * @return：		状态码
 */
status getSingleLinkListElement(singleLinkList L, int i, char* e)
{
	int count = 1;
	singleLinkList p = L->next;	// p 指向第一个结点，即首元结点
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}





/*******************************************************************************************************************************
 * @description：根据指定数据获取该数据所在的位置（地址）
 * @param：L		头结点
 * @param：e		要查找的值
 * @return：		在单链表中的地址
 */
singleLinkList getSingleLinkListElementAddress(singleLinkList L, char e)
{
	singleLinkList p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}





/*******************************************************************************************************************************
 * @description：根据指定数据获取该数据所在的位置序号
 * @param：L		头结点
 * @param：e		要查找的值
 * @return：		在单链表中的位置序号
 */
int getSingleLinkListElementIndex(singleLinkList L, char e)
{
	int count = 1;
	singleLinkList p = L->next;
	while (p && p->data != e) {
		p = p->next;
		count++;
	}
	// 没找到
	if (!p) {
		return 0;
	}
	return count;
}





/*******************************************************************************************************************************
 * @description：在第 i 个结点前插入值为e的新结点
 * @param：L		头结点
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status insertSingleLinkListElement(singleLinkList L, int i, char e)
{
	int count = 1;
	singleLinkList p = L;
	singleLinkList s;
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	s = (singleLinkList)malloc(sizeof(node));		// 创建一个新节点 s
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description： 删除第 i 个结点
 * @param：L		头结点
 * @param：i		要删除的位置
 * @param：e		用于接受删除的值
 * @return：		状态码
 */
status deleteSingleLinkListElement(singleLinkList L, int i, char* e)
{
	int count = 1;
	singleLinkList p = L;
	singleLinkList q;
	while (p->next && count < i) {
		p = p->next;
		count++;
	}
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p->next || count > i) {
		return ERROR;
	}
	// p->next = p->next->next
	q = p->next;
	p->next = q->next;
	*e = q->data;	// 将删除的值用 e 接收
	free(q);
	return OK;
}




/*******************************************************************************************************************************
 * @description：单链表的建立--头插法
 * @param：L		头指针
 * @param：n		要创建几个元素
 * @return：		状态码
 */
status createSingleLinkList_Head(singleLinkList* L, int n)
{
	singleLinkList p;
	// 初始化单链表，调用之前写的初始化函数
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	for (int i = 0; i < n; i++) {
		p = (singleLinkList)malloc(sizeof(node));
		if (!p) {
			return ERROR;
		}
		// scanf("%c", p->data);
		p->data = i + 97;	// e d c b a ......
		p->next = (*L)->next;
		(*L)->next = p;
	}
	return OK;
}





/*******************************************************************************************************************************
 * @description：单链表的建立--尾插法
 * @param：L		头指针
 * @param：n		要创建几个元素
 * @return：		状态码
 */
status createSingleLinkList_Tail(singleLinkList* L, int n)
{
	singleLinkList p, r;
	// 初始化单链表，调用之前写的初始化函数
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	r = *L;	// r 指向尾结点
	for (int i = 0; i < n; i++) {
		p = (singleLinkList)malloc(sizeof(node));
		if (!p) {
			return ERROR;
		}
		// scanf("%c", p->data);
		p->data = i + 65;	// A B C D E ......
		r->next = p;
		r = p;	// r 指向新的尾结点
	}
	r->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：打印单链表中的元素
 * @param：L		头结点
 */
void printSingleLinkList(singleLinkList L)
{
	singleLinkList p = L->next;
	while (p) {
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

