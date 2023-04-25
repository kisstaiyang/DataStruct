#include <iostream>
#include "common.h"

using namespace std;



/*******************************************************************************************************************************
 * @description��ð������
 * @param��L
 */
void bubbleSort(sequenList& L)
{
	int i, j;
	recordType temp;
	int flag = 1;	// ���ڱ���Ƿ�������

	// ���ѭ�����ƱȽϵ�����
	for (i = 1; i <= L.length - 1 && flag == 1; i++) {
		flag = 0;
		// �ڲ�ѭ������ÿ�˱ȽϵĴ���
		for (j = 1; j <= L.length - i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;	// ��������,���Ϊ1;������û����������flag����Ϊ0
				// ����
				temp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = temp;
			}
		}
	}
}







/*******************************************************************************************************************************
 * @description����ȡ����
 * @param��L
 * @param��low
 * @param��high
 * @return��
 */
int partition(sequenList& L, int low, int high)
{
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey) {
			high--;
		}
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey) {
			low++;
		}
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}






/*******************************************************************************************************************************
 * @description����������
 * @param��L
 * @param��low
 * @param��high
 */
void quickSort(sequenList& L, int low, int high)
{
	if (low < high) {
		// ����һ��Ϊ��
		int pivotloc = partition(L, low, high);
		// �ݹ�Ե��ӱ�ݹ�����
		quickSort(L, low, pivotloc - 1);
		// �ݹ�Ը��ӱ�ݹ�����
		quickSort(L, pivotloc + 1, high);
	}
}

