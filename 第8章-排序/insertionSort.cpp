#include <iostream>
#include "common.h"

using namespace std;





/*******************************************************************************************************************************
 * @description：直接插入排序
 * @param：L
 */
void directInsertionSort(sequenList& L)
{
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].key < L.r[j].key; j--) {
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}
}






/*******************************************************************************************************************************
 * @description：折半插入排序
 * @param：L
 */
void binaryInsertionSort(sequenList& L)
{
	int i, j, low, high, mid;
	for (i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];
		// 二分查找
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		// 循环结束，high+1则为插入位置，移动元素
		for (j = i - 1; j >= high + 1; j--) {
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}






/*******************************************************************************************************************************
 * @description：希尔排序
 * @param：L
 */
void shellSort(sequenList& L)
{
	int i, j, increment;
	increment = L.length;
	do {
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= L.length; i++) {
			if (L.r[i].key < L.r[i - increment].key) {
				L.r[0] = L.r[i];
				for (j = i - increment; j > 0 && L.r[0].key < L.r[j].key; j -= increment) {
					L.r[j + increment] = L.r[j];
				}
				L.r[j + increment] = L.r[0];
			}
		}
	} while (increment > 1);
}
