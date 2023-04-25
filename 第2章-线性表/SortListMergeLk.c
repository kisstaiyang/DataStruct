#include <stdio.h>
#include <stdlib.h>
#include "SortListMergeLk.h"




void SortListMerge_LkListMain()
{
	// 1. 初始化链表，为链表赋值
	singleLinkList La, Lb, Lc;
	initSingleLinkList(&La);
	initSingleLinkList(&Lb);

	insertSingleLinkListElement(La, 1, '1');
	insertSingleLinkListElement(La, 2, '7');
	insertSingleLinkListElement(La, 3, '8');
	printf("有序链表La中的内容为：");
	printSingleLinkList(La);

	insertSingleLinkListElement(Lb, 1, '2');
	insertSingleLinkListElement(Lb, 2, '4');
	insertSingleLinkListElement(Lb, 3, '6');
	insertSingleLinkListElement(Lb, 4, '8');
	insertSingleLinkListElement(Lb, 5, '9');
	printf("\n有序链表Lb中的内容为：");
	printSingleLinkList(Lb);


	// 2. 合并
	unionSortList_Lk(&La, &Lb, &Lc);
	printf("\n合并后有序链表Lc中内容为：");
	printSingleLinkList(Lc);

}





/*******************************************************************************************************************************
 * @description：合并有序链表
 * @param：La
 * @param：Lb
 * @param：Lc
 * @return：
 */
status unionSortList_Lk(singleLinkList* La, singleLinkList* Lb, singleLinkList* Lc)
{
	singleLinkList pa = (*La)->next;
	singleLinkList pb = (*Lb)->next;
	singleLinkList pc = *Lc = (*La);	// 用La的头结点作为Lc的头结点


	while (pa && pb)
	{
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;	// 插入剩余段
	free(*Lb);					// 释放Lb的头结点

	return OK;
}
