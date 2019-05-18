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
String String::SubString(int pos,int num)//将此成员函数补充完整，使得程序能够正确运行
{ 
String t;
int i,j;
t.str=new char[num+1];
t.size=num;	
if((pos>0 && pos<size+1)&& (num>=0 && pos+num<=size+1)){
for(i=0,j=pos-1;i<num;i++,j++)
t.str[i]=str[j];
}
else{   //返回空串
t.str=NULL;//生成空串对象
}
return t;
}

//插入运算:在串对象s的pos位置后插入一个串t
void String::Insert(String t,int pos)//将此成员函数补充完整，使得程序能够正确运行
{

if (pos<=0 || pos>size)//插入的pos位置小于等于0或大于size
cout << "不合法" << endl;//输出不合法
else {
	int p = pos-1;   // p 用于保存插入位置的下标  pos-1
	if (pos < size)  //如果插入位置小于size  则需要让位
for (int i=size-1;i>=p;i--) //把从插入位置到末尾位置的元素移动
str[i+t.size]=str[i]; //需要移动出串t的长度个空间，以便把串t插入
else          //如果插入位置大于size  则说明串t需要插入到末尾
	p = size; //把 长度 赋值给 p 表示在末尾插入
for (int k=0 ; k < t.size; k++) //把 串t 插入
	str[k+p] = t.str[k];  //从 p 下标起 插入 
	size += t.size; //长度增加  与 串t长度 相加
	}
}

//删除 :删除串中的一个子串
void  String:: Delete(int pos,int num)//将此成员函数补充完整，使得程序能够正确运行
{ 
	if (pos<=0 || pos>size || num<=0 || (num+pos-1)>size) {  //合法性判断
	cout << "不合法" << endl;  //输出不合法
	}
else {
	for (int i = pos - 1; i < size - num; i++) //从删除位置开始  删除num个元素 
		str[i] = str[i + num]; //把后面的数据依次补到前面去
		size -= num; //长度减去num个
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