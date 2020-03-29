#include<iostream>
#include"Queue.h"
#include<stdexcept>
using namespace std;

int main() {
	try{
		Queue<int>a;
		for (int i = 0; i < 10; i++) {
			a.enqueue(i);
		}
		cout << a<<endl;
		a.dequeue();
		cout << a<<endl;
		a.Clear();
		cout << a<<endl;
		cout << a.length()<<endl;
		a.enqueue(10);
		cout << a << endl;
	}
	catch (logic_error err) {
		cout << err.what();
	}
	return 0;
}