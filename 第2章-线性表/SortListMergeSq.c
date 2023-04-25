#include <stdio.h>
#include <stdlib.h>
#include "SortListMergeSq.h"
#include "SequenceList.h"	// ����֮ǰд��˳�����룬��������Ĵ����ŵ㲻���ۣ��������ܾ���




void SortListMerge_SqListMain()
{
	sequenceList sqLa, sqLb, sqLc;

	// ��ʼ��
	initSequenceList(&sqLa);
	initSequenceList(&sqLb);


	// ����La��Lb  ��Ȼ�����ţ����������һ�����ܾ���
	sqLa.data[sqLa.length].elem = '1';
	sqLa.length++;
	sqLa.data[sqLa.length].elem = '7';
	sqLa.length++;
	sqLa.data[sqLa.length].elem = '8';
	sqLa.length++;
	printf("�����La�е�����Ϊ��");
	printSequenceList(&sqLa);

	sqLb.data[sqLb.length].elem = '2';
	sqLb.length++;
	sqLb.data[sqLb.length].elem = '4';
	sqLb.length++;
	sqLb.data[sqLb.length].elem = '6';
	sqLb.length++;
	sqLb.data[sqLb.length].elem = '8';
	sqLb.length++;
	sqLb.data[sqLb.length].elem = '9';
	sqLb.length++;
	printf("\n�����Lb�е�����Ϊ��");
	printSequenceList(&sqLb);


	// �ϲ�
	unionSortList_Sq(sqLa, sqLb, &sqLc);

	printf("\n�ϲ���Lc�е�����Ϊ��");
	printSequenceList(&sqLc);

}





/*******************************************************************************************************************************
 * @description���ϸ������
 * @param��La
 * @param��Lb
 * @param��Lc
 */
void unionSortList_Sq(sequenceList La, sequenceList Lb, sequenceList* Lc)
{
	// ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ��
	sequence* pa = La.data;
	sequence* pb = Lb.data;

	// �±�ĳ���Ϊ���ϲ�������ĳ���֮��
	(*Lc).length = La.length + Lb.length;


	// Ϊ�ϲ�����±����һ������ռ�
	(*Lc).data = (sequence*)malloc((*Lc).length * sizeof(sequence));

	// ָ���±��ָ��pc�ĳ�ֵָ���±�ĵ�һ��Ԫ��
	sequence* pc = (*Lc).data;

	// pa_last��pb_last�ֱ�ָ����������һ��Ԫ��
	sequence* pa_last = La.data + La.length - 1;
	sequence* pb_last = Lb.data + Lb.length - 1;
	// ��ֵ��������

	while (pa <= pa_last && pb <= pb_last)
	{
		// ����ժȡ�����н�С��ֵ
		if (pa->elem <= pb->elem) {
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}

	while (pa <= pa_last)	// LA���ѵ����β����LA��ʣ��Ԫ�ؼ���LC
		*pc++ = *pa++;

	while (pb <= pb_last)	// LB���ѵ����β����LB��ʣ��Ԫ�ؼ���LC
		*pc++ = *pb++;

}



