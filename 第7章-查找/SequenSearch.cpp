#include <iostream>
#include <map>
#include <random>
#include "SequenSearch.h"

using namespace std;



void SequenSearchMain()
{
	SequenSearchList list;
	initSequenSearchList(list);
	createSequenSearchList(list);
	cout << "随机生成的顺序表中的元素为：";
	printSequenSearchList(list);

	cout << "\n查找元素3的位置\n" << endl;

	int index = sequensSearchList(list, 3);
	cout << "顺序查找的结果为： " << index << endl;

	index = binarySearchList_notRecursion(list, 3);
	cout << "折半查找--非递归算法查找的结果为：" << index << endl;

	index = binarySearchList_recursion(list, 3, 1, list.length);
	cout << "折半查找--递归算法查找的结果为：" << index << endl;
}






/*******************************************************************************************************************************
 * @description：顺序查找
 * @param：list
 * @param：key
 * @return：找到返回下标，没找到返回0
 */
int sequensSearchList(SequenSearchList list, keyType key)
{
	for (int i = list.length; i >= 1; --i) {
		if (list.elem[i].key == key) {
			return i;
		}
	}
	return 0;
}






/*******************************************************************************************************************************
 * @description：折半查找--非递归算法
 * @param：list
 * @param：key
 * @return：找到返回下标，没找到返回0
 */
int binarySearchList_notRecursion(SequenSearchList list, keyType key)
{
	int low = 1;
	int high = list.length;
	int mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (list.elem[mid].key == key) {
			return mid;
		}
		else if (list.elem[mid].key > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return 0;
}







/*******************************************************************************************************************************
 * @description：折半查找--递归算法
 * @param：list
 * @param：key
 * @param：low
 * @param：high
 * @return：找到返回下标，没找到返回0
 */
int binarySearchList_recursion(SequenSearchList list, keyType key, int low, int high)
{
	if (low > high) {
		return 0;
	}
	int mid = (low + high) / 2;
	if (list.elem[mid].key == key) {
		return mid;	// 递归出口
	}
	else if (list.elem[mid].key > key) {
		return binarySearchList_recursion(list, key, low, mid - 1);
	}
	else {
		return binarySearchList_recursion(list, key, mid + 1, high);
	}
}






/*******************************************************************************************************************************
 * @description：初始化顺序表
 * @param：list
 * @return：
 */
status initSequenSearchList(SequenSearchList& list)
{
	list.elem = new ElemType[11];
	if (!list.elem) {
		exit(OVERFLOW);
	}
	list.length = 0;
	return OK;
}






/*******************************************************************************************************************************
 * @description：创建顺序表
 * @param：list
 * @return：
 */
status createSequenSearchList(SequenSearchList& list)
{
	// 生成不重复的随机数
	srand((unsigned)time(NULL));
	vector<int> temp;
	for (int i = 1; i <= 15; ++i) {
		temp.push_back(i);
	}
	random_shuffle(temp.begin(), temp.end());


	for (int i = 1; i <= 10; ++i) {
		list.elem[i].key = temp[i];
		++list.length;
	}
	return OK;
}






/*******************************************************************************************************************************
 * @description：打印顺序表
 * @param：list
 */
void printSequenSearchList(SequenSearchList list)
{
	for (int i = 1; i <= list.length; ++i) {
		cout << list.elem[i].key << " ";
	}
	cout << endl;
}
