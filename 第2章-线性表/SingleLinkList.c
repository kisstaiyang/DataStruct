#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkList.h"



void SingleListMain() {

	singleLinkList single_link_list_head;

	/*******************************************************************************************************************************
	 * @description�����Ե�����Ĵ���--ͷ�巨
	 */
	 // ��ͷ�巨����һ������������Ԫ��Ϊ��e d c b a
	createSingleLinkList_Head(&single_link_list_head, 5);
	printf("��ͷ�巨�����ĵ������е�Ԫ��Ϊ��");
	printSingleLinkList(single_link_list_head);
	// �������ͷ�巨�����ĵ������е�Ԫ��Ϊ��e d c b a



	singleLinkList single_link_list_tail;

	/*******************************************************************************************************************************
	 * @description�����Ե�����Ĵ���--β�巨
	 */
	createSingleLinkList_Tail(&single_link_list_tail, 5);
	printf("\n��β�巨�����ĵ������е�Ԫ��Ϊ��");
	printSingleLinkList(single_link_list_tail);
	// �������β�巨�����ĵ������е�Ԫ��Ϊ��A B C D E



	/*******************************************************************************************************************************
	 * @description��������ղ�����ɾ��ͷ�巨�����ĵ����� single_link_list_head
	 */
	clearSingleLinkList(&single_link_list_head);
	printf("\n���ͷ�巨�����ĵ�����󣬵������е�Ԫ��Ϊ��");
	printSingleLinkList(single_link_list_head);
	// ��������ͷ�巨�����ĵ�����󣬵������е�Ԫ��Ϊ��



	/*******************************************************************************************************************************
	 * @description�������жϿձ�����������Ѿ��� single_link_list_head ���
	 */
	if (isSingleLinkListEmpty(single_link_list_head)) {
		printf("\nͷ�巨�����ĵ�����Ϊ��\n");
	}
	else {
		printf("\nͷ�巨�����ĵ�����Ϊ��\n");
	}
	// �����ͷ�巨�����ĵ�����Ϊ��



	/*******************************************************************************************************************************
	 * @description���������ٲ���������ͷ�巨�����ĵ����� single_link_list_head�����ٳɹ����� 1
	 */
	if (destroySingleLinkList(&single_link_list_head)) {
		printf("\n�ɹ�����ͷ�巨�����ĵ�����\n");
	}
	else {
		printf("\n����ͷ�巨�����ĵ�����ʧ��\n");
	}
	// ������ɹ�����ͷ�巨�����ĵ�����



	/*******************************************************************************************************************************
	 * @description�����Ի�ȡ����������ȡβ�巨����������ĳ���  single_link_list_tail
	 */
	int tailLinkListLength = getSingleLinkListLength(single_link_list_tail);
	printf("\nβ�巨�����ĵ�����ĳ���Ϊ��%d\n", tailLinkListLength);
	// �����β�巨�����ĵ�����ĳ���Ϊ��5



	/*******************************************************************************************************************************
	 * @description������ȡֵ������������ single_link_list_tail �� �� 3 ��Ԫ�ص�����
	 */
	char c;
	getSingleLinkListElement(single_link_list_tail, 3, &c);
	printf("\nβ�巨�����ĵ������еĵ� 3 ��Ԫ��Ϊ��%c\n", c);
	// �����β�巨�����ĵ������еĵ� 3 ��Ԫ��Ϊ��C




	/*******************************************************************************************************************************
	 * @description������ȡֵ����--���ص�ַ
	 */
	singleLinkList p = getSingleLinkListElementAddress(single_link_list_tail, 'C');
	printf("\nβ�巨�����ĵ������е�Ԫ�� C �ĵ�ַΪ��%p\n", p);
	// �����β�巨�����ĵ������е�Ԫ�� C �ĵ�ַΪ��0x000000000061FEB0   ps����ַ�ǻ�仯��




	/*******************************************************************************************************************************
	 * @description������ȡֵ����--����λ�����
	 */
	int num = getSingleLinkListElementIndex(single_link_list_tail, 'C');
	printf("\nβ�巨�����ĵ������е�Ԫ�� C ��λ�����Ϊ��%d\n", num);
	// �����β�巨�����ĵ������е�Ԫ�� C ��λ�����Ϊ��3




	/*******************************************************************************************************************************
	 * @description�����Բ���������� C ǰ����� Z
	 */
	insertSingleLinkListElement(single_link_list_tail, 3, 'Z');
	printf("\n�� C ǰ����� Z ��β�巨�����ĵ������е�Ԫ��Ϊ��");
	printSingleLinkList(single_link_list_tail);
	// ������� C ǰ����� Z ��β�巨�����ĵ������е�Ԫ��Ϊ��A B Z C D E




	/*******************************************************************************************************************************
	 * @description������ɾ��������ɾ�� single_link_list_tail �е�3��Ԫ��
	 */
	char deletedChar;
	deleteSingleLinkListElement(single_link_list_tail, 3, &deletedChar);
	printf("\nɾ��β�巨�����ĵ������еĵ� 3 ��Ԫ�غ󣬵������е�Ԫ��Ϊ��");
	printSingleLinkList(single_link_list_tail);
	// �����ɾ��β�巨�����ĵ������еĵ� 3 ��Ԫ�غ󣬵������е�Ԫ��Ϊ��A B C D E
	printf("\nɾ����Ԫ��Ϊ��%c\n", deletedChar);
	// �����ɾ����Ԫ��Ϊ��Z

}






/*******************************************************************************************************************************
 * @description����ʼ����ͷ���ĵ�����
 * @param��L		ָ��ͷ����ͷָ��
 * @return��״̬��
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
 * @description���ж�ͷ����ָ�����Ƿ�Ϊ��
 * @param��L		ͷ���
 * @return����Ϊ�գ����� 1
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
 * @description�����ٵ�����
 * @param��L		ָ��ͷ����ָ��
 * @return��״̬��
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
 * @description����յ�����
 * @param��L		ָ��ͷ����ָ��
 * @return��		״̬��
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
	// ͷ���ָ�����ÿ�
	(*L)->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ȡ�����
 * @param��L		ͷ���
 * @return��		��
 */
int getSingleLinkListLength(singleLinkList L)
{
	int count = 0;
	singleLinkList p = L->next;	// p ָ���һ����㣬����Ԫ���
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}





/*******************************************************************************************************************************
 * @description��ȡ�������еĵ� i ��Ԫ�ص�����
 * @param��L		������ͷ���
 * @param��i		�ڼ���Ԫ��
 * @param��e		Ԫ�ص����ݣ������Ҷ���ʱ�� char ���ͣ���������� char*
 * @return��		״̬��
 */
status getSingleLinkListElement(singleLinkList L, int i, char* e)
{
	int count = 1;
	singleLinkList p = L->next;	// p ָ���һ����㣬����Ԫ���
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}





/*******************************************************************************************************************************
 * @description������ָ�����ݻ�ȡ���������ڵ�λ�ã���ַ��
 * @param��L		ͷ���
 * @param��e		Ҫ���ҵ�ֵ
 * @return��		�ڵ������еĵ�ַ
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
 * @description������ָ�����ݻ�ȡ���������ڵ�λ�����
 * @param��L		ͷ���
 * @param��e		Ҫ���ҵ�ֵ
 * @return��		�ڵ������е�λ�����
 */
int getSingleLinkListElementIndex(singleLinkList L, char e)
{
	int count = 1;
	singleLinkList p = L->next;
	while (p && p->data != e) {
		p = p->next;
		count++;
	}
	// û�ҵ�
	if (!p) {
		return 0;
	}
	return count;
}





/*******************************************************************************************************************************
 * @description���ڵ� i �����ǰ����ֵΪe���½��
 * @param��L		ͷ���
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
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
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	s = (singleLinkList)malloc(sizeof(node));		// ����һ���½ڵ� s
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description�� ɾ���� i �����
 * @param��L		ͷ���
 * @param��i		Ҫɾ����λ��
 * @param��e		���ڽ���ɾ����ֵ
 * @return��		״̬��
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
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p->next || count > i) {
		return ERROR;
	}
	// p->next = p->next->next
	q = p->next;
	p->next = q->next;
	*e = q->data;	// ��ɾ����ֵ�� e ����
	free(q);
	return OK;
}




/*******************************************************************************************************************************
 * @description��������Ľ���--ͷ�巨
 * @param��L		ͷָ��
 * @param��n		Ҫ��������Ԫ��
 * @return��		״̬��
 */
status createSingleLinkList_Head(singleLinkList* L, int n)
{
	singleLinkList p;
	// ��ʼ������������֮ǰд�ĳ�ʼ������
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
 * @description��������Ľ���--β�巨
 * @param��L		ͷָ��
 * @param��n		Ҫ��������Ԫ��
 * @return��		״̬��
 */
status createSingleLinkList_Tail(singleLinkList* L, int n)
{
	singleLinkList p, r;
	// ��ʼ������������֮ǰд�ĳ�ʼ������
	if (!initSingleLinkList(L)) {
		return ERROR;
	}
	r = *L;	// r ָ��β���
	for (int i = 0; i < n; i++) {
		p = (singleLinkList)malloc(sizeof(node));
		if (!p) {
			return ERROR;
		}
		// scanf("%c", p->data);
		p->data = i + 65;	// A B C D E ......
		r->next = p;
		r = p;	// r ָ���µ�β���
	}
	r->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ӡ�������е�Ԫ��
 * @param��L		ͷ���
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

