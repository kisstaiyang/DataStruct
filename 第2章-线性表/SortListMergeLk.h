#pragma once

#ifndef SORTLISTMERGELK__H
#define SORTLISTMERGELK__H

#include "StatusCode.h"			// 状态码
#include "SingleLinkList.h"		// 调用之前写的单链表




/*************************************函数声明*************************************/

// 有序表合并--单链表实现
status unionSortList_Lk(singleLinkList* La, singleLinkList* Lb, singleLinkList* Lc);


// 主函数
void SortListMerge_LkListMain();



#endif // !SORTLISTMERGELK__H
