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
	printf("\n多项式A为：");
	printPolynomialList(La);
	// 输出：多项式A为：7 + 3 * x ^ 1 + 9 * x ^ 8 + 5 * x ^ 17


	polynomialList Lb;
	initPolynomialList(&Lb);
	insertPolynomialListElement(Lb, 1, 8, 1);
	insertPolynomialListElement(Lb, 2, 22, 7);
	insertPolynomialListElement(Lb, 3, -9, 8);
	printf("\n多项式B为：");
	printPolynomialList(Lb);
	// 输出：多项式B为：8 * x ^ 1 + 22 * x ^ 7 - 9 * x ^ 8


	// 相加
	polynomialList Lc = addPolynomialList(La, Lb);
	printf("\n多项式A+B为：");
	printPolynomialList(Lc);
	// 输出：多项式A+B为：7 + 11 * x ^ 1 + 22 * x ^ 7 + 5 * x ^ 17

}






/*******************************************************************************************************************************
 * @description：稀疏多项式相加
 * @param：La
 * @param：Lb
 * @return：多项式和
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
 * @description：初始化带头结点的单链表
 * @param：L		指向头结点的头指针
 * @return：状态码
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
 * @description：在第 i 个结点前插入多项式对的新结点
 * @param：L		头结点
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
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
	// 循环结束找到了第 i 个的位置，再次进行判断
	if (!p || count > i) {
		return ERROR;
	}
	s = (polynomialList)malloc(sizeof(polynomialNode));		// 创建一个新节点 s
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
 * @description：打印多项式
 * @param：L
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