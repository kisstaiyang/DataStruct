#include <stdio.h>
#include <stdlib.h>
#include "myString.h"



void StringMain()
{
	mystring S = { ' ', 'a','a','a','b','a','a','a','a','b' };		// 主串，第一个位置不用
	S.length = 9;
	mystring T = { ' ','a','a','a','a' };							// 模式串，第一个位置不用
	T.length = 4;
	printf("主串：");
	printString(S);
	printf("\n模式串：");
	printString(T);

	// 测试BF算法
	int pos = index_BF(S, T, 1);
	if (pos)
		printf("\nBF算法：匹配成功，位置为：%d\n\n", pos);
	else
		printf("\nBF算法：匹配失败\n\n");

	// 测试KMP算法
	pos = index_KMP(S, T, 1);
	if (pos)
		printf("\nKMP算法：匹配成功，位置为：%d\n", pos);
	else
		printf("\nKMP算法：匹配失败\n");

}






/*******************************************************************************************************************************
 * @description：BF算法
 * @param：S		主串
 * @param：T		子串
 * @param：pos	开始位置
 * @return：		匹配成功返回1；否则返回0
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
			i = i - j + 2;	// 回溯
			j = 1;
		}
	}
	if (j > T.length)	// 匹配成功
		return i - T.length;
	else
		return 0;
}






/*******************************************************************************************************************************
 * @description：构造next数组
 * @param：T		模式串
 * @param：next
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
 * @description：KMP算法
 * @param：S		主串
 * @param：T		模式串
 * @param：pos	开始位置
 * @return：
 */
int index_KMP(mystring S, mystring T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	printf("KMP算法中next数组：");
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
 * @description：打印串内容
 * @param：S
 */
void printString(mystring S)
{
	for (int i = 1; i <= S.length; ++i)
		printf("%c ", S.ch[i]);
	printf("\n");
}
