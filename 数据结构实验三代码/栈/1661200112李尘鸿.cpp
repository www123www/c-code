//---------------------------------------------------------------------------
//ջ��˳��洢�ṹ��˳�����
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
	void into(char e)//��
	{
		if(top>=MAXSIZE)
		{
			cout<<"ջ���"<<endl;
		}
		else
		{
				elem[top++]=e;
		}
	}
	char chu()//��
	{
		if(top<=0)
		{
			cout<<"ջΪ��"<<endl;
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
	int temp=0;//�ж�����Ƿ�ƥ��ɹ�
	cout<<"����һ���������ʽ:";
	cin>>bds;
	for(int i=0;i<bds.length();i++)
	{
		if(bds[i]=='(')//���������Ž�����ջ����
		{
			temp++;
			Sq.into(bds[i]);
		}
		if(bds[i]==')')//���������Ž�����ջ����
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
	if(temp==0)//0���ɹ�
	{
		cout<<"yes"<<endl;
	}
	else//1:���ɹ�
	{
		cout<<"no"<<endl;
	}
	return 0;
}
