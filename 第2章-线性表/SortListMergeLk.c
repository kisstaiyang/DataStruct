#include <stdio.h>
#include <stdlib.h>
#include "SortListMergeLk.h"




void SortListMerge_LkListMain()
{
	// 1. ��ʼ������Ϊ����ֵ
	singleLinkList La, Lb, Lc;
	initSingleLinkList(&La);
	initSingleLinkList(&Lb);

	insertSingleLinkListElement(La, 1, '1');
	insertSingleLinkListElement(La, 2, '7');
	insertSingleLinkListElement(La, 3, '8');
	printf("��������La�е�����Ϊ��");
	printSingleLinkList(La);

	insertSingleLinkListElement(Lb, 1, '2');
	insertSingleLinkListElement(Lb, 2, '4');
	insertSingleLinkListElement(Lb, 3, '6');
	insertSingleLinkListElement(Lb, 4, '8');
	insertSingleLinkListElement(Lb, 5, '9');
	printf("\n��������Lb�е�����Ϊ��");
	printSingleLinkList(Lb);


	// 2. �ϲ�
	unionSortList_Lk(&La, &Lb, &Lc);
	printf("\n�ϲ�����������Lc������Ϊ��");
	printSingleLinkList(Lc);

}





/*******************************************************************************************************************************
 * @description���ϲ���������
 * @param��La
 * @param��Lb
 * @param��Lc
 * @return��
 */
status unionSortList_Lk(singleLinkList* La, singleLinkList* Lb, singleLinkList* Lc)
{
	singleLinkList pa = (*La)->next;
	singleLinkList pb = (*Lb)->next;
	singleLinkList pc = *Lc = (*La);	// ��La��ͷ�����ΪLc��ͷ���


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

	pc->next = pa ? pa : pb;	// ����ʣ���
	free(*Lb);					// �ͷ�Lb��ͷ���

	return OK;
}
