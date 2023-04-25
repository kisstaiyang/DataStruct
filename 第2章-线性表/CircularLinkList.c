#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkList.h"



void CircularLinkListMain()
{
	// 1. ��������ѭ������Ta��Tb������β��㷵��
	circularLinkList Ta;
	circularLinkList Tb;

	circularLinkList Ta_tail = createCircularLinkList(&Ta, 5);	// Ԫ�أ�A B C D E
	printf("ѭ������ Ta ��Ԫ��Ϊ��");
	printCircularLinkList(Ta);
	// �����ѭ������Ta��Ԫ��Ϊ��A B C D E

	circularLinkList Tb_tail = createCircularLinkList(&Tb, 5);	// Ԫ�أ�A B C D E
	printf("\nѭ������ Tb ��Ԫ��Ϊ��");
	printCircularLinkList(Tb);
	// �����ѭ������Tb��Ԫ��Ϊ��A B C D E


	// 2. ��Tbƴ����Ta��
	mergeCircularLinkList(Ta_tail, Tb_tail);
	printf("\nƴ�Ӻ�ѭ��������Ԫ��Ϊ��");
	//printCircularLinkList(ret);
	printCircularLinkList(Ta);
	// �����ƴ�Ӻ�ѭ��������Ԫ��Ϊ��A B C D E A B C D E

}





/*******************************************************************************************************************************
 * @description����ʼ����ͷ����ѭ������
 * @param��L		ָ��ͷ����ͷָ��
 * @return��״̬��
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
 * @description����βָ��ѭ������ĺϲ�����Tb�ϲ���Ta֮��
 * @param��Ta_tail	β���
 * @param��Tb_tail	β���
 * @return��
 */
status mergeCircularLinkList(circularLinkList Ta_tail, circularLinkList Tb_tail)
{
	circularLinkList p;
	circularLinkList temp;

	// 1. p���ͷ���
	p = Ta_tail->next;

	// 2. ��Ta��β����ָ����ָ��Tb����Ԫ���
	temp = Tb_tail->next;	//	������ʱ�����ҵ�Tb��ͷ���
	Ta_tail->next = temp->next;

	// 3. ��Tb��β����ָ����ָ��Ta��ͷ���
	Tb_tail->next = p;

	// 4. �ͷ�Tb��ͷ���
	free(temp);

	return OK;
}





/*******************************************************************************************************************************
 * @description��ѭ������Ľ���--β�巨
 * @param��L		ͷָ��
 * @param��n		Ҫ��������Ԫ��
 * @return��		״̬��
 */
circularLinkList createCircularLinkList(circularLinkList* L, int n)
{
	circularLinkList p, r;
	// ��ʼ��ѭ����������֮ǰд�ĳ�ʼ������
	if (!initCircularLinkList(L)) {
		exit(ERROR);
	}
	r = *L;	// r ָ��β���
	for (int i = 0; i < n; i++) {
		p = (circularLinkList)malloc(sizeof(circularNode));
		if (!p) {
			exit(ERROR);
		}
		// scanf("%c", p->data);
		p->data = i + 65;	// A B C D E ......
		r->next = p;
		r = p;	// r ָ���µ�β���
	}
	r->next = *L;	// ��β����ָ����ָ��ͷ���

	return r;	// ����β���
}





/*******************************************************************************************************************************
 * @description����ӡѭ�������е�Ԫ��
 * @param��L		ͷ���
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