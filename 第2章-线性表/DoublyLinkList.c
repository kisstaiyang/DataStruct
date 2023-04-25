#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkList.h"





void DoublyLinkListMain()
{
	/*******************************************************************************************************************************
	 * @description�����Դ���˫��ѭ������
	 */
	doublyLinkList doubly_link_list;
	createDoublyLinkList(&doubly_link_list, 5);
	printf("˫��ѭ��������Ԫ��Ϊ��");
	printDoublyLinkList(doubly_link_list);
	// �����˫��ѭ��������Ԫ��Ϊ��A B C D E



	/*******************************************************************************************************************************
	 * @description�����Բ���������ڵ�3��Ԫ��ǰ���� Z
	 */
	insertdoublyLinkList(&doubly_link_list, 3, 'Z');
	printf("\n����Z��˫��ѭ��������Ԫ��Ϊ��");
	printDoublyLinkList(doubly_link_list);
	// ���������Z��˫��ѭ��������Ԫ��Ϊ��A B Z C D E



	/*******************************************************************************************************************************
	 * @description������ɾ��������ɾ����3��Ԫ�� Z
	 */
	char delDoublylinkchar;
	deletedoublyLinkList(&doubly_link_list, 3, &delDoublylinkchar);
	printf("\nɾ��Z��˫��ѭ��������Ԫ��Ϊ��");
	printDoublyLinkList(doubly_link_list);
	// �����ɾ��Z��˫��ѭ��������Ԫ��Ϊ��A B C D E
	printf("\n��ɾ����Ԫ��Ϊ��%c\n", delDoublylinkchar);
	// �������ɾ����Ԫ��Ϊ��Z

}





/*******************************************************************************************************************************
 * @description���ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e
 * @param��L		ͷָ��
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status insertdoublyLinkList(doublyLinkList* L, int i, char e)
{
	doublyLinkList p, s;
	int j;

	// 1.�ж�i�Ƿ�Ϸ�
	if (i < 1) {
		return ERROR;
	}

	// 2.�ҵ���i�����
	p = *L;
	j = 0;
	while (p && j < i) {
		p = p->next;
		++j;
	}

	// 3.�ж�i�Ƿ�Ϸ�
	if (!p || j > i) {
		return ERROR;
	}

	// ��ʱ���Լ��ҵ���i�������

	// 4.�����ڴ�
	s = (doublyLinkList)malloc(sizeof(doublynode));
	if (!s) {
		return ERROR;
	}

	// 5.����
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}




/*******************************************************************************************************************************
 * @description���ڴ�ͷ����˫��ѭ������L��ɾ����i��Ԫ�أ�����e������ֵ
 * @param��L		ͷָ��
 * @param��i		Ҫɾ���ڼ���Ԫ��
 * @param��e		���ڽ���ɾ����Ԫ��
 * @return��		״̬��
 */
status deletedoublyLinkList(doublyLinkList* L, int i, char* e)
{
	doublyLinkList p;
	int j;
	// 1.�ж�i�Ƿ�Ϸ�
	if (i < 1) {
		return ERROR;
	}
	// 2.�ҵ���i�����
	p = *L;
	j = 0;
	while (p->next && j < i) {
		p = p->next;
		++j;
	}
	// 3.�ж�i�Ƿ�Ϸ�
	if (!p->next || j > i) {
		return ERROR;
	}
	// ��ʱ���Լ��ҵ���i�������

	// 4.ɾ��
	*e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}




/*******************************************************************************************************************************
 * @description������˫��ѭ������
 * @param��L	ͷָ��
 * @param��n	Ҫ��������Ԫ��
 * @return��	״̬��
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
		p->data = i + 65;	// data char���ͣ�A B C D E
		r->next = p;
		p->prior = r;
		r = p;
	}
	r->next = *L;
	(*L)->prior = r;
	return OK;
}




/*******************************************************************************************************************************
 * @description����ӡԪ��
 * @param��L	ͷ���
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



