#include <iostream>
#include <conio.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;
class String
{public:
     String(){};
     ~String(){};
     String SubString(int pos,int num);
     void Insert(String t,int pos);
     void Delete(int pos,int num);
     void Creat();
     void Display();
  private:
     char *str;
     int size;
 };
 //�������ַ�������
void String:: Creat()
 { char *s=new char(100); 
   cin>>s;
    size=strlen(s);
    str=new char[size];
    if(str==0)  cout<<"û�����뵽�ռ䣡";
    strcpy(str,s);
 }
//���
void String::Display()
{ int i;
  for(i=0;i<size;i++)  cout<<str[i];
  cout<<endl;
}
//���Ӵ�
String String::SubString(int pos,int num)
{ 
	String m; 
	int i=0;
	m.size=num;
	m.str=new char[num+1];
	for(int j=pos-1;j<num+1;j++)
	{
			m.str[i]=str[j];
			i++;
	}
	return m;
}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t,int pos)
{
	String tmp;
	tmp.str = new char[size - (pos-1)];
	tmp.size = size - pos;
	int y=0;
	int r = 0;
for (int i = pos-1; i < size; i++)
{
	
	tmp.str[r++] = str[i];
	tmp.size = r;
}//��pos���str������ʱ������
size=size+t.size;
//���pos֮���Ԫ��
for (int  q = pos; q < size; q++)
{
	str[q] = NULL;
}
//��Ҫ����Ĳ��pos֮��
int p = pos - 1;
for (int j = 0;j < t.size;j++)
{
	str[p++] = t.str[j];
}



for (int x =p;x < size;x++)
{
	str[x] = tmp.str[y];
	y = y++;
}

}
//ɾ�� :ɾ�����е�һ���Ӵ�
void  String:: Delete(int pos,int num)
{ 
//���˳�Ա��������������ʹ�ó����ܹ���ȷ����
	for (int i = pos-1; i < num; i++)
	{
		str[i] = NULL;//���Ƚ�Ŀ����ַ����ÿ�
		str[i] = str[i + num];//��Ҫ���Ⱥ�һλ����ǰ���ǵ�ɾ��λ�õ�ֵ
		size--;//���ȼ�һ
	}
}
//������
int main(int argc, char* argv[])
{  int pos,num,k;
   String s,s1,t;
   do{  cout<<"\n\n    1.�����ַ���"  ;
        cout<<"\n\n    2.ȡ�Ӵ�";
        cout<<"\n\n    3.�����Ӵ�s1";
        cout<<"\n\n    4.ɾ���Ӵ�";
        cout<<"\n\n    5.��������";
        cout<<"\n******************************** ";
        cout<<"\n    ���������ѡ��(1,2,3,4,5)";  cin>>k;
  switch(k){
       case 1:{cout<<"������һ���ַ�����";
               s.Creat();
               cout<<"�ַ���Ϊ��       ";     s.Display();
              }break;
       case 2:{ cout<<"�������Ӵ��Ľ�ȡλ��pos���Ӵ�����num"<<endl;
                cin>>pos>>num;
                t=s.SubString(pos,num);
                cout<<"����ȡ���Ӵ�Ϊ������";  t.Display();
               }break;
       case 3:{ cout<<"�������Ӵ�����λ��pos"<<endl;
                cin>>pos;
                cout<<"������Ҫ������Ӵ�:  ";   s1.Creat();
                s.Insert(s1,pos);
                cout<<"�������ַ���Ϊ��   ";  s.Display();
              }break;
       case 4:{ cout<<"������Ҫɾ���Ӵ��Ŀ�ʼλ��pos���Ӵ�����num"<<endl;
               cin>>pos>>num;
               s.Delete(pos,num);
               cout<<"ɾ������ַ���Ϊ��   ";
               s.Display();
             }break;
     default:break;
  } //switch
     cout<<"\n--------------------------------- ";
}while(k>=1&&k<5);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
  return 0;
}
