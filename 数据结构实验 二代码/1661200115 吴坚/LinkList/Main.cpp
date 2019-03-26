#include "pch.h"
#include<iostream>
#include "LinkList.h"
using namespace std;


//���Ժ���
int main()
{
	LinkList l;
	int i;
	do {
		cout << "*******************\n1.����������\n2.����������\n3.��ȡ������ĳ���\n4.�жϵ������Ƿ�Ϊ��\n5.���ҽڵ�\n";
		cout << "6.��β������ָ��Ԫ��\n7.��ָ��λ�ò���ָ��Ԫ��\n8.��ͷ������ָ��Ԫ��\n";
		cout << "9.��β��ɾ��Ԫ��\n10.ɾ������Ԫ��\n11.ɾ��ָ��Ԫ��\n12.��ͷ��ɾ��Ԫ��\n13 ����\n14 �ں���λ�ò���ֵ\n0.�˳�\n*******************" << endl;
		cout << "������Ҫִ�еĲ���: ";
		cin >> i;
		switch (i) {
		case 1:
			int n;
			cout << "�����뵥����ĳ���: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "�õ�����ĳ���Ϊ" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "�õ������ǿձ�" << endl;
			else
				cout << "�õ������ǿձ�" << endl;
			break;
		case 5:
			DataType data;
			cout << "������Ҫ���ҽڵ��ֵ: ";
			cin >> data;
			if (l.Find(data))
				cout << "�����д��ڸýڵ�" << endl;
			else
				cout << "�������Ҳ����ýڵ�" << endl;
			break;
		case 6:
			DataType endData;
			cout << "������Ҫ��β�������ֵ: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType  pointData;
			int index;
			cout << "������Ҫ���������: ";
			cin >> pointData;
			cout << "������Ҫ�������ݵ�λ��: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "������Ҫ��ͷ�������ֵ: ";
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
			cout << "������Ҫɾ��������: ";
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
			cout << "����һ��ֵ:";
			cin >> pData;
			l.InsertFitPos(pData);
			l.TravalLinkList();
		default: break;
		}//end switch
	} while (i != 0);    //end do-while
	system("pause");
	return 0;
}