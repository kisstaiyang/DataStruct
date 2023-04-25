#pragma once

#ifndef SPARSEPOLYNOMIAL__H
#define SPARSEPOLYNOMIAL__H


#include "StatusCode.h"		// ״̬��



typedef struct PolynomialNode {
	int coef;				// ϵ��
	int expn;				// ָ��
	struct PolynomialNode* next;
}polynomialNode, * polynomialList;



/*************************************��������*************************************/

// ��ʼ��
status initPolynomialList(polynomialList* L);

// �ڵ� i �����ǰ�������ʽ�Ե��½��
status insertPolynomialListElement(polynomialList L, int i, int coef, int expn);

// ��ӡ����ʽ
void printPolynomialList(polynomialList L);

// ���
polynomialList addPolynomialList(polynomialList La, polynomialList Lb);

// ������
void SparsePolynomialMain();



#endif // !SPARSEPOLYNOMIAL__H
