#include "pch.h"
#include "SqList.h"
#include <iomanip>
SqList::SqList() {
	//初始化数组数据
	length = 0;
}
void SqList::SetData() {
	cout << "\n 输入人数lengh=" << endl;
	cin >> length;
	if (length <= Max_size) {
		 cout << "\n 输入 —— 学号|姓名|电话号"<<endl;
		for (int i = 0; i < length; i++) {
				
			cin >> data_book[i].sno;
			cin >> data_book[i].name;
			cin >> data_book[i].phone;
		}
	}
	else
		cout << "数组容量已满" << endl;
}

void SqList::Insert(int place, AddressBook data) {
	    if (length < Max_size) {
			if (place > Max_size) {
				cout << "数组越界" << endl;
			}
			else {
				cout << "输入学号|姓名|电话号" << endl;
				cin >> data.sno >> data.name >> data.phone;

				for (int p = 0; p < length; p++) {
					if (p == place) {
						//移动

						for (int x = length - 1; x >= place; x--)
							data_book[x + 1] = data_book[x];


						//赋值
						data_book[place].phone = data.phone;
						data_book[place].sno = data.sno;
						data_book[place].name = data.name;
					}
				}
				if (place > length) {
					//赋值
					data_book[place].phone = data.phone;
					data_book[place].sno = data.sno;
					data_book[place].name = data.name;
				}

				length++;

			}

		}
		else {
			cout << "数组容量已满" << endl;
		}
		
	
	


	
		
}

AddressBook SqList::Delet(int place) {
	AddressBook add_book;

		for (int elem_x = 0; elem_x < length; elem_x++) {
			if (elem_x == place) {//移动元素
				add_book = data_book[elem_x];
				for (int i = elem_x; i < length; i++) 
					data_book[i] = data_book[i+1];
				length--;
			}
		}
	return add_book;
}

void SqList::PrintOut() {
	cout<< "\n 通讯录总人数：" << length;
	cout << "\n PrintOut Data:\n";
	cout << setw(16) << "学号" << setw(20) << "姓名" << setw(20)<<"电话号" << setw(20)<<endl;
   
	for(int k=0;k<length;k++)
		cout << setw(16) << data_book[k].sno << setw(20) <<data_book[k].name<< setw(20) << setw(20) <<data_book[k].phone <<endl;

}