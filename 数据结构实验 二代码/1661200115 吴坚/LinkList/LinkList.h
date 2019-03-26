#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
//#define ERROR NULL
//����ڵ�����
struct Node
{
public:
	DataType data; //������
	Node * next; //ָ����
};
//����һ����������
class LinkList
{
public:
	LinkList();                  //����һ��������;    
	~LinkList(); //����һ��������;    
	void CreateLinkList(int n); //����һ��������   
	void TravalLinkList(); //�������Ա�   
	int GetLength(); //��ȡ���Ա��� 
	bool IsEmpty(); //�жϵ������Ƿ�Ϊ��
	Node * Find(DataType data); //���ҽڵ�  
	void InsertElemAtEnd(DataType data); //��β������ָ����Ԫ��    
	void InsertElemAtIndex(DataType data, int n); //��ָ��λ�ò���ָ��Ԫ��   
	void InsertElemAtHead(DataType data); //��ͷ������ָ��Ԫ�� 
	void DeleteElemAtEnd(); //��β��ɾ��Ԫ��
	void DeleteAll(); //ɾ����������  
	void DeleteElemAtPoint(DataType data); //ɾ��ָ��������    
	void DeleteElemAtHead(); //��ͷ��ɾ���ڵ�

	void Sort(int n);//ð������
	void InsertFitPos(DataType data);//�ں���λ�ò���
private:
	Node * head; //ͷ���
};



