#include "pch.h"
#include "SqList.h"
using namespace std;
int main()
{ //������������Ҫ��һ�����
	int i, k;   AddressBook e, x;
	//�����ʹ������������������ǵ������ݽṹ��    
	SqList  as;
	cout << "\n             ���Ա�˳��洢�ṹ��ʾ";
	do {     //��ʾ�˵�����
		cout << "\n\n";
		cout << "\n\n    1. ��������һ�����Ա� ";
		cout << "\n\n    2. ����һ������Ԫ�� ";
		cout << "\n\n    3. ɾ��һ��Ԫ�أ�������ֵ";
		cout << "\n\n    4. ��������";
		cout << "\n******************************** ";
		cout << "\n    ���������ѡ��(1,2,3,4)";  cin >> k;    //�����û���ѡ��
  //����kֵ��ת���Ӧ��case ��֧�����ִ��
		switch (k)
		{
		case 1: {  as.SetData(); as.PrintOut(); }break;
		case 2: { 
			cout << "\n �����λ�ã����� i,e=";
			cin >> i;
			
			as.Insert(i, e); 
		   as.PrintOut();
		}break;
		case 3: {  
			cout << "\n ɾ���ڼ���Ԫ��"; 
			cin >> i;
			x = as.Delet(i);
			cout << "\n  Ԫ����ֵ= "<<"ѧ��|����|�绰��  "<<x.sno<<"-"<<x.name<<"-"<<x.phone<<endl;
			as.PrintOut();
		}break;
		default:break;
		} //switch
	} while (k >= 1 && k < 4);    //
	cout << "\n          �ټ�!";  cout << "\n     ������������ء�";
	 
	return 0;
}//---------------------