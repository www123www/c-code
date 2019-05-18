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
 //生成新字符串函数
void String:: Creat()
 { char *s=new char(100); 
   cin>>s;
    size=strlen(s);
    str=new char[size];
    if(str==0)  cout<<"没有申请到空间！";
    strcpy(str,s);
 }
//输出
void String::Display()
{ int i;
  for(i=0;i<size;i++)  cout<<str[i];
  cout<<endl;
}
//求子串
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
//插入运算:在串对象s的pos位置后插入一个串t
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
}//把pos后的str存入临时变量里
size=size+t.size;
//清空pos之后的元素
for (int  q = pos; q < size; q++)
{
	str[q] = NULL;
}
//把要插入的插进pos之后
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
//删除 :删除串中的一个子串
void  String:: Delete(int pos,int num)
{ 
//将此成员函数补充完整，使得程序能够正确运行
	for (int i = pos-1; i < num; i++)
	{
		str[i] = NULL;//首先将目标的字符串置空
		str[i] = str[i + num];//将要长度后一位的提前覆盖到删除位置的值
		size--;//长度减一
	}
}
//主函数
int main(int argc, char* argv[])
{  int pos,num,k;
   String s,s1,t;
   do{  cout<<"\n\n    1.生成字符串"  ;
        cout<<"\n\n    2.取子串";
        cout<<"\n\n    3.插入子串s1";
        cout<<"\n\n    4.删除子串";
        cout<<"\n\n    5.结束程序";
        cout<<"\n******************************** ";
        cout<<"\n    请输入你的选择(1,2,3,4,5)";  cin>>k;
  switch(k){
       case 1:{cout<<"请输入一个字符串：";
               s.Creat();
               cout<<"字符串为：       ";     s.Display();
              }break;
       case 2:{ cout<<"请输入子串的截取位置pos及子串长度num"<<endl;
                cin>>pos>>num;
                t=s.SubString(pos,num);
                cout<<"你所取的子串为：　　";  t.Display();
               }break;
       case 3:{ cout<<"请输入子串插入位置pos"<<endl;
                cin>>pos;
                cout<<"请输入要插入的子串:  ";   s1.Creat();
                s.Insert(s1,pos);
                cout<<"插入后的字符串为：   ";  s.Display();
              }break;
       case 4:{ cout<<"请输入要删除子串的开始位置pos及子串长度num"<<endl;
               cin>>pos>>num;
               s.Delete(pos,num);
               cout<<"删除后的字符串为：   ";
               s.Display();
             }break;
     default:break;
  } //switch
     cout<<"\n--------------------------------- ";
}while(k>=1&&k<5);
  cout<<"\n          再见!";
  cout<<"\n     按任意键，返回。";
  return 0;
}
