#include <iostream.h>
#include <conio.h>
#define MAXSIZE 3
typedef int ElemType;
 class SeQueue
  {  private:
       ElemType elem[MAXSIZE];
        int front,rear;
     public:
        SeQueue();
        ~SeQueue();
        void Display();
        void AddQ(ElemType x);
        ElemType DelQ();
};
SeQueue::SeQueue()
  {  front=0;
     rear=0;
     cout<<"init!"<<endl;
  }
SeQueue::~SeQueue()
{};//{ delete [MAXSIZE]Q.elem;}
void SeQueue::Display()
    { ElemType x; int j=0;
      if(rear==front)
            {cout<<"QUEUE IS FULL!";}
      else{j=front;while(j!=rear)
          {x=elem[j];cout<<x<<" ";j=(j+1)%MAXSIZE;}
          }cout<<endl;
    }
void SeQueue::AddQ(ElemType x)
{  
	if((rear +1) % MAXSIZE == front)
		cout<<" max"<<endl;
	else{
		elem [rear]= x;
		rear = (rear + 1)  % MAXSIZE;
		cout<<"�ɹ� "<<endl;
	}
	//���˳�Ա��������������ʹ�ó����ܹ���ȷ����
 }
 ElemType SeQueue::DelQ()
 {
	ElemType x;
	 if(front == rear){
	 cout<<"�� "<<endl;
	 return -1;
	 }
	 else{
		x = elem[front];
		front = (front +1)% MAXSIZE;
		cout<<"�ɹ� "<<endl;
		return x;
	 }	
 //���˳�Ա��������������ʹ�ó����ܹ���ȷ����
 }
int main(  )
{  ElemType x;  int j;
   SeQueue h;
   int k;
   cout<<"\n                           ���д洢�ṹ��ʾ";
  do{
    cout<<"\n\n";
    cout<<"\n\n    1.��������һ������";
    cout<<"\n\n    2.�����������";
    cout<<"\n\n    3.���";
    cout<<"\n\n    4.����";
    cout<<"\n\n    5.��������";
    cout<<"\n******************************** ";
    cout<<"\n    ���������ѡ��(1,2,3,4,5)";
    cin>>k;
    switch(k){
       case 1:{SeQueue::SeQueue();
              }break;
       case 2:{h.Display();
              }break;
       case 3:{
                cout<< "����  data=?";  cin>>x;
                h.AddQ(x);
                h.Display();
               }break;
       case 4:{   x=h.DelQ();
                 if(x!=-1)
                 cout<< "���ӵĽ��ֵ�ǣ�"<<x<<endl;
                 h.Display();
                }break;
       default:break;
         }
       cout<<"\n--------------------------------- ";
    }while(k>=1&&k<5);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
     _getch(); return 0;
}
