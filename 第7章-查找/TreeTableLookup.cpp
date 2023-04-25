#include <iostream>
#include "TreeTableLookup.h"
using namespace std;



/*******************************************************************************************************************************
 * @description：二叉排序树的查找算法
 * @param：T
 * @param：key
 * @return：
 */
BSTree BSTSearch(BSTree T, keyType key) {
	if (T == NULL) {
		return NULL;
	}
	else if (key == T->data.key) {
		return T;
	}
	else if (key < T->data.key) {
		return BSTSearch(T->leftChild, key);
	}
	else {
		return BSTSearch(T->righrChild, key);
	}
}





/*******************************************************************************************************************************
 * @description：二叉排序树的插入算法
 * @param：T
 * @param：e
 * @return：
 */
BSTree BSTInsert(BSTree& T, elemType e) {
	if (T == NULL) {
		T = (BSTree)malloc(sizeof(BSTNode));
		if (T) {
			T->data = e;
			T->leftChild = T->righrChild = NULL;
		}
	}
	else if (e.key < T->data.key) {
		T->leftChild = BSTInsert(T->leftChild, e);
	}
	else if (e.key > T->data.key) {
		T->righrChild = BSTInsert(T->righrChild, e);
	}
	return T;
}






/*******************************************************************************************************************************
 * @description：二叉排序树的生成算法
 * @param：T
 * @param：a
 * @param：n
 */
void CreateBST(BSTree& T, keyType a[], int n) {
	T = NULL;
	for (int i = 0; i < n; i++) {
		elemType e;
		e.key = a[i];
		BSTInsert(T, e);
	}
}







/*******************************************************************************************************************************
 * @description：二叉排序树的删除算法
 * @param：T
 * @param：key
 * @return：
 */
BSTree BSTDelete(BSTree& T, keyType key) {
	if (T == NULL) {
		return NULL;
	}
	else if (key < T->data.key) {
		T->leftChild = BSTDelete(T->leftChild, key);
	}
	else if (key > T->data.key) {
		T->righrChild = BSTDelete(T->righrChild, key);
	}
	else {
		if (T->leftChild == NULL) {
			BSTree p = T;
			T = T->righrChild;
			free(p);
		}
		else if (T->righrChild == NULL) {
			BSTree p = T;
			T = T->leftChild;
			free(p);
		}
		else {
			BSTree p = T->righrChild;
			while (p->leftChild != NULL) {
				p = p->leftChild;
			}
			T->data = p->data;
			T->righrChild = BSTDelete(T->righrChild, p->data.key);
		}
	}
	return T;
}







