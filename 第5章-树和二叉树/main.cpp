#pragma warning(disable:4996)	// 关闭4996警告

#include <stdio.h>
#include "BinaryTree.h"		// 二叉树
#include "TreeAndForest.h"	// 树和森林
#include "Huffman_CPP.h"	// Huffman编码



int main()
{

	// 默认使用链式二叉树
	// BinaryTreeMain();

	// 树和森林
	// TreeAndForestMain();

	// Huffman编码，C++实现
	string filename = "test1.txt";
	FileHandler fh;
	fh.compress(filename);



	return 0;
}
