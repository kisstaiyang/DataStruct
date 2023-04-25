#include <stdio.h>
#include <stdlib.h>
#include "myString.h"



void StringMain()
{
	mystring S = { ' ', 'a','a','a','b','a','a','a','a','b' };		// ��������һ��λ�ò���
	S.length = 9;
	mystring T = { ' ','a','a','a','a' };							// ģʽ������һ��λ�ò���
	T.length = 4;
	printf("������");
	printString(S);
	printf("\nģʽ����");
	printString(T);

	// ����BF�㷨
	int pos = index_BF(S, T, 1);
	if (pos)
		printf("\nBF�㷨��ƥ��ɹ���λ��Ϊ��%d\n\n", pos);
	else
		printf("\nBF�㷨��ƥ��ʧ��\n\n");

	// ����KMP�㷨
	pos = index_KMP(S, T, 1);
	if (pos)
		printf("\nKMP�㷨��ƥ��ɹ���λ��Ϊ��%d\n", pos);
	else
		printf("\nKMP�㷨��ƥ��ʧ��\n");

}






/*******************************************************************************************************************************
 * @description��BF�㷨
 * @param��S		����
 * @param��T		�Ӵ�
 * @param��pos	��ʼλ��
 * @return��		ƥ��ɹ�����1�����򷵻�0
 */
int index_BF(mystring S, mystring T, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;	// ����
			j = 1;
		}
	}
	if (j > T.length)	// ƥ��ɹ�
		return i - T.length;
	else
		return 0;
}






/*******************************************************************************************************************************
 * @description������next����
 * @param��T		ģʽ��
 * @param��next
 */
static void get_next(mystring T, int next[])
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			if (T.ch[i] != T.ch[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
}






/*******************************************************************************************************************************
 * @description��KMP�㷨
 * @param��S		����
 * @param��T		ģʽ��
 * @param��pos	��ʼλ��
 * @return��
 */
int index_KMP(mystring S, mystring T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	printf("KMP�㷨��next���飺");
	for (int i = 1; i <= T.length; ++i)
		printf("%d ", next[i]);
	printf("\n");

	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}






/*******************************************************************************************************************************
 * @description����ӡ������
 * @param��S
 */
void printString(mystring S)
{
	for (int i = 1; i <= S.length; ++i)
		printf("%c ", S.ch[i]);
	printf("\n");
}
