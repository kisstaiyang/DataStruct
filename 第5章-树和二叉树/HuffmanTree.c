#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanTree.h"

#pragma warning(disable:4996)	// �ر�4996����



/*******************************************************************************************************************************
 * @description��ѡ��HT[1...n]��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
 * @param��HT
 * @param��n
 * @param��s1
 * @param��s2
 */
static void select(HuffmanTree HT, int n, int* s1, int* s2)
{
	int min1 = 0, min2 = 0;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			if (min1 == 0) {
				min1 = i;
			}
			else if (min2 == 0) {
				min2 = i;
			}
			else {
				if (HT[i].weight < HT[min1].weight) {
					min2 = min1;
					min1 = i;
				}
				else if (HT[i].weight < HT[min2].weight) {
					min2 = i;
				}
			}
		}
	}
	*s1 = min1;
	*s2 = min2;
}






/*******************************************************************************************************************************
 * @description������Huffman��
 * @param��HT
 * @param��w
 * @param��n
 */
void createHuffmanTree(HuffmanTree HT, int* w, int n)
{
	if (n <= 1) {
		return;
	}
	long m = 2 * n - 1;	// �������
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	if (!HT) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}

	// ��ʼ��
	for (int i = 1; i <= m; i++) {
		HT[i].parent = 0;
		HT[i].leftchild = 0;
		HT[i].rightchild = 0;
	}

	// ��ǰn����㸳Ȩֵ
	for (int i = 1; i <= n; i++) {
		HT[i].weight = w[i - 1];
	}

	// �ϲ�����n-1����㡪������Huffman��
	for (int i = n + 1; i <= m; i++) {
		// ��HT[1...i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		int s1, s2;
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].leftchild = s1;
		HT[i].rightchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;

	}
}






/*******************************************************************************************************************************
 * @description����Ҷ�ӵ���������ÿ���ַ��Ĺ���������
 * @param��HT
 * @param��HC
 * @param��n
 */
void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n)
{
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	char* cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int p = HT[i].parent;
		while (p != 0) {
			--start;
			if (HT[p].leftchild == c) {
				cd[start] = '0';
			}
			else {
				cd[start] = '1';
			}
			c = p;
			p = HT[p].parent;	// �������ϻ���
		}
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy((*HC)[i], &cd[start]);
	}
	free(cd);
}






/*******************************************************************************************************************************
 * @description������
 * @param��HT
 * @param��HC
 * @param��n
 */
void decode(HuffmanTree HT, HuffmanCode HC, int n)
{
	int m = 2 * n - 1;
	int p = m;
	for (int i = 0; i < strlen(HC); i++) {
		if (HC[i] == '0') {
			p = HT[p].leftchild;
		}
		else {
			p = HT[p].rightchild;
		}
		if (HT[p].leftchild == 0 && HT[p].rightchild == 0) {
			printf("%c", p);
			p = m;
		}
	}
}



