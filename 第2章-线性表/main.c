#pragma warning(disable:4996)	// 关闭4996警告

#include <stdio.h>
#include <stdlib.h>

#include "SequenceList.h"		// 顺序表
#include "SingleLinkList.h"		// 单链表
#include "CircularLinkList.h"	// 循环链表
#include "LinearListMerge.h"	// 线性表的合并
#include "SortListMergeSq.h"	// 有序表合并--顺序表实现
#include "SortListMergeLk.h"	// 有序表合并--单链表实现
#include "SparsePolynomial.h"	// 稀疏多项式加法运算



int main()
{
	// 顺序表
	// SequenceListMain();

	// 单链表
	// SingleListMain();

	// 循环链表
	// CircularLinkListMain();

	// 双向循环链表
	// DoublyLinkListMain();

	// 线性表的合并
	// LinearListMergeMain();

	// 有序表合并--顺序表实现
	// SortListMerge_SqListMain();

	// 有序表合并--单链表实现
	// SortListMerge_LkListMain();

	// 稀疏多项式加法运算
	SparsePolynomialMain();



	return 0;
}
