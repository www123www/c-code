#include "pch.h"
#include "String.h"
#include <string.h>

#include <iostream>

using namespace std;
//�������ַ�������
void String::Creat()
{
	char *s = new char(100);
	cin >> s;
	size = strlen(s);
	str = new char[size];
	if (str == 0)  cout << "û�����뵽�ռ䣡";
	strcpy(str, s);
}
//���
void String::Display()
{
	int i;
	for (i = 0; i < size; i++)  cout << str[i];
	cout << endl;
}
//���Ӵ�
String String::SubString(int pos, int num)
{    //λ��pos ��0��ʼ��
	String t;
	t.str= new char[num + 1];
	t.size = num;
	if (  pos>=0  && pos <  size&&
		  num>0   && num <= size&&
		  pos+num<=size
		){
		for (int j=0,i = pos; i <size,j<num; i++) {
			//��posλ��ȡnum���ַ���������char����
			t.str[j++] = str[i];
	   }

	}
	else {
		cout << "�����λ�û���Ŀ�쳣" << endl;
		t.str = NULL;
		t.size = 0;
	}
	return t;

}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t, int pos)
{   
	//λ��pos ��0��ʼ��
	
	
	if (pos>=0&&pos<size) {
		//��posλ�ú�Ĵ�����t.size
		for (int i = size - 1 + t.size, j = size - 1; j >= pos; i--, j--) {
			str[i] = str[j];

		}

		//�������
		for (int y = 0, i = pos; y < t.size; i++) {
			str[i] = t.str[y++];
		}
		//����size
		size = size + t.size;
	}
	else {
		cout << "λ�����쳣";
	}
	
}
//ɾ�� :ɾ�����е�һ���Ӵ�
void  String::Delete(int pos, int num)
{   //λ��pos ��0��ʼ��
	if (pos >= 0 && pos < size  &&
		num>0 && num <= size &&
		pos + num <= size) {
		//�ж�λ�ã���Ŀ�Ϸ���
		//��λ��pos����ĿΪnum���Ӵ��ĺ����Ӵ���ǰ��
		for (int i = pos, j = pos + num;j<size; i++,j++) {
			str[i] = str[j];
		}
		//����size
		size = size - num;
	}
	else {

		cout << "λ�����쳣";
	}
	
}