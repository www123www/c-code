//ջ��˳��洢�ṹ��˳�����
#include<iostream>
#include<conio.h>
#include <iomanip>
#include <string>
using namespace std;
//------------------------------ջ��˳��洢�ṹ---------------------------------------------
typedef char  ElemType;     // ����Ԫ�ص�����
typedef string  FlemType;
const int MAXSIZE=10;     // ���������
class SqStack
  { private:
      ElemType  elem[MAXSIZE];
	  FlemType  flemType;
      int top;
    public:
      SqStack( void);
      ~SqStack(){};
      int  SetEmpty();
      void  push(string e);
      ElemType pop();
      void PrintOut();
     int IsEmpty(void)const ; 

	 
};
//-------------------------------------------------------------
SqStack::SqStack( void):top(0){ }
int  SqStack::SetEmpty()
   { return top==0;
   }

void  SqStack::push(string f)
{ 
  int o=0;
  if (top==0)
  {
    elem[0]='#';
  }
  for(int i=0;i<f.length();i++)
  {
    if (f[i]=='(')
	{
	  elem[++top]=f[i];
	  
	}
	else if (f[i]==')' )
	{	
		if (elem[top] == '(')
		{
		 elem[top--];
		 o = 0;
		}
		else 
		{
			o = 1;
			break;
		}	
	}
	else if(f[i] != ')'&&f[i] != '(')
	{
		o = 2;
	}
  }
	if (elem[top] == '#'&& o==0)
	{
		memset(elem, NULL, sizeof(elem));
		cout<<"yes";
	}
	else if (elem[top] == '#'&&o == 2)
	{
		memset(elem, NULL, sizeof(elem));
		cout << "no";
	}
	else
	{
		memset(elem, NULL, sizeof(elem));
		cout << "no";
	}
}
ElemType SqStack::pop()
 {
//���˳�Ա��������������ʹ�ó����ܹ���ȷ����
	 ElemType e;
	 if(IsEmpty())
	 {
	 return -1;
	 }
	 else 
	 e=elem[top--];
	 return e;
}
void SqStack::PrintOut()
  {int k;
   cout<<"\n PrintOut Data:\n" ;
   for(k=top; k>=1;k--) 
	   cout<<setw(6)<<elem[k];
   cout<<endl;
 }
int SqStack::IsEmpty(void)const
{ if(top==0) return 1;
     else return 0;
 }
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{ int i,k;
  ElemType e,x;
  string f;
  SqStack  as;
   cout<<"\n                           ջ��˳��洢�ṹʵ��";
  do{
    cout<<"\n\n";
    cout<<"\n\n    1.����һ������Ԫ��e����ջ��";
    cout<<"\n\n    2.ɾ��һ��Ԫ�أ�������ֵ����ջ��";
    cout<<"\n\n    3..��������";
    cout<<"\n******************************** ";
    cout<<"\n    ���������ѡ��(1,2,3,4,5,6)";    cin>>k;
    switch(k){
       case 1:{cout<<"\n ��ջ������ e=";
               cin>>f;
               as.push(f);
               //as.PrintOut();
              }break;
       case 2:{  cout<<"\n ��ջ";
                 x=as.pop();
                 cout<<"\n  ��ջԪ����ֵ= "<<x;
                  as.PrintOut();
             }break;
       default:break;
         } //switch
     cout<<"\n--------------------------------- ";
    }while(k>=1&&k<3);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
  _getch(); return 0;
}
//-----------------------------------------------
 
