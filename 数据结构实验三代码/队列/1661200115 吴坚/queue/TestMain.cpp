#include "pch.h"

#include "queue.h"
#include <iostream>
using namespace std;

int main() {
	ElemType e;
	int j;
	Se_queue h;
	int k;
	cout << "\n                           ���д洢�ṹ��ʾ";
	do {
		cout << "\n\n";
		cout << "\n\n    1.��������һ������";
		cout << "\n\n    2.�����������";
		cout << "\n\n    3.���";
		cout << "\n\n    4.����";
		cout << "\n\n    5.��������";
		cout << "\n******************************** ";
		cout << "\n    ���������ѡ��(1,2,3,4,5)";
		cin >> k;
		switch (k) {
		case 1: {Se_queue::Se_queue();
		}break;
		case 2: {h.Display();
		}break;
		case 3: {
			cout << "����  data=?";  cin >> e;
			h.Enqueue(e);
			h.Display();
		}break;
		case 4: {   e = h.Dequeue();
			if (e != -1)
				cout << "���ӵĽ��ֵ�ǣ�" << e << endl;
			h.Display();
		}break;
		default:break;
		}
		cout << "\n--------------------------------- ";
	} while (k >= 1 && k < 5);
	cout << "\n          �ټ�!";
	cout << "\n     ������������ء�";
	return 0;

}