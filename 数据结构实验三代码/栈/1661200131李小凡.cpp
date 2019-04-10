// zhan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

//栈的顺序存储结构，顺序表类
#include<iostream>
#include<conio.h>
#include <iomanip>
using namespace std;
//------------------------------栈的顺序存储结构---------------------------------------------
typedef int  ElemType;     // 数据元素的类型
const int MAXSIZE = 3;     // 数组的容量
class SqStack
{
private:
	ElemType  elem[MAXSIZE];
	int top;
public:
	SqStack(void);
	~SqStack() {};
	int  SetEmpty();
	void  push(ElemType e);
	ElemType pop();
	void PrintOut();
	int IsEmpty(void)const;
};
//-------------------------------------------------------------
SqStack::SqStack(void) :top(-1) { }
int  SqStack::SetEmpty()
{
	return top == -1;
}
//入栈
void  SqStack::push(ElemType e)
{
	if (top+1< MAXSIZE) {
		top++;
		elem[top] = e;
	}
	else {
		cout << "栈已存满" << endl;
		return;
	}
}
//出栈
ElemType SqStack::pop()
{
	ElemType s;
	if (IsEmpty()) {
		cout << "\n栈为空" << endl;
		return NULL;
	}
	else {
		s = elem[top--];
		return s;
	}
}
void SqStack::PrintOut()
{
	int k;
	cout << "\n PrintOut Data:\n";
	for (k = top; k >= 0; k--) cout << setw(6) << elem[k];
	cout << endl;
}
int SqStack::IsEmpty(void)const
{
	if (top == -1) return 1;
	else return 0;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	int i, k;
	ElemType e, x;
	SqStack  as;
	cout << "\n                           栈的顺序存储结构实现";
	do {
		cout << "\n\n";
		cout << "\n\n    1.插入一个数据元素e（入栈）";
		cout << "\n\n    2.删除一个元素，返回其值（出栈）";
		cout << "\n\n    3..结束程序";
		cout << "\n******************************** ";
		cout << "\n    请输入你的选择(1,2,3,4,5,6)";    cin >> k;
		switch (k) {
		case 1: {cout << "\n 入栈，数据 e=?";
			cin >> e;
			as.push(e);
			as.PrintOut();
		}break;
		case 2: {  cout << "\n 出栈";
			x = as.pop();
			cout << "\n  出栈元素数值= " << x;
			as.PrintOut();
		}break;
		default:break;
		} //switch
		cout << "\n--------------------------------- ";
	} while (k >= 1 && k < 3);
	cout << "\n          再见!";
	cout << "\n     按任意键，返回。";
	_getch(); return 0;
}
//-----------------------------------------------

