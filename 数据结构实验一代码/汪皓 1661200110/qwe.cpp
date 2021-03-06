#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <string.h>
//--------------------------------------------------------------------
struct ElemType              // 数据元素的类型
{ 
	int numb;
	char name[20];
	int tel;
};

const int MAXSIZE=5;     // 数组的容量

class Sqlist
{
private:
	ElemType  elem[MAXSIZE];
	int length;
    public:
		Sqlist( void);
		~Sqlist(){ };
void  SetData();
		void  Insert( int i, ElemType e);
		ElemType Delet(int i);
		void PrintOut();
};
//-------------------------------------------------------------
Sqlist::Sqlist( ) { length=0;}
void  Sqlist::SetData( )     //初步建立一个通讯录 
{
	cout<<"\n 输入人数length="<<endl;
	cin>>length;
    if(length<= MAXSIZE)
		for(int i=0;i<length;i++)
		{ 
			cout<<"\n 输入学号：";  
			cin>>elem[i].numb;
			cout<<"\n 输入姓名："; 
			cin>> elem[i].name;
			cout<<"\n 输入电话号：="; 
			cin>>elem[i].tel;
		}
    else cout<<"\nlength is bigger than MAXSIZE";
}
void  Sqlist::Insert( int i, ElemType e) //请完成此函数
{
	if(length> MAXSIZE)
	{
		cout<<"数组越界"<<endl;	
	
	}
	if(i-1>=0&&i-1<=length)
		{
			for( int z=length;z=i-1;z--)
			{	
				elem[i]=elem[i-1];									
				
			}	
			elem[i-1]=e;length++;
		
		}
	if(i-1<0||i-1>length){cout<<"位置出错"<<endl;}
		
}
ElemType Sqlist::Delet(int i)
{
		if(i-1>length)
		{
			cout<<"输入位置违法"<<endl;
		
		}
		if(i-1>=0&&i-1<=length)
		{
			ElemType e;
			e=elem[i-1];
			for(int c=length;c>=i-1;c--)
			{
				
			
				elem[i-1]=elem[i];
				
			}
		
		
			length--;
			return  e;
		}
		else
		{
			cout<<"删除位置没有元素"<<endl;		
			

		}
	
		
	
//程序填空2
}
void Sqlist::PrintOut()  //输出
 { 
	cout<<"\n 通讯录总人数："<<length;
	cout<<"\n PrintOut Data:\n";
	cout<<setw(16)<<"学号"<<setw(20)<<"姓名"<<setw(20)<<"电话号"<<endl;
	for(int k=0; k<length;k++)      
	{ 
		cout<<setw(16)<<elem[k].numb<<setw(20)<<elem[k].name<<setw(20)<<elem[k].tel<<endl;
	}
 }
//--------------------------------------------------
int main( )
{ 
	int i,k;  ElemType e,x;
  Sqlist  as;
  cout<<"\n               通讯录演示";
  do{
      cout<<"\n\n";
      cout<<"\n\n    1. 初步建立一个通讯录（线性表） ";
      cout<<"\n\n    2. 插入一个数据元素 ";
      cout<<"\n\n    3. 删除一个元素，返回其值";
      cout<<"\n\n    4. 结束程序";
      cout<<"\n******************************** ";
      cout<<"\n    请输入你的选择(1,2,3,4)";  cin>>k;
	  switch(k)
	  { 
	  case 1:
		  {  as.SetData(); as.PrintOut();  }break;
	  case 2:{ cout<<"\n 插入的位置， i=?"; cin>>i;
                   cout<<"\n 插入的数据 编号=?"; cin>>e.numb;
                   cout<<"\n 插入的数据 姓名=?"; cin>>e.name;
                   cout<<"\n 插入的数据 电话号=?"; cin>>e.tel;
                   as.Insert(i,e);  as.PrintOut();
                 }break;
	  case 3:{ cout<<"\n 删除第几个元i=?";  cin>>i;
                  x=as.Delet(i);
                  if(x.numb!=-1)
                  {	
cout<<"\n  被删除的元素数值= "<<setw(10)<<x.numb<< setw(10)<<x.name<<setw(10)<<x.tel;
                      as.PrintOut();
}
                 }
		  break;
	  default:break;
	  } //switch
  }
  while(k>=1&&k<4);
  cout<<"\n          再见!";  cout<<"\n     按任意键，返回。";
  _getch(); 
  return 0;
}//-----------------------------------------------   
