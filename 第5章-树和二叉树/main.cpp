#pragma warning(disable:4996)	// �ر�4996����

#include <stdio.h>
#include "BinaryTree.h"		// ������
#include "TreeAndForest.h"	// ����ɭ��
#include "Huffman_CPP.h"	// Huffman����



int main()
{

	// Ĭ��ʹ����ʽ������
	// BinaryTreeMain();

	// ����ɭ��
	// TreeAndForestMain();

	// Huffman���룬C++ʵ��
	string filename = "test1.txt";
	FileHandler fh;
	fh.compress(filename);



	return 0;
}
