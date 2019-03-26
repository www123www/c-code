// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LinkList.h"

#define ERROR NULL  
//初始化单链表
LinkList::LinkList()
{
	head = new Node;
	head->data = 0; //将头结点的数据域定义为0
	head->next = NULL; //头结点的下一个定义为NULL
}
//销毁单链表
LinkList::~LinkList()
{
	Node *q = head->next; //定义q指向空白头结点的下一个
	while (q != NULL) //当指针的地址不为空时
	{
		head->next = q->next; //让q所指向的结点从链表中脱离出来，并保持原链表的链不断开
		delete q;//释放从链表中脱离出来的结点的空间
		q = head->next;//q之前指向的结点已被删除，现在需要重新给q赋值
	}
	delete head; //其余结点已被删完，最后删除空白头结点
}
//创建一个单链表
void LinkList::CreateLinkList(int n)
{
	Node *pnew, *ptemp;
	ptemp = head;

	if (n < 0)
	{ //当输入的值有误时，处理异常      
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
	{ //将值一个一个插入单链表中pnew = new Node;        
		cout << "请输入第" << i + 1 << "个值: ";
		pnew = new Node;
		cin >> pnew->data;
		pnew->next = NULL; //新节点的下一个地址为NULL  
		ptemp->next = pnew; //当前结点的下一个地址设为新节点 
		ptemp = pnew; //将当前结点设为新节点    
	}
}
//遍历单链表
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "链表为空表" << endl;
	}
	Node *p = head; //另指针指向头结点    
	while (p->next != NULL) //当指针的下一个地址不为空时，循环输出p的数据域   
	{
		p = p->next; //p指向p的下一个地址     
		cout << p->data << "  |  ";
	}
	cout << endl;
}
//获取单链表的长度
int LinkList::GetLength()
{
	int count = 0; //定义count计数
	Node *p = head->next; //定义p指向头结点
	while (p != NULL) //当指针的下一个地址不为空时，count+1  
	{
		count++;
		p = p->next; //p指向p的下一个地址
	}
	return count; //返回count的数据
}
//判断单链表是否为空
bool LinkList::IsEmpty()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}
//查找节点
Node * LinkList::Find(DataType data)
{
	Node * p = head->next;
	if (p == NULL) { //当为空表时，报异常      
		cout << "此链表为空链表" << endl;
		return ERROR;
	}
	else
	{
		while (p != NULL) //循环每一个节点      
		{
			if (p->data == data)
			{
				return p; //返回指针域
			}
			p = p->next;
		}
		return NULL; //未查询到结
	}
}
//在尾部插入指定的元素
void LinkList::InsertElemAtEnd(DataType data)
{
	Node * newNode = new Node; //定义一个Node结点指针newNode 
	newNode->next = NULL; //定义newNode的数据域和指针域  
	newNode->data = data;
	Node * p = head; //定义指针p指向头结点
	if (head == NULL)
	{ //当头结点为空时，设置newNode为头结点        
		head = newNode;
	}
	else //循环知道最后一个节点，将newNode放置在最后
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}
//在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data, int n)
{
	if (n<1 || n>GetLength() + 1) //输入有误报异常        
		cout << "输入的值错误" << endl;
	else
	{
		Node * ptemp = new Node; //创建一个新的节点       
		ptemp->data = data; //定义数据域 
		Node * p = head; //创建一个指针指向头结点       
		int i = 1;
		while (n > i) //遍历到指定的位置   
		{
			p = p->next;
			i++;
		}
		ptemp->next = p->next; //将新节点插入到指定位置      
		p->next = ptemp;
	}
}
//在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data)
{
	Node * newNode = new Node; //定义一个Node结点指针newNode 
	newNode->data = data;
	Node * p = head; //定义指针p指向头结点 
	if (head == NULL)
	{ //当头结点为空时，设置newNode为头结点
		head = newNode;
	}
	newNode->next = p->next; //将新节点插入到指定位置    
	p->next = newNode;
}
//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
	Node * p = head; //创建一个指针指向头结点    
	Node * ptemp = NULL; //创建一个占位节点
	if (p->next == NULL)
	{ //判断链表是否为空       
		cout << "单链表空" << endl;
	}
	else
	{
		while (p->next != NULL) //循环到尾部的前一个
		{
			ptemp = p; //将ptemp指向尾部的前一个节点         
			p = p->next; //p指向最后一个节点
		}
		delete p; //删除尾部节点        
		p = NULL;
		ptemp->next = NULL;
	}
}
//删除所有数据
void LinkList::DeleteAll()
{
	Node * p = head->next;
	Node * ptemp = new Node;
	while (p != NULL) //在头结点的下一个节点逐个删除节点
	{
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL; //头结点的下一个节点指向NULL
}
//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
	Node * ptemp = Find(data); //查找到指定数据的节点位置    
	if (ptemp == head->next)
	{ //判断是不是头结点的下一个节点，如果是就从头部删了它              
		DeleteElemAtHead();
	}
	else
	{
		Node * p = head; //p指向头结点 
		while (p->next != ptemp) //p循环到指定位置的前一个节点      
		{
			p = p->next;
		}
		p->next = ptemp->next; //删除指定位置的节点    
		delete ptemp;
		ptemp = NULL;
	}
}
//在头部删除节点
void LinkList::DeleteElemAtHead()
{
	Node * p = head;
	if (p == NULL || p->next == NULL)
	{ //判断是否为空表，报异常   
		cout << "该链表为空表" << endl;
	}
	else
	{
		Node * ptemp = NULL; //创建一个占位节点    
		p = p->next;
		ptemp = p->next; //将头结点的下下个节点指向占位节点  
		delete p; //删除头结点的下一个节点    
		p = NULL;
		head->next = ptemp; //更换头结点的指针域 
	}
}

//排序
void LinkList::Sort(int n) {
	//Node *d = head,*p=head;
	//DataType  value;
	//
	//for (int i = 2; i < n+1; i++) {
	//	int j = i - 1;//j=
	//	value = p->next->next->data;
	//	for (; j >= 0; j--) {
	//		
	//		if (p->next->data> value) { //

	//			//头节点 的下一个数据域  
	//			//p->next->next->data = p->next->data;//
	//			DataType temp = p->next->next->data;
	//			p->next->next->data = p->next->data;
	//			p->next->data = temp;

	//			//d = d->next;
	//			//p = d;

	//		}
	//		else {
	//		
	//			break;
	//		}
	//		
	//	
	//	}
	//  //if(j==-1)	d->data = value;
	//	p = p->next;

	// }

	//冒泡排序
	Node *d = head, *p = head;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p->next->next == NULL)break;
			DataType value_q = p->next->data;//链表第j 位置的值
			DataType value_h = p->next->next->data;//链表第j+1 位置的值
			if (value_q > value_h) {// j位置的值大于  j+1位置的值  进行交换操作

				DataType temp = p->next->next->data;
				p->next->next->data = p->next->data;
				p->next->data = temp;


			}
			p = p->next;//p指针往后移动

		}
		//冒泡一次就将  指针p重新指向 d指针 /即 指针p 重新 指向 头指针
		p = d;
}


	

}

//在合适位置插入

void LinkList::InsertFitPos(DataType data) {
	bool flag = false;//插入值比最小值还小
	int n = GetLength();
	Node *p = head;
	Node *q = new Node;
	q->data = data;

	DataType value_q, value_h;

	//插入的值比最小的值还小
	if (q->data < p->next->data) {
		q->next = p->next;
		p->next = q;
		flag = true;
	}
	//遍历 
	for (int i = 0; i < n-1; i++) {
		if (flag == true)break;
		value_q = p->next->data;
		value_h = p->next->next->data;
		//找到合适位置
		if (value_q < data&&value_h > data) {
			p = p->next;
			q->next = p->next;
			p->next= q;
			
			break;
		}
	
		p = p->next;
	}
	//插入的值比最大的值还大
	if (q->data > p->next->data) {
		q->next = NULL;
		p->next->next = q;
	}
}
