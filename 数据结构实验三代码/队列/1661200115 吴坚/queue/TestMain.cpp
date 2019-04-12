#include "pch.h"

#include "queue.h"
#include <iostream>
using namespace std;

int main() {
	ElemType e;
	int j;
	Se_queue h;
	int k;
	cout << "\n                           队列存储结构演示";
	do {
		cout << "\n\n";
		cout << "\n\n    1.初步建立一个队列";
		cout << "\n\n    2.输出整个队列";
		cout << "\n\n    3.入队";
		cout << "\n\n    4.出队";
		cout << "\n\n    5.结束程序";
		cout << "\n******************************** ";
		cout << "\n    请输入你的选择(1,2,3,4,5)";
		cin >> k;
		switch (k) {
		case 1: {Se_queue::Se_queue();
		}break;
		case 2: {h.Display();
		}break;
		case 3: {
			cout << "进队  data=?";  cin >> e;
			h.Enqueue(e);
			h.Display();
		}break;
		case 4: {   e = h.Dequeue();
			if (e != -1)
				cout << "出队的结点值是：" << e << endl;
			h.Display();
		}break;
		default:break;
		}
		cout << "\n--------------------------------- ";
	} while (k >= 1 && k < 5);
	cout << "\n          再见!";
	cout << "\n     按任意键，返回。";
	return 0;

}