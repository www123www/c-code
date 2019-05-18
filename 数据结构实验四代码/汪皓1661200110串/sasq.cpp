#include <iostream.h>
#include <conio.h>
#include <string.h>
//using namespace std;
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
	String s;
	
	if((pos>0&&pos<size+1)&&(num>=0&&pos+num<=size))
	{
		s.str=new char[num+1];
		s.size=num;

		for(int i=pos-1,int x=0;i<s.size+1;x++,i++)
		{
			s.str[x]=str[i];
		
		}
		s.str[num+1]='\0';
		
	}
	else{
		s.str=NULL;
		s.size=0;
	}
	return s;

}
//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t,int pos)
{
	String st;		
	st.str=new char[size-pos];	//将此成员函数补充完整，使得程序能够正确运行
	for(int a=0,int i=pos;i<size;i++,a++)
	{
		st.str[a]=str[i];
	}	
	for(int w=0,int l= pos;w<t.size;l++,w++)
	{
			str[l]=t.str[w];
			
	}
		
	for(int c=pos+t.size,int b=0;c<size+t.size+1;c++,b++)
	{
		str[c]=st.str[b];

			
	}
		size=t.size+size;
		cout<<size<<endl;

	


}
//删除 :删除串中的一个子串
void  String:: Delete(int pos,int num)
{ 
	for(int q =0,int i=pos;q<size;i++,q++)
		{
			str[i]=str[i+num];
			
		
		
		}size=size-num;//将此成员函数补充完整，使得程序能够正确运行
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
