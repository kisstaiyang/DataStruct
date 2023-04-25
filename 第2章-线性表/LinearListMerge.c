#include <stdio.h>
#include <stdlib.h>
#include "LinearListMerge.h"



void LinearListMergeMain()
{
	mergelinearList La, Lb;

	// ����������
	printf("����La�е�Ԫ�أ��ÿո�ָ��-1������");
	createMergeLinearList(&La);
	printf("\n����Lb�е�Ԫ�أ��ÿո�ָ��-1������");
	createMergeLinearList(&Lb);

	// ��ӡ������
	printf("\nLa = ");
	printMergelinearList(La);
	printf("\nLb = ");
	printMergelinearList(Lb);

	// �ϲ�������
	unioLinearList(&La, Lb);

	// ��ӡ������
	printf("\n�ϲ���La = ");
	printMergelinearList(La);
}





/*******************************************************************************************************************************
 * @description���ϲ�������
 * @param��La
 * @param��Lb
 * @return��
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
 * @description��β�巨����һ��������
 * @param��L		ͷָ��
 * @return��
 */
status createMergeLinearList(mergelinearList* L)
{
	mergelinearList p, r;
	int x;
	*L = (mergelinearList)malloc(sizeof(lmnode));
	if (*L == NULL) {
		printf("�ڴ����ʧ��");
		exit(ERROR);
	}
	(*L)->next = NULL;
	r = *L;
	scanf_s("%d ", &x);
	while (x != -1)
	{
		p = (mergelinearList)malloc(sizeof(lmnode));
		if (p == NULL) {
			printf("�ڴ����ʧ��");
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
 * @description����ȡ�����
 * @param��L		ͷ���
 * @return��		��
 */
int getMergeLinearListLength(mergelinearList L)
{
	int count = 0;
	mergelinearList p = L->next;	// p ָ���һ����㣬����Ԫ���
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
 * @param��e		Ԫ�ص����ݣ������Ҷ���ʱ�� int ���ͣ���������� int
 * @return��		״̬��
 */
int getMergelinearListElement(mergelinearList L, int i)
{
	int count = 1;
	mergelinearList p = L->next;	// p ָ���һ����㣬����Ԫ���
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	int e = p->data;
	return e;
}





/*******************************************************************************************************************************
 * @description����ֵ���ң���Ԫ�������Ԫ����ͬ����һ���λ��
 * @param��L		ͷ���
 * @param��e		�ַ�
 * @return���ҵ�����λ�ã�û�ҵ����� 0
 */
int locateMergeLinearListElement(mergelinearList L, int e)
{
	int count = 1;
	mergelinearList p = L->next;	// p ָ���һ����㣬����Ԫ���
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
 * @description���ڵ� i �����ǰ����ֵΪe���½��
 * @param��L		ͷ���
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
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
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	s = (mergelinearList)malloc(sizeof(lmnode));	// ����һ���½ڵ� s
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ӡ�������е�Ԫ��
 * @param��L		ͷ���
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