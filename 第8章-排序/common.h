#pragma once

#ifndef _COMMON__H_
#define _COMMON__H_


#define MAXSIZE 20

typedef int keyType;

typedef struct {
	keyType key;
	// other data
}recordType;


typedef struct {
	recordType r[MAXSIZE + 1];
	int length;
}sequenList;



/*************************************��������*************************************/

// ֱ�Ӳ�������
void directInsertionSort(sequenList& L);

// �۰��������
void binaryInsertionSort(sequenList& L);

// ϣ������
void shellSort(sequenList& L);

// ð������
void bubbleSort(sequenList& L);

// ��ѡ������
void simpleSelectionSort(sequenList& L);

// ������
void heapSort(sequenList& L);

// ��������
void quickSort(sequenList& L, int low, int high);


#endif // !_COMMON__H_


