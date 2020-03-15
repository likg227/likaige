
#include<iostream>
#include<stdexcept>
#include <time.h>
#include<vector>
using namespace std;


template<typename t>
struct Node {
	t data;
	Node<t>* next;
};
//带头结点的单链表实现
template<typename T>
class Linklist {
	template <class T>
	friend void  merge_list  (Linklist<T>&a, Linklist<T>&b);
	template <class T>
	friend void Rmerge(Linklist<T>& a, Linklist<T>& b);
	template <class T>
	friend void Reverse_linklist(Linklist<T>& a);
	template<typename T>
	friend void Big_add(int* a, int sa, int* b, int sb);
	friend vector<int> Minus(Linklist<int>& la, Linklist<int>& lb);
public:
	Linklist() {
		front = new Node<T>;
		front->next = NULL;
		count = 0;
	}
	void Hconstruct(T a[], int n) {
		for (int i = 0; i < n; i++) {
			Node<T>* node = new Node<T>;
			count++;
			node->data = a[i];
			node->next = front->next;
			front->next = node;
		}
	}
	void Tconstruct(T a[], int n) {
		Node<T>* p = front;
		for (int i = 0; i < n; i++) {
			Node<T>* node = new Node<T>;
			p->next = node;
			count++;
			node->data = a[i];
			node->next = NULL;
			p = p->next;
		}
	}
	~Linklist() {
		Node<T>* p = front->next;
		while (p != NULL) {
			Node<T>* temp = p;
			p = p->next;
			delete temp;
		}
		delete front;
		cout << endl;
	}
	void print() {
		Node<T>* p = front->next;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	//insert应该有可以改进的地方
	void Insert(T num) {  
		Node<T>* p = front->next;
		count++;
		if (p == NULL) {
			Node<T>* node = new Node<T>;
			node->data = num;
			front->next = node;
			return;
		}
		if (num <= p->data)
		{
			Node<T>* node = new Node<T>;
			node->data = num;
			node->next = p;
			front->next = node;
			return;
		}
		while (p->next!= NULL) {
			if (num > p->data&& num <= p->next->data)
			{
				Node<T>* node = new Node<T>;
				node->data = num;
				node->next = p->next;
				p->next = node;
				return;
			}
			p = p->next;
		}
		Node<T>* node = new Node<T>;
		node->data = num;
		node->next = NULL;
		p->next = node;
		return;

	} 
	int getLength() { return count; }
	//解引用空指针也没事吗？
	T Delete(int index) {
		if (index < 0 || index >= count)
			throw out_of_range("the index is out of range");
		int num = 0;
		Node<T>* temp = front;
		while (num != index) {
			num++;
			temp = temp->next;
		}
		Node<T>* pa = temp->next;
		temp->next = pa->next;
		T da = pa->data;
		delete pa;
		return da;
	}
	int Search(T goal) {
	
		int num = 0;
		for (Node<T>* pa = front->next;( pa->data )!= goal; num++) {
			if ((pa->next)== NULL) {
				return -1;
			}
			
		    pa = pa->next;
		}
		return num;
	}
	
private:
	Node<T>* front;
	int count;
};
template<typename T>
void merge_list(Linklist<T>&a, Linklist<T>&b) {
	Node<T>* pa = a.front;
	Node<T>* pb = b.front->next;
	Node<T>* pbb = b.front;
	while (pb != NULL) {
		if ((pa->next->data) > (pb->data)) {
			Node<T>* node;
			pbb->next = pb->next;
			node = pb->next;
			pb->next = pa->next;
			pa->next = pb;
			pa = pb;
			pb = node;
		}
		else if ((pa->next->data) == pb->data) {
			pb = pb->next;
			pbb = pbb->next;
		}
		else if ((pa->next->data) < pb->data) {
			pa = pa->next;
		}
		if (pa->next == NULL) {
			pa->next = pb;
			pbb->next = NULL;
			break;
		}
	}
	a.print();
}
//5.3
template<typename T>
void Rmerge(Linklist<T>& a, Linklist<T>& b){
	Node<T>* pa = a.front->next;
	Node<T>* pb = b.front->next;
	b.front->next = NULL;
	Node<T>* temp=NULL;
	while (pa != NULL&& pb != NULL) {
		if (pa->data < pb->data) {
			Node<T>*te = pa;
			pa = pa->next;
			te->next = temp;
			a.front->next = te;
			temp = te;
		}
		else if (pa->data > pb->data) {
			Node<T>*te = pb;
			pb = pb->next;
			te->next = temp;
			a.front->next = te;
			temp = te;
		}
		else {
			Node<T>*te = pb;
			pb = pb->next;
			te->next = temp;
			a.front->next = te;
			temp = te;
		}
	}
	if (pa == NULL) {
		while (pb != NULL) {
			Node<T>*te = pb;
			pb = pb->next;
			te->next = temp;
			a.front->next = te;
			temp = te;
		}
	}
	else {
		while (pa != NULL) {
			Node<T>*te = pa;
			pa = pa->next;
			te->next = temp;
			a.front->next = te;
			temp = te;
		}
	}
	}
//5.4
template<typename T>
void Reverse_linklist(Linklist<T>& a) {
	Node<T>* pa = a.front->next;
	Node<T>* temp = NULL;
	while (pa != NULL) {
		
		Node<T>* te = pa;
		pa = pa->next;
		te->next = temp;
		a.front->next = te;
		temp = te;
	}
}
template<typename T>
void Reverse_array(T *a,const int size){
	for (int i = 0; i <= (((size + 1) / 2) - 1); i++)
		swap(a[i], a[size - 1 - i]);
}
template<typename T>
void Big_add(int *a,int sa,int *b,int sb) {
	Linklist<T> la;
	la.Hconstruct(a, sa);
	Linklist<T>lb;
	lb.Hconstruct(b, sb);
	Linklist<T>lc;
	Node<T>* pa = la.front->next;
	Node<T>* paa = la.front;
	Node<T>* pb = lb.front->next;
	Node<T>* pbb = lb.front;
	Node<T>* pc = lc.front;
	int num=0;
	while (pb != NULL && pa != NULL) {
		if ((pa->data + pb->data + num) >= 10) {
			Node<T>* newp = new Node<T>;
			newp->data = (pa->data + pb->data + num) % 10;
			newp->next = NULL;
			pc->next = newp;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			paa = paa->next;
			pbb = pbb->next;
			num = 1;
		}
		else {
			Node<T>* newp = new Node<T>;
			newp->data = (pa->data + pb->data + num) % 10;
			newp->next = NULL;
			pc->next = newp;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			paa = paa->next;
			pbb = pbb->next;
			num = 0;
		}
	}
	if (pa == NULL && pb == NULL){
		if ((paa->data + pbb->data +num)>= 10) {
			Node<T>* newp = new Node<T>;
			newp->data = 1;
			newp->next = NULL;
			pc->next = newp;
	   }
	}
	else if (pa == NULL) {
		pc->next = pb;
		pbb->next = NULL;
		pc = pc->next;
		if (num == 1 ) {
		  while (num == 1 && pc->next != NULL) {
			  if (pc->data + num < 10) {
				  pc->data += num;
				  num = 0;
			}
			  else {
				  pc->data = 0;
				  num = 1;
				  pc = pc->next;
			  }
		  }
		  if (num == 1) {
			  if (pc->data + num < 10) {
				  pc->data += num;
			  }
			  else {
				  Node<T>* newp = new Node<T>;
				  newp->data = 1;
				  newp->next = NULL;
				  pc->next = newp;
				  pc->data = 0;
			  }
		  }
		}
	}
	else {
		pc->next = pa;
		paa->next = NULL;
		pc = pc->next;
		if (num == 1) {
			while (num == 1 && pc->next != NULL) {
				if (pc->data + num < 10) {
					pc->data += num;
					num = 0;
				}
				else {
					pc->data = 0;
					num = 1;
					pc = pc->next;
				}
			}
			if (num == 1) {
				if (pc->data + num < 10) {
					pc->data += num;
				}
				else {
					Node<T>* newp = new Node<T>;
					newp->data = 1;
					newp->next = NULL;
					pc->next = newp;
					pc->data = 0;
				}
			}
		}
	}
	Reverse_linklist(lc);
	Node<T>* p = lc.front->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
int  compare(int* a, int sa, int* b, int sb) {
	if (sa > sb)
		return 1;
	else if (sa < sb)
		return -1;
	else if (sa == sb) {
		for (int i = 0; i <sa; i++) {
			if (a[i] > b[i])
				return 1;
			else if (a[i] < b[i])
				return -1;
			else
				continue;
		}
	}
	return 0;
}
vector<int>Minus(Linklist<int>& la, Linklist<int>& lb) {
	Linklist<int>lc;
	Node<int>* pa = la.front->next;
	Node<int>* paa = la.front;
	Node<int>* pb = lb.front->next;
	Node<int>* pc = lc.front;
	while (pb != NULL) {
		if ((pa->data) >= (pb->data)) {
			Node<int>* newp = new Node<int>;
			newp->data = pa->data - pb->data;
			newp->next = NULL;
			pc->next = newp;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			paa = paa->next;
		}
		else {
			Node<int>* newp = new Node<int>;
			newp->data = 10+( pa->data) - (pb->data);
			((pa->next)->data)--;
			newp->next = NULL;
			pc->next = newp;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			paa = paa->next;
		}
	}
	if (pa != NULL) {
		paa->next = NULL;
		pc->next = pa;
	}
	Reverse_linklist(lc);
	Node<int>* pcc = (lc.front)->next;
	while ( (pcc!=NULL)&&(pcc->data) == 0) {
		pcc = pcc->next;
	}
	vector<int>a;
	while (pcc != NULL) {
		a.push_back(pcc->data);
		pcc = pcc->next;
	}
	return a;
}
void Big_min(int* a, int sa, int* b, int sb) {
	Linklist<int> la;
	la.Hconstruct(a, sa);
	Linklist<int>lb;
	lb.Hconstruct(b, sb);
	if (compare(a, sa, b, sb) == 1) {
		auto va = Minus(la,lb);
		
		for (const auto& s : va)
			cout << s;
	}
	else if (compare(a, sa, b, sb) == -1) {
		auto va = Minus(lb,la);
		cout << "-";
		for (const auto& s :va)
			cout << s;
		
	}
	else
		cout << 0;
}
int main()
{
	try{
	const int N =100;
	int a[N];
	int b[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i + 5;
	}
	srand((unsigned int)(time(NULL)));
	int sna = 2, snb =5;
	int* sa = new int[sna];
	int* sb = new int[snb];
	sa[0] = rand() % 9 + 1;
	sb[0] = rand() % 9 + 1;

	for (int i = 1; i < sna; i++) {
		sa[i] = rand() % 10;
	}

	for (int i = 0; i < sna; i++) {
		cout << sa[i];
	}
	cout << endl;
	for (int i = 1; i < snb; i++) {
		sb[i] = rand() % 10;
	}
	for (int i = 0; i < snb; i++) {
		cout << sb[i];
	}
	cout << endl;
	Big_min(sa, sna, sb, snb);
	//Big_add<int>(sa, sna, sb, snb);
	delete[]sa;
	delete[]sb;
	/*for (const auto s : a) {
		cout << s << " ";
	}
	cout << endl;*/
	Linklist<int> Htest;
	//头插法
	Htest.Hconstruct(a, N);
	//Htest.print();
	Linklist<int>Ttest;
	Linklist<int>test2;
	//尾插法
	Ttest.Tconstruct(a, N);
	test2.Tconstruct(b, N);

	//插入
	//Ttest.Insert(100);
	////删除
	//auto da=Ttest.Delete(5);
	////打印
	//Ttest.print();
	////查找
	//int search_index= Ttest.Search(3);
	//cout << search_index << endl;
	////合并
	//merge_list(Ttest, test2);
	////merge(Ttest, test2);
	//Reverse_linklist(test2);
	//test2.print();
	//for (const auto& s : a) {
	//	cout << s << " ";
	//}
	//cout << endl;
	//Reverse_array(a, N);
	//for (const auto& s : a) {
	//	cout << s << " ";
	//}

	}
	catch (out_of_range err) {
		cout << err.what();
	}
}