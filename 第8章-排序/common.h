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



/*************************************∫Ø ˝…˘√˜*************************************/

// ÷±Ω”≤Â»Î≈≈–Ú
void directInsertionSort(sequenList& L);

// ’€∞Î≤Â»Î≈≈–Ú
void binaryInsertionSort(sequenList& L);

// œ£∂˚≈≈–Ú
void shellSort(sequenList& L);

// √∞≈›≈≈–Ú
void bubbleSort(sequenList& L);

// ºÚµ•—°‘Ò≈≈–Ú
void simpleSelectionSort(sequenList& L);

// ∂—≈≈–Ú
void heapSort(sequenList& L);

// øÏÀŸ≈≈–Ú
void quickSort(sequenList& L, int low, int high);


#endif // !_COMMON__H_


