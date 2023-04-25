#include <stdio.h>
#include <stdlib.h>
#include "SortListMergeSq.h"
#include "SequenceList.h"	// 调用之前写的顺序表代码，所以下面的代码优点不美观，但是能跑就行




void SortListMerge_SqListMain()
{
	sequenceList sqLa, sqLb, sqLc;

	// 初始化
	initSequenceList(&sqLa);
	initSequenceList(&sqLb);


	// 构建La，Lb  虽然不优雅，代码和我有一个能跑就行
	sqLa.data[sqLa.length].elem = '1';
	sqLa.length++;
	sqLa.data[sqLa.length].elem = '7';
	sqLa.length++;
	sqLa.data[sqLa.length].elem = '8';
	sqLa.length++;
	printf("有序表La中的内容为：");
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
	printf("\n有序表Lb中的内容为：");
	printSequenceList(&sqLb);


	// 合并
	unionSortList_Sq(sqLa, sqLb, &sqLc);

	printf("\n合并后Lc中的内容为：");
	printSequenceList(&sqLc);

}





/*******************************************************************************************************************************
 * @description：合格有序表
 * @param：La
 * @param：Lb
 * @param：Lc
 */
void unionSortList_Sq(sequenceList La, sequenceList Lb, sequenceList* Lc)
{
	// 指针pa和pb的初值分别指向两个表的第一个元素
	sequence* pa = La.data;
	sequence* pb = Lb.data;

	// 新表的长度为待合并的两表的长度之和
	(*Lc).length = La.length + Lb.length;


	// 为合并后的新表分配一个数组空间
	(*Lc).data = (sequence*)malloc((*Lc).length * sizeof(sequence));

	// 指向新表的指针pc的初值指向新表的第一个元素
	sequence* pc = (*Lc).data;

	// pa_last，pb_last分别指向两表的最后一个元素
	sequence* pa_last = La.data + La.length - 1;
	sequence* pb_last = Lb.data + Lb.length - 1;
	// 赋值操作结束

	while (pa <= pa_last && pb <= pb_last)
	{
		// 依次摘取两表中较小的值
		if (pa->elem <= pb->elem) {
			*pc++ = *pa++;
		}
		else {
			*pc++ = *pb++;
		}
	}

	while (pa <= pa_last)	// LA表已到达表尾，将LA中剩余元素加入LC
		*pc++ = *pa++;

	while (pb <= pb_last)	// LB表已到达表尾，将LB中剩余元素加入LC
		*pc++ = *pb++;

}



