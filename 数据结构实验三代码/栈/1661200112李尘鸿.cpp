//---------------------------------------------------------------------------
//栈的顺序存储结构，顺序表类
#include<iostream>
#include<conio.h>
#include <iomanip>
#include <string>
using namespace std;


const int MAXSIZE=6;
class SqStack
{
private:
	int top;
	char  elem[MAXSIZE];
public:
	SqStack()
	{
		elem[0]='#';
		top=1;
	}
	void into(char e)//进
	{
		if(top>=MAXSIZE)
		{
			cout<<"栈溢出"<<endl;
		}
		else
		{
				elem[top++]=e;
		}
	}
	char chu()//出
	{
		if(top<=0)
		{
			cout<<"栈为空"<<endl;
			return false;
		}
		else
		{
			char x=elem[--top];
			return x;
		}
	}
};

int main()
{
	char x;
	SqStack Sq;
	string bds;
	int temp=0;//判断最后是否匹配成功
	cout<<"输入一个算数表达式:";
	cin>>bds;
	for(int i=0;i<bds.length();i++)
	{
		if(bds[i]=='(')//遇到左括号进行入栈操作
		{
			temp++;
			Sq.into(bds[i]);
		}
		if(bds[i]==')')//遇到左括号进行入栈操作
		{
			x=Sq.chu();
			if((x+1)==')')
			{
				temp--;
			}
			else
			{
				temp=1;
			}
		}
	}
	if(temp==0)//0：成功
	{
		cout<<"yes"<<endl;
	}
	else//1:不成功
	{
		cout<<"no"<<endl;
	}
	return 0;
}
