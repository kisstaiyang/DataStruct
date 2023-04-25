#include <stdio.h>
#include <stdlib.h>
#include "SparsePolynomial.h"



void SparsePolynomialMain()
{
	polynomialList La;
	initPolynomialList(&La);
	insertPolynomialListElement(La, 1, 7, 0);
	insertPolynomialListElement(La, 2, 3, 1);
	insertPolynomialListElement(La, 3, 9, 8);
	insertPolynomialListElement(La, 4, 5, 17);
	printf("\n����ʽAΪ��");
	printPolynomialList(La);
	// ���������ʽAΪ��7 + 3 * x ^ 1 + 9 * x ^ 8 + 5 * x ^ 17


	polynomialList Lb;
	initPolynomialList(&Lb);
	insertPolynomialListElement(Lb, 1, 8, 1);
	insertPolynomialListElement(Lb, 2, 22, 7);
	insertPolynomialListElement(Lb, 3, -9, 8);
	printf("\n����ʽBΪ��");
	printPolynomialList(Lb);
	// ���������ʽBΪ��8 * x ^ 1 + 22 * x ^ 7 - 9 * x ^ 8


	// ���
	polynomialList Lc = addPolynomialList(La, Lb);
	printf("\n����ʽA+BΪ��");
	printPolynomialList(Lc);
	// ���������ʽA+BΪ��7 + 11 * x ^ 1 + 22 * x ^ 7 + 5 * x ^ 17

}






/*******************************************************************************************************************************
 * @description��ϡ�����ʽ���
 * @param��La
 * @param��Lb
 * @return������ʽ��
 */
polynomialList addPolynomialList(polynomialList La, polynomialList Lb)
{
	polynomialList Lc;
	initPolynomialList(&Lc);

	polynomialList pa = La->next;
	polynomialList pb = Lb->next;
	polynomialList pc = Lc;

	while (pa && pb) {
		if (pa->expn == pb->expn) {
			int sum = pa->coef + pb->coef;
			if (sum) {
				insertPolynomialListElement(pc, 1, sum, pa->expn);
				pc = pc->next;
			}
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->expn > pb->expn) {
			insertPolynomialListElement(pc, 1, pb->coef, pb->expn);
			pc = pc->next;
			pb = pb->next;
		}
		else {
			insertPolynomialListElement(pc, 1, pa->coef, pa->expn);
			pc = pc->next;
			pa = pa->next;
		}
	}
	while (pa) {
		insertPolynomialListElement(pc, 1, pa->coef, pa->expn);
		pc = pc->next;
		pa = pa->next;
	}
	while (pb) {
		insertPolynomialListElement(pc, 1, pb->coef, pb->expn);
		pc = pc->next;
		pb = pb->next;
	}
	return Lc;
}






/*******************************************************************************************************************************
 * @description����ʼ����ͷ���ĵ�����
 * @param��L		ָ��ͷ����ͷָ��
 * @return��״̬��
 */
status initPolynomialList(polynomialList* L)
{
	*L = (polynomialList)malloc(sizeof(polynomialNode));
	if (!*L) {
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description���ڵ� i �����ǰ�������ʽ�Ե��½��
 * @param��L		ͷ���
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status insertPolynomialListElement(polynomialList L, int i, int coef, int expn)
{
	int count = 1;
	polynomialList p = L;
	polynomialList s;
	while (p && count < i) {
		p = p->next;
		count++;
	}
	// ѭ�������ҵ��˵� i ����λ�ã��ٴν����ж�
	if (!p || count > i) {
		return ERROR;
	}
	s = (polynomialList)malloc(sizeof(polynomialNode));		// ����һ���½ڵ� s
	if (!s) {
		return ERROR;
	}
	s->coef = coef;
	s->expn = expn;
	s->next = p->next;
	p->next = s;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ӡ����ʽ
 * @param��L
 */
void printPolynomialList(polynomialList L)
{
	polynomialList p = L->next;
	while (p) {
		if (p->expn) {
			printf("%d*x^%d", p->coef, p->expn);
			p = p->next;
			if (p && p->coef > 0) {
				printf(" + ");
			}
		}
		else {
			printf("%d", p->coef);
			p = p->next;
			if (p && p->coef > 0) {
				printf(" + ");
			}
		}
	}
	printf("\n");
}