#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstring>
using namespace std;

class String
{
public:
	String() {};
	~String() {};
	String SubString(int pos, int num);
	void Insert(String t, int pos);
	void Delete(int pos, int num);
	void Creat();
	void Display();
	void zh(String p, int pos);
private:
	char *str;
	int size;
};
//生成新字符串函数
void String::Creat()
{
	char *s = new char(100);
	cin >> s;
	size = strlen(s);
	str = new char[size];
	if (str == 0)  cout << "没有申请到空间！";
	strcpy(str, s);
}
//输出
void String::Display()
{
	int i;
	for (i = 0; i < size; i++)  cout << str[i];
	cout << endl;
}
//求子串
String String::SubString(int pos, int num)//pos为截取位置，num为长度
{
	String s1;  //定义个String 字符串
	if (pos >= 1 && pos + num - 1 <= size)//判断位置是否合法
	{
		int len = num + 1;
		char *cr = new char[len];
		int tab = 0;
		for (int i = pos - 1; i < pos + num - 1; i++)  //因为数组下标从0开始，所以要-1
		{
			cr[tab] = str[i]; //从i开始赋值，将值赋给cr
			tab++;
		}
		s1.size = len;
		s1.str = cr; //把子串的值赋给指针str
	}
	else
	{
		cout << "参数不合法" << endl;
		s1.size = 0;
		s1.str = NULL;
	}
	return s1; //返回子串
}

//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t, int pos)
{
	if (pos >= 0 && pos <= size)//判断位置是否合法
	{
		int t_len = t.size; //要插入的字符串长度
		int len = size + t_len; //总长度
		char *cr = new char[len]; //开辟空间
		int tab = 0;
		for (int i = 0; i < pos; i++) //将pos之前的值赋给新串
		{
			cr[i] = str[i];
		}
		for (int j = pos; j < pos + t_len; j++)//从pos开始进行插入,直到串t全部插入后结束
		{
			cr[j] = t.str[tab];
			tab++;
		}
		for (int k = pos + t_len; k < len; k++)//将原来插入前pos位置后的值重新添加进去
		{
			cr[k] = str[pos];
			pos++;
		}
		str = cr; //将新串的值赋给str
		size = len; //新串的长度赋给SIZE
	}
	else
	{
		cout << "输入不合法或字符串为空，插入失败。" << endl;
		return;
	}
}

//删除 :删除串中的一个子串,起始位置和删除长度
void  String::Delete(int pos, int num)
{
	if (pos >= 1 && pos + num - 1 <= size)//判断删除位置是否合法
	{
		int len = size - num; //删除后的长度
		char *cr = new char[len]; //开辟一个新的空间,用来存放删除后的字符串
		int tab = pos - 1; //删除时的下标位置
		if (pos != 1)
		{
			for (int i = 0; i < pos - 1; i++) //存放pos位置之前的字符串
			{
				cr[i] = str[i];
			}
		}
		for (int j = pos + num - 1; j < size; j++) //将要删除的串后面的值从tab开始进行赋值
		{
			cr[tab] = str[j];
			tab++;
		}
		str = cr;
		size = len;
	}
	else
	{
		cout << "输入不合法，删除失败。" << endl;
		return;
	}
}
//置换函数  用一串字符置换给定串中某指定位置开始的若干字符
void String::zh(String z, int pos)
{
	if (pos <= 0 && pos > size)//判断合法性
	{
		cout << "输入不合法,置换失败" << endl;
		return;
	}

	int zlen = z.size;
	int len = pos + zlen;
	char *cr = new char[len];

	int num = 0;

	for (int i = 0; i < pos; i++)
	{
		cr[i] = str[i];
	}

	for (int j = pos; j < len; j++)
	{
		cr[j] = z.str[num];
		num++;
	}

	str = cr;
	size = len;
}
//主函数
int main(int argc, char* argv[])
{
	int pos, num, k;
	String s, s1, t, p;
	do {
		cout << "\n\n    1.生成字符串";
		cout << "\n\n    2.取子串";
		cout << "\n\n    3.插入子串";
		cout << "\n\n    4.删除子串";
		cout << "\n\n    5.置换子串";
		cout << "\n\n    6.结束程序";
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
		case 5: { cout << "请输入置换串:";
			p.Creat();
			cout << "请输入置换位置:";
			cin >> pos;
			s.zh(p, pos);
			cout << "置换后的字符串为：   ";
			s.Display();
		}break;
		default:break;
		} //switch
		cout << "\n--------------------------------- ";
	} while (k >= 1 && k < 6);
	cout << "\n          再见!";
	cout << "\n     按任意键，返回。";
	return 0;
}

