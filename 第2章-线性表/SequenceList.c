#include <stdio.h>
#include <stdlib.h>		// malloc()��free()
#include "SequenceList.h"




void SequenceListMain()
{
	sequenceList list;

	// ��ʼ��
	initSequenceList(&list);

	// ����5��ֵ���ֱ�Ϊ��a��b��c��d��e
	for (int i = 1; i < 6; i++)
	{
		sequence e = { i + 96 };
		insertSequenceListElement(&list, i, e);
	}


	// ��ӡ���Ա�
	printSequenceList(&list);
	// �����a b c d e


	// ��ȡ˳�����
	int length = getSequenceListLength(&list);
	printf("\n˳�����Ϊ��%d\n", length);
	// �����˳�����Ϊ��5


	// ��ȡ˳����е�3��Ԫ��
	sequence getedElement;
	getSequenceListElement(&list, 3, &getedElement);
	printf("\n˳����е�3��Ԫ��Ϊ��%c\n", getedElement.elem);
	// �����˳����е�3��Ԫ��Ϊ��c


	// ��ȡ˳����е�һ��ƥ�䵽��Ԫ��
	int indexGet = locateSequenceListElement(&list, 'd');
	if (indexGet) {
		printf("\n˳����е�һ��ƥ�䵽��Ԫ��Ϊ�� %d ��\n", indexGet);
	}
	else {
		printf("\n˳�����û��ƥ�䵽��Ԫ��\n");
	}
	// �����˳����е�һ��ƥ�䵽��Ԫ��Ϊ�� 4 ��


	// ��ȡ˳����е�һ��ƥ�䵽��Ԫ��
	int indexNotGet = locateSequenceListElement(&list, 'z');
	if (indexNotGet) {
		printf("\n˳����е�һ��ƥ�䵽��Ԫ��Ϊ�� %d ��\n", indexNotGet);
	}
	else {
		printf("\n˳�����û��ƥ�䵽��Ԫ��\n");
	}
	// �����˳�����û��ƥ�䵽��Ԫ��


	// ��λԪ����˳����е�λ��
	int localtion = locateSequenceListElement(&list, 'c');
	printf("\n�ַ�c��˳����е�λ��Ϊ��%d\n", localtion);
	// ������ַ�c��˳����е�λ��Ϊ��3


	// ɾ��˳����е�ĳ��Ԫ��
	sequence delElement;
	deleteSequenceListElement(&list, 3, &delElement);
	// ��ӡ���Ա�
	printf("\nɾ����3��Ԫ�غ��˳���Ϊ��");
	printSequenceList(&list);
	// �����ɾ����3��Ԫ�غ��˳���Ϊ��a b d e


	// ���˳���
	clearSequenceList(&list);
	printf("\n���˳����˳����е�Ԫ��Ϊ��");
	printSequenceList(&list);
	// ��������˳����˳����е�Ԫ��Ϊ��


	// ����˳���
	destroySequenceList(&list);

}





/*******************************************************************************************************************************
 * @description����ʼ��˳���
 * @param��list
 * @return��״̬��
 */
status initSequenceList(sequenceList* list)
{
	list->data = (sequence*)malloc(sizeof(sequence) * MAXSIZE);
	if (!list->data) {
		exit(OVERFLOW);		// ����ʧ��ֱ���˳�
	}

	list->length = 0;
	return OK;
}




/*******************************************************************************************************************************
 * @description������˳���
 * @param��list
 */
void destroySequenceList(sequenceList* list)
{
	// �ж��Ƿ�Ϊ��
	if (list->data) {
		free(list->data);
	}
}



/*******************************************************************************************************************************
 * @description�����˳���
 * @param��list
 */
void clearSequenceList(sequenceList* list)
{
	list->length = 0;
}



/*******************************************************************************************************************************
 * @description����ȡ˳���ĳ���
 * @param��list
 * @return������
 */
int getSequenceListLength(sequenceList* list)
{
	return list->length;
}




/*******************************************************************************************************************************
 * @description���ж�˳����Ƿ�Ϊ��
 * @param��list
 * @return��Ϊ�� ���� 1
 */
status isSequenceListEmpty(sequenceList* list)
{
	return list->length == 0 ? TRUE : FALSE;
}




/*******************************************************************************************************************************
 * @description��ȡ˳����i��Ԫ��
 * @param��list	˳���ָ��
 * @param��i		λ��
 * @param��e		Ԫ��
 * @return��״̬��
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
 * @description����ֵ���ң���Ԫ�������Ԫ����ͬ����һ���λ��
 * @param��list	˳���ָ��
 * @param��e		�ַ�
 * @return���ҵ�����λ�ã�û�ҵ����� 0
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
 * @description������Ԫ�أ�λ�������
 * @param��list	˳���ָ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status lastInsertSequenceListElement(sequenceList* list, sequence e)
{
	// �ж��Ƿ�����
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	list->data[list->length] = e;
	list->length++;
	return OK;
}




/*******************************************************************************************************************************
 * @description������Ԫ�أ�λ�����м�
 * @param��list	˳���ָ��
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��״̬��
 */
status middleInsertSequenceListElement(sequenceList* list, int i, sequence e)
{
	int j = 0;
	// �ж��Ƿ�����
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	// �ж�λ���Ƿ�Ϸ�
	if (i < 1 || i > list->length + 1) {
		return ERROR;
	}
	// �����һ��Ԫ�ؿ�ʼ����������ƶ�һλ
	for (j = list->length - 1; j >= i - 1; j--) {
		list->data[j + 1] = list->data[j];
	}
	list->data[i - 1] = e;
	list->length++;
	return OK;
}



/*******************************************************************************************************************************
 * @description������Ԫ�أ�λ������ǰ��
 * @param��list	˳���ָ��
 * @param��e		Ҫ�����Ԫ��
 * @return��״̬��
 */
status firstInsertSequenceListElement(sequenceList* list, sequence e)
{
	// ���ò����м�λ�õĺ������� i ��Ϊ 1
	return middleInsertSequenceListElement(list, 1, e);
}




/*******************************************************************************************************************************
 * @description�������Ĳ��뺯��
 * @param��list	˳���ָ��
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status insertSequenceListElement(sequenceList* list, int i, sequence e)
{
	// �ж�λ���Ƿ�Ϸ�
	if (i < 1 || i > list->length + 1) {
		return ERROR;
	}
	// �ж��Ƿ�����
	if (list->length == MAXSIZE) {
		return ERROR;
	}
	// �жϲ���λ��
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
 * @description��ɾ�����Ա�L�е� i ��Ԫ�أ��� e ������ֵ
 * @param��list	˳���ָ��
 * @param��i		Ҫ�����λ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status deleteSequenceListElement(sequenceList* list, int i, sequence* e)
{
	int j = 0;
	// �ж�λ���Ƿ�Ϸ�
	if (i < 1 || i > list->length) {
		return ERROR;
	}
	// �� e ���ر�ɾ����Ԫ��
	*e = list->data[i - 1];

	// �ӵ� i ��Ԫ�ؿ�ʼ��������ǰ�ƶ�һλ
	for (j = i; j < list->length; j++) {
		list->data[j - 1] = list->data[j];
	}
	list->length--;
	return OK;
}




/*******************************************************************************************************************************
 * @description����ӡ˳���
 * @param��list
 */
void printSequenceList(sequenceList* list)
{
	for (int i = 0; i < list->length; i++) {
		printf("%c ", list->data[i].elem);
	}
	printf("\n");
}
