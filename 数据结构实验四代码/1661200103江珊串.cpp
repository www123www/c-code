#include <iostream.h>
#include <conio.h>
#include <string.h>
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
//将此成员函数补充完整，使得程序能够正确运行
String t;
	int i,j;
	if((pos>0&&pos<size+1)&&(num>=0&&pos+num<=size+1)){
		t.str=new char[num+1];
		t.size=num;
		for(i=0,j=pos-1;i<num;i++,j++)
			t.str[i]=str[j];
	}
	else{
		t.str=NULL;
		t.size=0;
	}
	return t;
}
//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t,int pos)
{
	
	String s;
	if(s.size+t.size>= *str)
		cout<<"溢出"<<endl;
	else{
		for(int i=s.size-1;i>=pos;--i)
			
			s.str[i+s.size]=s.str[i];

		for(i=0;i<=t.size;++i)
		s.str[pos++]=t.str[i];
		//s.size=s.size+t.size;
	}
}

//删除 :删除串中的一个子串
void  String:: Delete(int pos,int num)
{ String s;
	if((pos<1)||(pos>s.size))
		cout<<" "<<endl;

		int i=pos-1;
		int j=pos+num-1;

		while(str[i++]=str[j++]){
;
		}
		cout<<"删除成功";
	}

//将此成员函数补充完整，使得程序能够正确运行

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
	