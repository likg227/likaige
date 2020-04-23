#include<iostream>
#include<fstream>
#include"Huffman.h"
using namespace std;
int main() {
	string s;
	ifstream in("input.txt");
	getline(in, s);//从文本文件中读取一行字符串
	Huffman h(s);
	h.expand();
	cout << "--------------------------------------------------------------" << endl;
	return 0;
}