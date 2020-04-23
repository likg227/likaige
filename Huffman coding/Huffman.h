#include<queue>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int R = 256;//定义常数
//节点数据类型
struct Node {
	char ch;
	int freq;
	Node* lch, * rch;
	Node(char c = '\0', int fre = 0, Node* lc = NULL, Node* rc = NULL) :ch(c), freq(fre), lch(lc), rch(rc) {};
	bool isLeaf() {
		return lch == NULL && rch == NULL;
	}
};
//比较
struct cmp {
	bool operator()(Node* a, Node* b) {
		return (a->freq) > (b->freq);
	}
};


class Huffman {
public:
	Huffman(const string& s);
	void CreateTable(string* s, Node* pn, string ss);//创建编译表
	void PrintTable();//打印编译表
	string ToBinary(int num);//将字符转化为八位的比特
	void writeTrie(Node* pn);//将单词树写入到比特流中
	void readTrie(Node*& pr, int& i);//根据比特流生成单词树
	void expand();//利用生成的单词树来解码比特流
	void Delete(Node* pn);	//销毁单词树
	void printBT(Node* node);
	void printBT(const string& prefix, Node* node, bool isLeft);
	~Huffman();
private:
	string* st;//编译表
	Node* root;//根节点
	string cst = "";//比特流
};