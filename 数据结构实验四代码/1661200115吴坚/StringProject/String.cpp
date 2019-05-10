#include "pch.h"
#include "String.h"
#include <string.h>

#include <iostream>

using namespace std;
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
String String::SubString(int pos, int num)
{    //位置pos 从0开始算
	String t;
	t.str= new char[num + 1];
	t.size = num;
	if (  pos>=0  && pos <  size&&
		  num>0   && num <= size&&
		  pos+num<=size
		){
		for (int j=0,i = pos; i <size,j<num; i++) {
			//从pos位置取num个字符拷贝到新char数组
			t.str[j++] = str[i];
	   }

	}
	else {
		cout << "输入的位置或数目异常" << endl;
		t.str = NULL;
		t.size = 0;
	}
	return t;

}
//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t, int pos)
{   
	//位置pos 从0开始算
	
	
	if (pos>=0&&pos<size) {
		//将pos位置后的串后移t.size
		for (int i = size - 1 + t.size, j = size - 1; j >= pos; i--, j--) {
			str[i] = str[j];

		}

		//插入操作
		for (int y = 0, i = pos; y < t.size; i++) {
			str[i] = t.str[y++];
		}
		//更新size
		size = size + t.size;
	}
	else {
		cout << "位置有异常";
	}
	
}
//删除 :删除串中的一个子串
void  String::Delete(int pos, int num)
{   //位置pos 从0开始算
	if (pos >= 0 && pos < size  &&
		num>0 && num <= size &&
		pos + num <= size) {
		//判断位置，数目合法性
		//将位置pos，数目为num的子串的后面子串往前移
		for (int i = pos, j = pos + num;j<size; i++,j++) {
			str[i] = str[j];
		}
		//更新size
		size = size - num;
	}
	else {

		cout << "位置有异常";
	}
	
}