#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include<algorithm>
using namespace std;



struct ElemType              // ����Ԫ�ص�����
{
	int numb;
};

const int MAXSIZE = 3;     // ���������

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
		cout << "\n          ��!";
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

}//����

void Sqlist::PaiXu()
{
	for (int i = 0;i < length; i++) {
		int m = i;
		for (int j = i + 1;j < length;j++) {
			//�����j��Ԫ�رȵ�m��Ԫ��С����j��ֵ��m   
			if (elem[j].numb < elem[m].numb) {
				m = j;
			}
		}
		//����m��i����Ԫ�ص�λ��   
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


}///ɾ��


Sqlist::Sqlist() { length = 0;  }
void  Sqlist::SetData()     //��������
{
	cout << "\n ��������length=" << endl;
	cin >> length;
	if (length <= MAXSIZE) {	
		for (int i = 0;i < length;i++)
		{
			cout << "\n ����ֵ��";
			cin >> elem[i].numb;

		}
		PaiXu(); 
	}

	
	else cout << "\nlength is bigger than MAXSIZE";
}


void Sqlist::PrintOut()  //���
{
	cout << "\n ȫ����" << length;
	cout << "\n PrintOut Data:\n";
	cout << setw(16) << "ֵ"<< endl;
	for (int k = 0; k < length;k++)
	{
		cout << setw(16) << elem[k].numb << endl;
	}
}


int main()
{
	int i, k;  ElemType e, x;
	Sqlist  as;
	cout << "\n               ��ʾ";
	do {
		cout << "\n\n";
		cout << "\n\n    1. ��������һ��˳��� ";
		cout << "\n\n    2. ����һ������Ԫ�� ";
		cout << "\n\n    3. ɾ��һ��Ԫ�أ�������ֵ";
		cout << "\n\n    4. ��������";
		cout << "\n******************************** ";
		cout << "\n    ���������ѡ��(1,2,3,4)";  cin >> k;
		switch (k)
		{
		case 1:
		{  as.SetData(); as.PrintOut();  }break;
		case 2: {
			cout << "\n ��������� ���=?"; cin >> e.numb;
			as.Insert(e);  as.PrintOut();
		}break;
		case 3: { cout << "\n ɾ���ڼ���Ԫi=?";  cin >> i;
			x = as.Delet(i);
			if (x.numb != -1)
			{
				cout << "\n  ��ɾ����Ԫ����ֵ= " << setw(10) << x.numb ;
				as.PrintOut();
			}
		}break;
		case 4: {
			//as.diyiti();
		
		}break;
		default:break;
		} //switch
	} while (k >= 1 && k < 5);
	cout << "\n          �ټ�!";  cout << "\n     ������������ء�";
	_getch(); return 0;
}//---------------------------------------