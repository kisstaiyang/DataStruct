#include <iostream>
#include "common.h"

using namespace std;





/*******************************************************************************************************************************
 * @description����ѡ������
 * @param��L
 */
void simpleSelectionSort(sequenList& L)
{
	int i, j, min;
	for (i = 1; i < L.length; i++) {
		min = i;
		for (j = i + 1; j <= L.length; j++) {
			if (L.r[j].key < L.r[min].key) {
				// ��¼��Сֵ��λ��
				min = j;
			}
		}
		if (min != i) {
			swap(L.r[i], L.r[min]);
		}
	}
}






/*******************************************************************************************************************************
 * @description���ѵĵ���
 * @param��L
 * @param��s
 * @param��m
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
 * @description���ѵĽ���
 * @param��L
 */
static void heapCreate(sequenList& L)
{
	int i;
	for (i = L.length / 2; i > 0; i--) {
		heapAdjust(L, i, L.length);
	}
}







/*******************************************************************************************************************************
 * @description��������
 * @param��L
 */
void heapSort(sequenList& L)
{
	int i;
	heapCreate(L);	// ������ʼ��
	for (i = L.length; i > 1; i--) {
		swap(L.r[1], L.r[i]);
		heapAdjust(L, 1, i - 1);	// ��ʣ���i-1��Ԫ������ɶ�
	}
}
