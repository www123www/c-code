#pragma once

#define MAXSIZE 3
typedef int ElemType;

class Se_queue {
public:
	Se_queue();
	~Se_queue();
	void Display();//��ʾ
	void Enqueue(ElemType x);//���
	ElemType Dequeue();//����
private:
	ElemType Elem[MAXSIZE];
	int front;//ͷ
	int rear;//β
	int length = 0;//�����д���Ԫ��
};