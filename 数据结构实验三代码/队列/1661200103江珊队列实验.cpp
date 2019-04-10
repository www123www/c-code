#include <iostream.h>
#include <conio.h>
#define MAXSIZE 3//最大容量
typedef int ElemType;
 class SeQueue
  {  private:
       ElemType elem[MAXSIZE];
        int front,rear;//队头队尾
     public:
        SeQueue();//构造函数
        ~SeQueue();//析构函数
        void Display();
        void AddQ(ElemType x);//入队
        ElemType DelQ();//出队
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
      else{
		  j=(front+1)%MAXSIZE;
		  while(j!=(rear+1) %MAXSIZE){
			  x=elem[j];cout<<x<<" ";j=(j+1)%MAXSIZE;
		  }
          }cout<<endl;
    }
void SeQueue::AddQ(ElemType x)
{  //将此成员函数补充完整，使得程序能够正确运行
	if((rear+1)% MAXSIZE==front)
		cout<<"存满了！"<<endl;
	else{
		elem[rear+1]=x;
		rear=(rear +1) % MAXSIZE;
			cout<<"入队成功"<<endl;
	}
 }
 ElemType SeQueue::DelQ()
 {
 //将此成员函数补充完整，使得程序能够正确运行
	if(elem !=NULL){
		ElemType e;
		e=elem[front+1];
		front=(front+1) % MAXSIZE;
		return e;
	 }else{
            cout<<"QUEUE IS FULL!";

	 }
 }
int main(  )
{  ElemType e;  int j;
   SeQueue h;
   int k;
   cout<<"\n                           队列存储结构演示";
  do{
    cout<<"\n\n";
    cout<<"\n\n    1.初步建立一个队列";
    cout<<"\n\n    2.输出整个队列";
    cout<<"\n\n    3.入队";
    cout<<"\n\n    4.出队";
    cout<<"\n\n    5.结束程序";
    cout<<"\n******************************** ";
    cout<<"\n    请输入你的选择(1,2,3,4,5)";
    cin>>k;
    switch(k){
       case 1:{SeQueue::SeQueue();
              }break;
       case 2:{h.Display();
              }break;
       case 3:{
                cout<< "进队  data=?";  cin>>e;
                h.AddQ(e);
                h.Display();
               }break;
       case 4:{   e=h.DelQ();
                 if(e!=-1)
                 cout<< "出队的结点值是："<<e<<endl;
                 h.Display();
                }break;
       default:break;
         }
       cout<<"\n--------------------------------- ";
    }while(k>=1&&k<5);
  cout<<"\n          再见!";
  cout<<"\n     按任意键，返回。";
   _getch(); return 0;
}
