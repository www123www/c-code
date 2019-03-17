#pragma once
#include <iostream>
#include <string>
using namespace std;
//要求：使用线性表实现一个通讯录，
//1.通讯录内容包含学号、姓名、电话三项数据。
//2.完成通讯录数据的建立，记录插入和删除功能。

struct AddressBook
{
	string sno;//学号
	string name;//姓名
	string phone;//电话


};
const int Max_size = 10;//数组最大容量
class SqList {
private:
	AddressBook data_book[Max_size];
	int length;//存入几条数据

public:
	SqList();
	~SqList() {}

	void SetData();//输入数据
	void Insert(int i, AddressBook data);
	AddressBook Delet(int i);
	void PrintOut();
};