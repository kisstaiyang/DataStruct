#include <stdio.h>
#include <stdlib.h>		// malloc()、free()
#include "SequenceList.h"




void SequenceListMain()
{
	sequenceList list;

	// 初始化
	initSequenceList(&list);

	// 插入5个值，分别为：a，b，c，d，e
	for (int i = 1; i < 6; i++)
	{
		sequence e = { i + 96 };
		insertSequenceListElement(&list, i, e);
	}


	// 打印线性表
	printSequenceList(&list);
	// 输出：a b c d e


	// 获取顺序表长度
	int length = getSequenceListLength(&list);
	printf("\n顺序表长度为：%d\n", length);
	// 输出：顺序表长度为：5


	// 获取顺序表中第3个元素
	sequence getedElement;
	getSequenceListElement(&list, 3, &getedElement);
	printf("\n顺序表中第3个元素为：%c\n", getedElement.elem);
	// 输出：顺序表中第3个元素为：c


	// 获取顺序表中第一个匹配到的元素
	int indexGet = locateSequenceListElement(&list, 'd');
	if (indexGet) {
		printf("\n顺序表中第一个匹配到的元素为第 %d 个\n", indexGet);
	}
	else {
		printf("\n顺序表中没有匹配到的元素\n");
	}
	// 输出：顺序表中第一个匹配到的元素为第 4 个


	// 获取顺序表中第一个匹配到的元素
	int indexNotGet = locateSequenceListElement(&list, 'z');
	if (indexNotGet) {
		printf("\n顺序表中第一个匹配到的元素为第 %d 个\n", indexNotGet);
	}
	else {
		printf("\n顺序表中没有匹配到的元素\n");
	}
	// 输出：顺序表中没有匹配到的元素


	// 定位元素在顺序表中的位置
	int localtion = locateSequenceListElement(&list, 'c');
	printf("\n字符c在顺序表中的位置为：%d\n", localtion);
	// 输出：字符c在顺序表中的位置为：3


	// 删除顺序表中的某个元素
	sequence delElement;
	deleteSequenceListElement(&list, 3, &delElement);
	// 打印线性表
	printf("\n删除第3个元素后的顺序表为：");
	printSequenceList(&list);
	// 输出：删除第3个元素后的顺序表为：a b d e


	// 清空顺序表
	clearSequenceList(&list);
	printf("\n清空顺序表后，顺序表中的元素为：");
	printSequenceList(&list);
	// 输出：清空顺序表后，顺序表中的元素为：


	// 销毁顺序表
	destroySequenceList(&list);

}





/*******************************************************************************************************************************
 * @description：初始化顺序表
 * @param：list
 * @return：状态码
 */
status initSequenceList(sequenceList* list)
{
	list->data = (sequence*)malloc(sizeof(sequence) * MAXSIZE);
	if (!list->data) {
		exit(OVERFLOW);		// 分配失败直接退出
	}

	list->length = 0;
	return OK;
}




/*******************************************************************************************************************************
 * @description：销毁顺序表
 * @param：list
 */
void destroySequenceList(sequenceList* list)
{
	// 判断是否为空
	if (list->data) {
		free(list->data);
	}
}



/*******************************************************************************************************************************
 * @description：清空顺序表
 * @param：list
 */
void clearSequenceList(sequenceList* list)
{
	list->length = 0;
}



/*******************************************************************************************************************************
 * @description：获取顺序表的长度
 * @param：list
 * @return：长度
 */
int getSequenceListLength(sequenceList* list)
{
	return list->length;
}




/*******************************************************************************************************************************
 * @description：判断顺序表是否为空
 * @param：list
 * @return：为空 返回 1
 */
status isSequenceListEmpty(sequenceList* list)
{
	return list->length == 0 ? TRUE : FALSE;
}




/*******************************************************************************************************************************
 * @description：取顺序表第i个元素
 * @param：list	顺序表指针
 * @param：i		位置
 * @param：e		元素
 * @return：状态码
 */
status getSequenceListElement(sequenceList* list, int i, sequence* e)
{
	if (i < 1 || i > list->length) {
		return ERROR;
	}

	*e = list->data[i - 1];
	return OK;
}



/*******************************************************************************************************************************
 * @description：按值查找，找元素与给定元素相同的那一项的位置
 * @param：list	顺序表指针
 * @param：e		字符
 * @return：找到返回位置；没找到返回 0
 */
int locateSequenceListElement(sequenceList* list, char e)
{
	int i = 0;
	for (i = 0; i < list->length; i++) {
		if (list->data[i].elem == e) {
			return i + 1;
		}
	}
	return 0;
}




/*******************************************************************************************************************************
 * @description：插入元素，位置在最后
 * @param：list	顺序表指针
 * @param：e		要插入的元素
 * @return：		状态码
 */
status lastInsertSequenceListElement(sequenceList* list, sequence e)
{
	// 判断是否已满
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	list->data[list->length] = e;
	list->length++;
	return OK;
}




/*******************************************************************************************************************************
 * @description：插入元素，位置在中间
 * @param：list	顺序表指针
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：状态码
 */
status middleInsertSequenceListElement(sequenceList* list, int i, sequence e)
{
	int j = 0;
	// 判断是否已满
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	// 判断位置是否合法
	if (i < 1 || i > list->length + 1) {
		return ERROR;
	}
	// 从最后一个元素开始，依次向后移动一位
	for (j = list->length - 1; j >= i - 1; j--) {
		list->data[j + 1] = list->data[j];
	}
	list->data[i - 1] = e;
	list->length++;
	return OK;
}



/*******************************************************************************************************************************
 * @description：插入元素，位置在最前面
 * @param：list	顺序表指针
 * @param：e		要插入的元素
 * @return：状态码
 */
status firstInsertSequenceListElement(sequenceList* list, sequence e)
{
	// 调用插在中间位置的函数，把 i 设为 1
	return middleInsertSequenceListElement(list, 1, e);
}




/*******************************************************************************************************************************
 * @description：完整的插入函数
 * @param：list	顺序表指针
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status insertSequenceListElement(sequenceList* list, int i, sequence e)
{
	// 判断位置是否合法
	if (i < 1 || i > list->length + 1) {
		return ERROR;
	}
	// 判断是否已满
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	// 判断插入位置
	if (i == 1) {
		return firstInsertSequenceListElement(list, e);
	}
	else if (i == list->length + 1) {
		return lastInsertSequenceListElement(list, e);
	}
	else {
		return middleInsertSequenceListElement(list, i, e);
	}
}




/*******************************************************************************************************************************
 * @description：删除线性表L中第 i 个元素，用 e 返回其值
 * @param：list	顺序表指针
 * @param：i		要插入的位置
 * @param：e		要插入的元素
 * @return：		状态码
 */
status deleteSequenceListElement(sequenceList* list, int i, sequence* e)
{
	int j = 0;
	// 判断位置是否合法
	if (i < 1 || i > list->length) {
		return ERROR;
	}
	// 用 e 返回被删除的元素
	*e = list->data[i - 1];

	// 从第 i 个元素开始，依次向前移动一位
	for (j = i; j < list->length; j++) {
		list->data[j - 1] = list->data[j];
	}
	list->length--;
	return OK;
}




/*******************************************************************************************************************************
 * @description：打印顺序表
 * @param：list
 */
void printSequenceList(sequenceList* list)
{
	for (int i = 0; i < list->length; i++) {
		printf("%c ", list->data[i].elem);
	}
	printf("\n");
}
