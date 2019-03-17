#include "pch.h"
#include "SqList.h"
using namespace std;
int main()
{ //声明程序所需要的一般变量
	int i, k;   AddressBook e, x;
	//声明和创建类对象，这个类往往是典型数据结构类    
	SqList  as;
	cout << "\n             线性表顺序存储结构演示";
	do {     //显示菜单内容
		cout << "\n\n";
		cout << "\n\n    1. 初步建立一个线性表 ";
		cout << "\n\n    2. 插入一个数据元素 ";
		cout << "\n\n    3. 删除一个元素，返回其值";
		cout << "\n\n    4. 结束程序";
		cout << "\n******************************** ";
		cout << "\n    请输入你的选择(1,2,3,4)";  cin >> k;    //接收用户的选择
  //根据k值，转向对应的case 分支程序段执行
		switch (k)
		{
		case 1: {  as.SetData(); as.PrintOut(); }break;
		case 2: { 
			cout << "\n 插入的位置，数据 i,e=";
			cin >> i;
			
			as.Insert(i, e); 
		   as.PrintOut();
		}break;
		case 3: {  
			cout << "\n 删除第几个元素"; 
			cin >> i;
			x = as.Delet(i);
			cout << "\n  元素数值= "<<"学号|姓名|电话号  "<<x.sno<<"-"<<x.name<<"-"<<x.phone<<endl;
			as.PrintOut();
		}break;
		default:break;
		} //switch
	} while (k >= 1 && k < 4);    //
	cout << "\n          再见!";  cout << "\n     按任意键，返回。";
	 
	return 0;
}//---------------------