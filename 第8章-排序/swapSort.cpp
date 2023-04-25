#include <iostream>
#include "common.h"

using namespace std;



/*******************************************************************************************************************************
 * @description：冒泡排序
 * @param：L
 */
void bubbleSort(sequenList& L)
{
	int i, j;
	recordType temp;
	int flag = 1;	// 用于标记是否发生交换

	// 外层循环控制比较的趟数
	for (i = 1; i <= L.length - 1 && flag == 1; i++) {
		flag = 0;
		// 内层循环控制每趟比较的次数
		for (j = 1; j <= L.length - i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;	// 发生交换,标记为1;若本趟没发生交换，flag保持为0
				// 交换
				temp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = temp;
			}
		}
	}
}







/*******************************************************************************************************************************
 * @description：获取中轴
 * @param：L
 * @param：low
 * @param：high
 * @return：
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
 * @description：快速排序
 * @param：L
 * @param：low
 * @param：high
 */
void quickSort(sequenList& L, int low, int high)
{
	if (low < high) {
		// 将表一分为二
		int pivotloc = partition(L, low, high);
		// 递归对低子表递归排序
		quickSort(L, low, pivotloc - 1);
		// 递归对高子表递归排序
		quickSort(L, pivotloc + 1, high);
	}
}

