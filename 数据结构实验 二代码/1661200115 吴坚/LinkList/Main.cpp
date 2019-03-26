#include "pch.h"
#include<iostream>
#include "LinkList.h"
using namespace std;


//测试函数
int main()
{
	LinkList l;
	int i;
	do {
		cout << "*******************\n1.创建单链表\n2.遍历单链表\n3.获取单链表的长度\n4.判断单链表是否为空\n5.查找节点\n";
		cout << "6.在尾部插入指定元素\n7.在指定位置插入指定元素\n8.在头部插入指定元素\n";
		cout << "9.在尾部删除元素\n10.删除所有元素\n11.删除指定元素\n12.在头部删除元素\n13 排序\n14 在合适位置插入值\n0.退出\n*******************" << endl;
		cout << "请输入要执行的操作: ";
		cin >> i;
		switch (i) {
		case 1:
			int n;
			cout << "请输入单链表的长度: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "该单链表的长度为" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "该单链表是空表" << endl;
			else
				cout << "该单链表不是空表" << endl;
			break;
		case 5:
			DataType data;
			cout << "请输入要查找节点的值: ";
			cin >> data;
			if (l.Find(data))
				cout << "链表中存在该节点" << endl;
			else
				cout << "链表中找不到该节点" << endl;
			break;
		case 6:
			DataType endData;
			cout << "请输入要在尾部插入的值: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType  pointData;
			int index;
			cout << "请输入要插入的数据: ";
			cin >> pointData;
			cout << "请输入要插入数据的位置: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "请输入要在头部插入的值: ";
			cin >> headData;
			l.InsertElemAtHead(headData);
			break;
		case 9:
			l.DeleteElemAtEnd();
			break;
		case 10:
			l.DeleteAll();
			break;
		case 11:
			DataType pointDeleteData;
			cout << "请输入要删除的数据: ";
			cin >> pointDeleteData;
			l.DeleteElemAtPoint(pointDeleteData);
			break;
		case 12:
			l.DeleteElemAtHead();
			break;
		case 13:
			
			l.Sort(l.GetLength());
			l.TravalLinkList();
		  break;
		case 14:
			DataType  pData;
			cout << "输入一个值:";
			cin >> pData;
			l.InsertFitPos(pData);
			l.TravalLinkList();
		default: break;
		}//end switch
	} while (i != 0);    //end do-while
	system("pause");
	return 0;
}