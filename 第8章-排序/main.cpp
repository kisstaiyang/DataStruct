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
	cout << "ÅÅÐòÇ°£º\t";
	print(L);

	cout << "\n¼òµ¥Ñ¡ÔñÅÅÐò£º\t";
	simpleSelectionSort(L);
	print(L);

	cout << "\n¶ÑÅÅÐò£º\t";
	heapSort(L);
	print(L);

	cout << "\nÖ±½Ó²åÈëÅÅÐò£º\t";
	directInsertionSort(L);
	print(L);

	cout << "\nÕÛ°ë²åÈëÅÅÐò£º\t";
	binaryInsertionSort(L);
	print(L);

	cout << "\nÏ£¶ûÅÅÐò£º\t";
	shellSort(L);
	print(L);

	cout << "\nÃ°ÅÝÅÅÐò£º\t";
	bubbleSort(L);
	print(L);

	cout << "\n¿ìËÙÅÅÐò£º\t";
	quickSort(L, 1, L.length);
	print(L);

	return 0;
}


