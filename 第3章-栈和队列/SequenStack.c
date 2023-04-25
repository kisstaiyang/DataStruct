#include <stdio.h>
#include <stdlib.h>
#include "SequenStack.h"



void SequenStackMain()
{
	/*******************************************************************************************************************************
	 * @description：测试初始化操作
	 */
	sequenStack spStack;
	initSequenStack(&spStack);


	/*******************************************************************************************************************************
	 * @description：测试入栈操作
	 */
	pushSequenStack(&spStack, 'a');
	pushSequenStack(&spStack, 'b');
	printf("栈中元素为：");
	printSequenStack(spStack);
	// 输出：栈中元素为：a b    ps：因为 a 先进栈，打印从栈底元素开始



	/*******************************************************************************************************************************
	 * @description：测试求长度操作
	 */
	printf("\n栈的长度为：%d\n", getSequenStackLength(spStack));
	// 输出：栈的长度为：2



	/*******************************************************************************************************************************
	 * @description：测试出栈操作
	 */
	char popSqStckChar;
	popSequenStack(&spStack, &popSqStckChar);
	printf("\n出栈元素为：%c\n", popSqStckChar);
	// 输出：出栈元素为：b   因为 b 后进栈

	printf("\n元素b出栈后，栈内元素为：");
	printSequenStack(spStack);
	// 输出：元素b出栈后，栈内元素为：a

	printf("\nb元素出栈后栈的长度为：%d\n", getSequenStackLength(spStack));
	// 输出：b元素出栈后栈的长度为：1



	/*******************************************************************************************************************************
	 * @description：测试清空操作
	 */
	clearSequenStack(&spStack);
	printf("\n清空栈后栈的长度为：%d\n", getSequenStackLength(spStack));
	// 输出：清空栈后栈的长度为：0

}






/*******************************************************************************************************************************
 * @description：初始化栈
 * @param：s		指向栈的指针
 * @return：		状态码
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
 * @description：判断栈是否为空
 * @param：s		栈
 * @return：		空返回 1；否则返回 0
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
 * @description：求顺序栈长度
 * @param：s		栈
 * @return：		栈的长度
 */
int getSequenStackLength(sequenStack s)
{
	return s.top - s.base;
}





/*******************************************************************************************************************************
 * @description：清空顺序栈
 * @param：s		指向栈的指针
 * @return：		状态码
 */
status clearSequenStack(sequenStack* s)
{
	if ((*s).base)
		(*s).top = (*s).base;
	return OK;
}





/*******************************************************************************************************************************
 * @description：销毁顺序栈
 * @param：s		栈
 * @return：		状态码
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
 * @description：入栈
 * @param：s		栈
 * @param：e		要入栈的元素
 * @return：		状态码
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
 * @description：出栈
 * @param：s		指向栈的指针
 * @param：e		用于返回要出栈的元素
 * @return：		状态码
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
 * @description：打印栈中元素
 * @param：s
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
