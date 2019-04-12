// queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "queue.h"
#include <conio.h>
#include <iostream>
#define ERROR NULL;
using namespace std;
//Se_queue();
//~Se_queue();
//void Display();//显示
//void Enqueue(ElemType x);//入队
//ElemType Dequeue();//出队

/*初始化*/
Se_queue::Se_queue() {
	front = 0,rear=0,length=0;
	cout << "init!" << endl;
}
Se_queue::~Se_queue() {
	//delete[MAXSIZE] Elem;

}
/* 
遍历队列，并显示
*/
void Se_queue::Display() {
	ElemType x;
	int j = 0;
	if (length==0)
		cout << "QUEUE IS FULL!";
	else {
		//遍历队列
		for (int i = 0; i <MAXSIZE; i++) {
			if(Elem[i]!=0)cout <<Elem[i] << " ";
			if (i == rear)break;
		}
		cout << endl;
	}
}
/*入队*/
void Se_queue::Enqueue(ElemType elem) {

	if (length == 0) {
		//出队，队列空（初始化）
		rear = 0;
		front = 0;
	}
	//判断队列是否满
	if (length == MAXSIZE)cout << "队列已满" << endl;
	else {
		//入队

		Elem[0] = elem;
		length++;
		++rear;
		if (rear <MAXSIZE) {	
			//移动数据
			for (int i = rear; i >= 1; i--) {
				Elem[i] = Elem[i - 1];
			}
			Elem[0] = NULL;
		}
	
	}






}
/*出队*/
ElemType Se_queue::Dequeue() {

	if (length==0)return NULL;

	ElemType elm = Elem[rear-1];
	if (front < MAXSIZE) {
		//移动数据
		for (int i = rear - 1; i >= 1; i--) {
			Elem[i] = Elem[i - 1];
		}
	}

	Elem[front] = NULL;
	++front;	
	length--;
	
	return elm;
}
