#include<iostream>
#include<fstream>
#include"Huffman.h"
using namespace std;
int main() {
	string s;
	ifstream in("input.txt");
	getline(in, s);//���ı��ļ��ж�ȡһ���ַ���
	Huffman h(s);
	h.expand();
	cout << "--------------------------------------------------------------" << endl;
	return 0;
}