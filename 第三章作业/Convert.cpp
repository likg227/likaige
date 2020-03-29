#include<iostream>
#include<stdexcept>
using namespace std;
int main() {
	try{
		int num, n;
		cout << "����������Ҫת�������ֺͶ�Ӧ�Ľ���" << endl;
		cin >> num >> n;
		if (n > 36 || n <= 1)
			throw out_of_range("�����������Ч���������������һ��С�ڵ���36");
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