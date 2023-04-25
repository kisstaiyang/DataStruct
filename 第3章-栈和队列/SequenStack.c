#include <stdio.h>
#include <stdlib.h>
#include "SequenStack.h"



void SequenStackMain()
{
	/*******************************************************************************************************************************
	 * @description�����Գ�ʼ������
	 */
	sequenStack spStack;
	initSequenStack(&spStack);


	/*******************************************************************************************************************************
	 * @description��������ջ����
	 */
	pushSequenStack(&spStack, 'a');
	pushSequenStack(&spStack, 'b');
	printf("ջ��Ԫ��Ϊ��");
	printSequenStack(spStack);
	// �����ջ��Ԫ��Ϊ��a b    ps����Ϊ a �Ƚ�ջ����ӡ��ջ��Ԫ�ؿ�ʼ



	/*******************************************************************************************************************************
	 * @description�������󳤶Ȳ���
	 */
	printf("\nջ�ĳ���Ϊ��%d\n", getSequenStackLength(spStack));
	// �����ջ�ĳ���Ϊ��2



	/*******************************************************************************************************************************
	 * @description�����Գ�ջ����
	 */
	char popSqStckChar;
	popSequenStack(&spStack, &popSqStckChar);
	printf("\n��ջԪ��Ϊ��%c\n", popSqStckChar);
	// �������ջԪ��Ϊ��b   ��Ϊ b ���ջ

	printf("\nԪ��b��ջ��ջ��Ԫ��Ϊ��");
	printSequenStack(spStack);
	// �����Ԫ��b��ջ��ջ��Ԫ��Ϊ��a

	printf("\nbԪ�س�ջ��ջ�ĳ���Ϊ��%d\n", getSequenStackLength(spStack));
	// �����bԪ�س�ջ��ջ�ĳ���Ϊ��1



	/*******************************************************************************************************************************
	 * @description��������ղ���
	 */
	clearSequenStack(&spStack);
	printf("\n���ջ��ջ�ĳ���Ϊ��%d\n", getSequenStackLength(spStack));
	// ��������ջ��ջ�ĳ���Ϊ��0

}






/*******************************************************************************************************************************
 * @description����ʼ��ջ
 * @param��s		ָ��ջ��ָ��
 * @return��		״̬��
 */
status initSequenStack(sequenStack* s)
{
	s->base = (char*)malloc(MAXSIZE * sizeof(char));
	if (!s->base) {
		exit(OVERFLOW);
	}
	s->top = s->base;
	s->stackSize = MAXSIZE;
	return OK;
}





/*******************************************************************************************************************************
 * @description���ж�ջ�Ƿ�Ϊ��
 * @param��s		ջ
 * @return��		�շ��� 1�����򷵻� 0
 */
status isSequenStackEmpty(sequenStack s)
{
	if (s.top == s.base) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}





/*******************************************************************************************************************************
 * @description����˳��ջ����
 * @param��s		ջ
 * @return��		ջ�ĳ���
 */
int getSequenStackLength(sequenStack s)
{
	return s.top - s.base;
}





/*******************************************************************************************************************************
 * @description�����˳��ջ
 * @param��s		ָ��ջ��ָ��
 * @return��		״̬��
 */
status clearSequenStack(sequenStack* s)
{
	if ((*s).base)
		(*s).top = (*s).base;
	return OK;
}





/*******************************************************************************************************************************
 * @description������˳��ջ
 * @param��s		ջ
 * @return��		״̬��
 */
status destroySequenStack(sequenStack s)
{
	if (s.base) {
		free(s.base);
	}
	s.base = NULL;
	s.top = NULL;
	s.stackSize = 0;
	return OK;
}






/*******************************************************************************************************************************
 * @description����ջ
 * @param��s		ջ
 * @param��e		Ҫ��ջ��Ԫ��
 * @return��		״̬��
 */
status pushSequenStack(sequenStack* s, char e)
{
	if (s->top - s->base >= s->stackSize) {
		return ERROR;
	}
	*s->top++ = e;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ջ
 * @param��s		ָ��ջ��ָ��
 * @param��e		���ڷ���Ҫ��ջ��Ԫ��
 * @return��		״̬��
 */
status popSequenStack(sequenStack* s, char* e)
{
	if (s->top == s->base) {
		return ERROR;
	}
	*e = *--s->top;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ӡջ��Ԫ��
 * @param��s
 */
void printSequenStack(sequenStack s)
{
	char* p = s.base;
	while (p != s.top) {
		printf("%c ", *p);
		p++;
	}
	printf("\n");
}
