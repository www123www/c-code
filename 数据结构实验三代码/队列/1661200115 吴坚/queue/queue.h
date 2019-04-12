#pragma once

#define MAXSIZE 3
typedef int ElemType;

class Se_queue {
public:
	Se_queue();
	~Se_queue();
	void Display();//显示
	void Enqueue(ElemType x);//入队
	ElemType Dequeue();//出队
private:
	ElemType Elem[MAXSIZE];
	int front;//头
	int rear;//尾
	int length = 0;//队列中存在元素
};