#pragma once
#include <iostream>
#include <string>
using namespace std;
//Ҫ��ʹ�����Ա�ʵ��һ��ͨѶ¼��
//1.ͨѶ¼���ݰ���ѧ�š��������绰�������ݡ�
//2.���ͨѶ¼���ݵĽ�������¼�����ɾ�����ܡ�

struct AddressBook
{
	string sno;//ѧ��
	string name;//����
	string phone;//�绰


};
const int Max_size = 10;//�����������
class SqList {
private:
	AddressBook data_book[Max_size];
	int length;//���뼸������

public:
	SqList();
	~SqList() {}

	void SetData();//��������
	void Insert(int i, AddressBook data);
	AddressBook Delet(int i);
	void PrintOut();
};