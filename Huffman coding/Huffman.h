#include<queue>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int R = 256;//���峣��
//�ڵ���������
struct Node {
	char ch;
	int freq;
	Node* lch, * rch;
	Node(char c = '\0', int fre = 0, Node* lc = NULL, Node* rc = NULL) :ch(c), freq(fre), lch(lc), rch(rc) {};
	bool isLeaf() {
		return lch == NULL && rch == NULL;
	}
};
//�Ƚ�
struct cmp {
	bool operator()(Node* a, Node* b) {
		return (a->freq) > (b->freq);
	}
};


class Huffman {
public:
	Huffman(const string& s);
	void CreateTable(string* s, Node* pn, string ss);//���������
	void PrintTable();//��ӡ�����
	string ToBinary(int num);//���ַ�ת��Ϊ��λ�ı���
	void writeTrie(Node* pn);//��������д�뵽��������
	void readTrie(Node*& pr, int& i);//���ݱ��������ɵ�����
	void expand();//�������ɵĵ����������������
	void Delete(Node* pn);	//���ٵ�����
	void printBT(Node* node);
	void printBT(const string& prefix, Node* node, bool isLeft);
	~Huffman();
private:
	string* st;//�����
	Node* root;//���ڵ�
	string cst = "";//������
};