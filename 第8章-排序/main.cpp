#include <iostream>
#include "common.h"

using namespace std;


void print(sequenList& L)
{
	int i;
	for (i = 1; i <= L.length; i++) {
		printf("%d ", L.r[i].key);
	}
	printf("\n");

}



int main()
{
	sequenList L;
	int i;
	int arr[] = { 0, 49, 38, 65, 97, 76, 65, 27, 49 };
	for (i = 0; i < 9; i++) {
		L.r[i + 1].key = arr[i];
	}
	L.length = 8;
	cout << "����ǰ��\t";
	print(L);

	cout << "\n��ѡ������\t";
	simpleSelectionSort(L);
	print(L);

	cout << "\n������\t";
	heapSort(L);
	print(L);

	cout << "\nֱ�Ӳ�������\t";
	directInsertionSort(L);
	print(L);

	cout << "\n�۰��������\t";
	binaryInsertionSort(L);
	print(L);

	cout << "\nϣ������\t";
	shellSort(L);
	print(L);

	cout << "\nð������\t";
	bubbleSort(L);
	print(L);

	cout << "\n��������\t";
	quickSort(L, 1, L.length);
	print(L);

	return 0;
}


