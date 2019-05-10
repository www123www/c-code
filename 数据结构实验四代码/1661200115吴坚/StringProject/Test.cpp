// StringProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "String.h"
#include <iostream>

using namespace std;
int main()
{
	int pos, num, k;
	String s, s1, t;
	do {
		cout << "\n\n    1.生成字符串";
		cout << "\n\n    2.取子串";
		cout << "\n\n    3.插入子串s1";
		cout << "\n\n    4.删除子串";
		cout << "\n\n    5.结束程序";
		cout << "\n******************************** ";
		cout << "\n    请输入你的选择(1,2,3,4,5)";  cin >> k;
		switch (k) {
		case 1: {cout << "请输入一个字符串：";
			s.Creat();
			cout << "字符串为：       ";     s.Display();
		}break;
		case 2: { cout << "请输入子串的截取位置pos及子串长度num" << endl;
			cin >> pos >> num;
			t = s.SubString(pos, num);
			cout << "你所取的子串为：　　";  t.Display();
		}break;
		case 3: { cout << "请输入子串插入位置pos" << endl;
			cin >> pos;
			cout << "请输入要插入的子串:  ";   s1.Creat();
			s.Insert(s1, pos);
			cout << "插入后的字符串为：   ";  s.Display();
		}break;
		case 4: { cout << "请输入要删除子串的开始位置pos及子串长度num" << endl;
			cin >> pos >> num;
			s.Delete(pos, num);
			cout << "删除后的字符串为：   ";
			s.Display();
		}break;
		default:break;
		} //switch
		cout << "\n--------------------------------- ";
	} while (k >= 1 && k < 5);
	cout << "\n          再见!";
	cout << "\n     按任意键，返回。";
	return 0;
}