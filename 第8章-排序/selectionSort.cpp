#include <iostream>
#include "common.h"

using namespace std;





/*******************************************************************************************************************************
 * @description：简单选择排序
 * @param：L
 */
void simpleSelectionSort(sequenList& L)
{
	int i, j, min;
	for (i = 1; i < L.length; i++) {
		min = i;
		for (j = i + 1; j <= L.length; j++) {
			if (L.r[j].key < L.r[min].key) {
				// 记录最小值的位置
				min = j;
			}
		}
		if (min != i) {
			swap(L.r[i], L.r[min]);
		}
	}
}






/*******************************************************************************************************************************
 * @description：堆的调整
 * @param：L
 * @param：s
 * @param：m
 */
static void heapAdjust(sequenList& L, int s, int m)
{
	int j;
	L.r[0] = L.r[s];
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m && L.r[j].key < L.r[j + 1].key) {
			++j;
		}
		if (L.r[0].key >= L.r[j].key) {
			break;
		}
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = L.r[0];
}






/*******************************************************************************************************************************
 * @description：堆的建立
 * @param：L
 */
static void heapCreate(sequenList& L)
{
	int i;
	for (i = L.length / 2; i > 0; i--) {
		heapAdjust(L, i, L.length);
	}
}







/*******************************************************************************************************************************
 * @description：堆排序
 * @param：L
 */
void heapSort(sequenList& L)
{
	int i;
	heapCreate(L);	// 建立初始堆
	for (i = L.length; i > 1; i--) {
		swap(L.r[1], L.r[i]);
		heapAdjust(L, 1, i - 1);	// 将剩余的i-1个元素整理成堆
	}
}
