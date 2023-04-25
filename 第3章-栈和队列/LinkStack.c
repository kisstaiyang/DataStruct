#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"




void LinkStackMain()
{
	linkStack lkStack;

	/*******************************************************************************************************************************
	 * @description：测试初始化操作
	 */
	initLinkStack(&lkStack);



	/*******************************************************************************************************************************
	 * @description：测试入栈操作
	 */
	pushLinkStack(&lkStack, 'a');
	pushLinkStack(&lkStack, 'b');
	printf("入栈操作后，栈内元素为：");
	printLinkStack(&lkStack);
	// 输出：入栈操作后，栈内元素为：b a


	/*******************************************************************************************************************************
	 * @description：测试判空操作
	 */
	printf("\n此时栈内是否为空，1为空，0不为空：%d\n", isLinkStackEmpty(&lkStack));



	/*******************************************************************************************************************************
	 * @description：测试出栈操作
	 */
	char popLinkStackChar;
	popLinkStack(&lkStack, &popLinkStackChar);
	printf("\n出栈元素为：%c\n", popLinkStackChar);
	// 输出：出栈元素为：b
	printf("\n出栈一个元素后，栈内元素为：");
	printLinkStack(&lkStack);
	// 输出：出栈一个元素后，栈内元素为：a


	/*******************************************************************************************************************************
	 * @description：取栈顶元素
	 */
	printf("\n取出栈顶的元素为：%c\n", getLinkStackTopElement(&lkStack));

}






/*******************************************************************************************************************************
 * @description：初始化链式栈
 * @param：s		指向链栈的头指针
 * @return：		状态码
 */
status initLinkStack(linkStack* s)
{
	(*s) = NULL;
	return OK;
}





/*******************************************************************************************************************************
 * @description：判空
 * @param：s
 * @return：	状态码
 */
status isLinkStackEmpty(linkStack* s)
{
	if (*s == NULL)
		return TRUE;
	else
		return FALSE;
}





/*******************************************************************************************************************************
 * @description：入栈
 * @param：s		栈顶指针
 * @param：e		要插入的元素
 * @return：		状态码
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
 * @description：出栈
 * @param：s		栈顶指针
 * @param：e		用于返回被删除的元素
 * @return：		状态码
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
 * @description：取栈顶元素
 * @param：s		栈顶指针
 * @return：		栈顶元素
 */
char getLinkStackTopElement(linkStack* s)
{
	if (isLinkStackEmpty(s))
		return ERROR;

	return (*s)->data;;
}





/*******************************************************************************************************************************
 * @description：打印链式栈内元素
 * @param：s
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
