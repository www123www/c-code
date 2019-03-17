#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include<algorithm>
using namespace std;



struct ElemType              // 数据元素的类型
{
	int numb;
};

const int MAXSIZE = 3;     // 数组的容量

class Sqlist
{
private:
	ElemType  elem[MAXSIZE];
	int length;
public:
	Sqlist(void);
	~Sqlist() { };
	void  SetData();
	void  Insert( ElemType e);
	void PaiXu();
	ElemType Delet(int i);
	void PrintOut();
};


void  Sqlist::Insert( ElemType e) 
{
	int o = 0;
	if (length== MAXSIZE)
	{
		cout << "\n          满!";
		return;
	}
	if (length==0)
	{
		elem[0].numb = e.numb;
		length = 1;
	}
	else
	{	
		if (length < MAXSIZE)
		{
			elem[MAXSIZE-1].numb = 0;
		}
		elem[length ] = e;
		length++;

		PaiXu(); 
	}

}//插入

void Sqlist::PaiXu()
{
	for (int i = 0;i < length; i++) {
		int m = i;
		for (int j = i + 1;j < length;j++) {
			//如果第j个元素比第m个元素小，将j赋值给m   
			if (elem[j].numb < elem[m].numb) {
				m = j;
			}
		}
		//交换m和i两个元素的位置   
		if (i != m) {
			int t = elem[i].numb;
			elem[i].numb = elem[m].numb;
			elem[m].numb = t;
		}
	}

}

ElemType Sqlist::Delet(int i)
{
	ElemType e;
	int p=0;
	e.numb = i;
	for (int j = 0; j < length; j++)
	{
		if (elem[j].numb == i)
		{

			elem[j] = elem[j+1];
			p++;
		}
	}
	length=length-p;
	return e;


}///删除


Sqlist::Sqlist() { length = 0;  }
void  Sqlist::SetData()     //初步建立
{
	cout << "\n 输入人数length=" << endl;
	cin >> length;
	if (length <= MAXSIZE) {	
		for (int i = 0;i < length;i++)
		{
			cout << "\n 输入值：";
			cin >> elem[i].numb;

		}
		PaiXu(); 
	}

	
	else cout << "\nlength is bigger than MAXSIZE";
}


void Sqlist::PrintOut()  //输出
{
	cout << "\n 全部：" << length;
	cout << "\n PrintOut Data:\n";
	cout << setw(16) << "值"<< endl;
	for (int k = 0; k < length;k++)
	{
		cout << setw(16) << elem[k].numb << endl;
	}
}


int main()
{
	int i, k;  ElemType e, x;
	Sqlist  as;
	cout << "\n               演示";
	do {
		cout << "\n\n";
		cout << "\n\n    1. 初步建立一个顺序表 ";
		cout << "\n\n    2. 插入一个数据元素 ";
		cout << "\n\n    3. 删除一个元素，返回其值";
		cout << "\n\n    4. 结束程序";
		cout << "\n******************************** ";
		cout << "\n    请输入你的选择(1,2,3,4)";  cin >> k;
		switch (k)
		{
		case 1:
		{  as.SetData(); as.PrintOut();  }break;
		case 2: {
			cout << "\n 插入的数据 编号=?"; cin >> e.numb;
			as.Insert(e);  as.PrintOut();
		}break;
		case 3: { cout << "\n 删除第几个元i=?";  cin >> i;
			x = as.Delet(i);
			if (x.numb != -1)
			{
				cout << "\n  被删除的元素数值= " << setw(10) << x.numb ;
				as.PrintOut();
			}
		}break;
		case 4: {
			//as.diyiti();
		
		}break;
		default:break;
		} //switch
	} while (k >= 1 && k < 5);
	cout << "\n          再见!";  cout << "\n     按任意键，返回。";
	_getch(); return 0;
}//---------------------------------------