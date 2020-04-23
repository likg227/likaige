#include "Huffman.h"
Huffman::Huffman(const string& s) {
	int* pfreq = new int[R];
	priority_queue<Node*, vector<Node*>, cmp>pq;
	st = new string[R];
	for (int i = 0; i < R; i++) {//初始化统计频率的数组和编译表
		pfreq[i] = 0;
		st[i] = "";
	}
	for (const auto a : s) {//统计频率
		pfreq[static_cast<unsigned int>(a)]++;
	
	}
	for (int i = 0; i < R; i++) {//将频率的数据导入优先队列
		
		if (pfreq[i]) {
			Node* temp = new Node(static_cast<char>(i), pfreq[i]);
			pq.push(temp);
		}
	}
	while (pq.size() > 1) {//生成霍夫曼树
		Node* ta = pq.top();
		pq.pop();
		Node* tb = pq.top();
		pq.pop();
		Node* tc = new Node('\0', ta->freq + tb->freq, ta, tb);
		pq.push(tc);
	}
	root = pq.top();

	CreateTable(st, root, "");//创建编译表
	PrintTable();

	//Encoding
	writeTrie(root);//把单词查找树写入比特流

	int num = s.size();//打印字符总数（没问题）
	string ts = "";
	while (num != 0) {
		int temp = num % 2;
		if (temp)
			ts += '1';
		else
			ts += '0';
		num /= 2;
	}
	reverse(ts.begin(), ts.end());
	if (ts.size() < 32) {
		string ps(32 - ts.size(), '0');
		ps += ts;
		cst += ps;
	}
	else {
		cst += ts;
	}
	//编译输入字符串
	string temp = "";
	for (const auto a : s) { 
		int i = a;
		cst += st[i];
		temp += st[i];
	}
	cout << "编码后的比特流：" << endl;
	cout << temp << endl;
	//cout << cst.size() << endl;
	//TreePrint(root, 10);
	cout << "--------------------------------------------------------------" << endl;
	cout << "Huffman Tree: " << endl;
	printBT(root);
	cout << "--------------------------------------------------------------" << endl;
	//cout << "--------------------------------------------------------------" << endl;
	//cout << "比特流：" << cst << endl;
	//cout << "--------------------------------------------------------------" << endl;

	//输出压缩率
	double x = temp.size();
	double y = static_cast<double>(s.size()) * 8;
	cout <<"压缩率："<< x / y *100<<"%"<< endl;
	cout << "--------------------------------------------------------------" << endl;
	delete[]pfreq;
	Delete(root);
}
void Huffman::CreateTable(string* s, Node* pn, string ss) {
	if (pn->isLeaf()) {
		s[static_cast<unsigned int>(pn->ch)] = ss;
		return;
	}
	CreateTable(s, pn->lch, ss + '0');
	CreateTable(s, pn->rch, ss + '1');
}
void Huffman::PrintTable() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "编译表： " << endl;
	for (int i = 0; i < R; i++) {
		if (st[i] != "") {
			char c = i;
			cout << c <<" "<<st[i]<< endl;
		}
	}
	cout << "--------------------------------------------------------------" << endl;
}
string Huffman::ToBinary(int num) {
	string s = "";
	while (num != 0) {
		int temp = num % 2;
		if (temp)
			s += '1';
		else
			s += '0';
		num /= 2;
	}
	reverse(s.begin(), s.end());
	if (s.size() < 8) {
		string ps(8 - s.size(), '0');
		ps += s;
		return ps;
	}
	return s;
}
void Huffman::writeTrie(Node* pn) {
	if (pn->isLeaf()) {
		cst += '1';
		cst += ToBinary(static_cast<int>(pn->ch));
		return;
	}
	cst += '0';
	writeTrie(pn->lch);
	writeTrie(pn->rch);
}
void Huffman::readTrie(Node*& pr, int& i) {
	if (cst[i] == '0') {
		pr = new Node();
		i++;
		readTrie(pr->lch, i);
		readTrie(pr->rch, i);
	}
	else if (cst[i] == '1') {
		int en = i + 9;
		int cn = 7;
		int num = 0;
		for (i = i + 1; i < en; i++) {
			if (cst[i] == '1')
				num += static_cast<int>(pow(2, cn));
			cn--;
		}
		pr = new Node(static_cast<char>(num));
		return;
	}
}
void Huffman::expand() {
	cout << "解码后的字符串：";
	Node* p;
	int i = 0;
	readTrie(p, i);

	int en = i + 32;
	int cn = 31;
	int num = 0;
	for (; i < en; i++) {
		if (cst[i] == '1')
			num += static_cast<int>(pow(2, cn));
		cn--;
	}
	for (int j = 0; j < num; j++) {
		Node* x = p;
		while (!x->isLeaf()) {
			if (cst[i] == '1') {
				x = x->rch;
			}
			else x = x->lch;
			i++;
		}
		cout << x->ch;
	}
	cout << endl;
	Delete(p);
}
void Huffman::Delete(Node* pn) {
	if (pn == NULL)
		return;
	Delete(pn->lch);
	Delete(pn->rch);
	delete pn;
}
Huffman::~Huffman() {
	delete[]st;
}
void Huffman::printBT(const string& prefix,  Node* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──");

		// print the value of the node
		if (node->isLeaf()) {
			cout << " " <<node->ch <<endl;
		}
		else cout << " " << "*" << endl;
		

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "│   " : "    "), node->lch, true);
		printBT(prefix + (isLeft ? "│   " : "    "), node->rch, false);
	}
}

void Huffman::printBT( Node* node)
{
	printBT("", node, false);
}
