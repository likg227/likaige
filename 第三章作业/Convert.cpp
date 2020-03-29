#include<iostream>
#include<stdexcept>
using namespace std;
int main() {
	try{
		int num, n;
		cout << "请依次输入要转化的数字和对应的进制" << endl;
		cin >> num >> n;
		if (n > 36 || n <= 1)
			throw out_of_range("输入的数字无效，进制数必须大于一且小于等于36");
		int pos[100];
		int count = 0;
		while (num != 0) {
			int temp = num % n;
			pos[count++] = temp;
			num /= n;
		}
		if (n <= 10) {
			for (int i = count-1; i >= 0; i--) {
				cout << pos[i];
			}
		}
		else {
			for (int i = count - 1; i >= 0; i--) {
				if (pos[i] >= 10) {
					char temp = pos[i] + 55;
					cout << temp;
				}
				else {
					cout << pos[i];
				}
			}
		}
	}
	catch (out_of_range err) {
		cout << err.what();
	}


	return 0;
}