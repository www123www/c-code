#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
//#define ERROR NULL
//定义节点类型
struct Node
{
public:
	DataType data; //数据域
	Node * next; //指针域
};
//构建一个单链表类
class LinkList
{
public:
	LinkList();                  //构建一个单链表;    
	~LinkList(); //销毁一个单链表;    
	void CreateLinkList(int n); //创建一个单链表   
	void TravalLinkList(); //遍历线性表   
	int GetLength(); //获取线性表长度 
	bool IsEmpty(); //判断单链表是否为空
	Node * Find(DataType data); //查找节点  
	void InsertElemAtEnd(DataType data); //在尾部插入指定的元素    
	void InsertElemAtIndex(DataType data, int n); //在指定位置插入指定元素   
	void InsertElemAtHead(DataType data); //在头部插入指定元素 
	void DeleteElemAtEnd(); //在尾部删除元素
	void DeleteAll(); //删除所有数据  
	void DeleteElemAtPoint(DataType data); //删除指定的数据    
	void DeleteElemAtHead(); //在头部删除节点

	void Sort(int n);//冒泡排序
	void InsertFitPos(DataType data);//在合适位置插入
private:
	Node * head; //头结点
};



