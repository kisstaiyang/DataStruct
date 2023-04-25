#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"




void LinkStackMain()
{
	linkStack lkStack;

	/*******************************************************************************************************************************
	 * @description�����Գ�ʼ������
	 */
	initLinkStack(&lkStack);



	/*******************************************************************************************************************************
	 * @description��������ջ����
	 */
	pushLinkStack(&lkStack, 'a');
	pushLinkStack(&lkStack, 'b');
	printf("��ջ������ջ��Ԫ��Ϊ��");
	printLinkStack(&lkStack);
	// �������ջ������ջ��Ԫ��Ϊ��b a


	/*******************************************************************************************************************************
	 * @description�������пղ���
	 */
	printf("\n��ʱջ���Ƿ�Ϊ�գ�1Ϊ�գ�0��Ϊ�գ�%d\n", isLinkStackEmpty(&lkStack));



	/*******************************************************************************************************************************
	 * @description�����Գ�ջ����
	 */
	char popLinkStackChar;
	popLinkStack(&lkStack, &popLinkStackChar);
	printf("\n��ջԪ��Ϊ��%c\n", popLinkStackChar);
	// �������ջԪ��Ϊ��b
	printf("\n��ջһ��Ԫ�غ�ջ��Ԫ��Ϊ��");
	printLinkStack(&lkStack);
	// �������ջһ��Ԫ�غ�ջ��Ԫ��Ϊ��a


	/*******************************************************************************************************************************
	 * @description��ȡջ��Ԫ��
	 */
	printf("\nȡ��ջ����Ԫ��Ϊ��%c\n", getLinkStackTopElement(&lkStack));

}






/*******************************************************************************************************************************
 * @description����ʼ����ʽջ
 * @param��s		ָ����ջ��ͷָ��
 * @return��		״̬��
 */
status initLinkStack(linkStack* s)
{
	(*s) = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description���п�
 * @param��s
 * @return��	״̬��
 */
status isLinkStackEmpty(linkStack* s)
{
	if (*s == NULL)
		return TRUE;
	else
		return FALSE;
}





/*******************************************************************************************************************************
 * @description����ջ
 * @param��s		ջ��ָ��
 * @param��e		Ҫ�����Ԫ��
 * @return��		״̬��
 */
status pushLinkStack(linkStack* s, char e)
{
	linkStackNode* p = (linkStackNode*)malloc(sizeof(linkStackNode));
	//linkStackNode* p = NULL;
	if (!p)
		return OVERFLOW;
	p->data = e;
	p->next = *s;
	*s = p;
	return OK;
}





/*******************************************************************************************************************************
 * @description����ջ
 * @param��s		ջ��ָ��
 * @param��e		���ڷ��ر�ɾ����Ԫ��
 * @return��		״̬��
 */
status popLinkStack(linkStack* s, char* e)
{
	linkStackNode* p;
	if (isLinkStackEmpty(s))
		return ERROR;
	*e = (*s)->data;
	p = *s;
	*s = (*s)->next;
	free(p);
	return OK;
}





/*******************************************************************************************************************************
 * @description��ȡջ��Ԫ��
 * @param��s		ջ��ָ��
 * @return��		ջ��Ԫ��
 */
char getLinkStackTopElement(linkStack* s)
{
	if (isLinkStackEmpty(s))
		return ERROR;

	return (*s)->data;;
}





/*******************************************************************************************************************************
 * @description����ӡ��ʽջ��Ԫ��
 * @param��s
 */
void printLinkStack(linkStack* s)
{
	linkStackNode* p = *s;
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}
