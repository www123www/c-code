#include "pch.h"
#include "SqList.h"
#include <iomanip>
SqList::SqList() {
	//��ʼ����������
	length = 0;
}
void SqList::SetData() {
	cout << "\n ��������lengh=" << endl;
	cin >> length;
	if (length <= Max_size) {
		 cout << "\n ���� ���� ѧ��|����|�绰��"<<endl;
		for (int i = 0; i < length; i++) {
				
			cin >> data_book[i].sno;
			cin >> data_book[i].name;
			cin >> data_book[i].phone;
		}
	}
	else
		cout << "������������" << endl;
}

void SqList::Insert(int place, AddressBook data) {
	    if (length < Max_size) {
			if (place > Max_size) {
				cout << "����Խ��" << endl;
			}
			else {
				cout << "����ѧ��|����|�绰��" << endl;
				cin >> data.sno >> data.name >> data.phone;

				for (int p = 0; p < length; p++) {
					if (p == place) {
						//�ƶ�

						for (int x = length - 1; x >= place; x--)
							data_book[x + 1] = data_book[x];


						//��ֵ
						data_book[place].phone = data.phone;
						data_book[place].sno = data.sno;
						data_book[place].name = data.name;
					}
				}
				if (place > length) {
					//��ֵ
					data_book[place].phone = data.phone;
					data_book[place].sno = data.sno;
					data_book[place].name = data.name;
				}

				length++;

			}

		}
		else {
			cout << "������������" << endl;
		}
		
	
	


	
		
}

AddressBook SqList::Delet(int place) {
	AddressBook add_book;

		for (int elem_x = 0; elem_x < length; elem_x++) {
			if (elem_x == place) {//�ƶ�Ԫ��
				add_book = data_book[elem_x];
				for (int i = elem_x; i < length; i++) 
					data_book[i] = data_book[i+1];
				length--;
			}
		}
	return add_book;
}

void SqList::PrintOut() {
	cout<< "\n ͨѶ¼��������" << length;
	cout << "\n PrintOut Data:\n";
	cout << setw(16) << "ѧ��" << setw(20) << "����" << setw(20)<<"�绰��" << setw(20)<<endl;
   
	for(int k=0;k<length;k++)
		cout << setw(16) << data_book[k].sno << setw(20) <<data_book[k].name<< setw(20) << setw(20) <<data_book[k].phone <<endl;

}