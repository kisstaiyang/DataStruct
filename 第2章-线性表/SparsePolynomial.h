#pragma once

#ifndef SPARSEPOLYNOMIAL__H
#define SPARSEPOLYNOMIAL__H


#include "StatusCode.h"		// 状态码



typedef struct PolynomialNode {
	int coef;				// 系数
	int expn;				// 指数
	struct PolynomialNode* next;
}polynomialNode, * polynomialList;



/*************************************函数声明*************************************/

// 初始化
status initPolynomialList(polynomialList* L);

// 在第 i 个结点前插入多项式对的新结点
status insertPolynomialListElement(polynomialList L, int i, int coef, int expn);

// 打印多项式
void printPolynomialList(polynomialList L);

// 相加
polynomialList addPolynomialList(polynomialList La, polynomialList Lb);

// 主函数
void SparsePolynomialMain();



#endif // !SPARSEPOLYNOMIAL__H
