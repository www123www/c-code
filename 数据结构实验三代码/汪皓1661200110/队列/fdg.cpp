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
      else{j=(front)%MAXSIZE;while(j!=(rear) %MAXSIZE)
          {x=elem[j];cout<<x<<" ";j=(j+1)%MAXSIZE;}
          }cout<<endl;
    }
void SeQueue::AddQ(ElemType x)//将此成员函数补充完整，使得程序能够正确运行
{  
	if((rear+1)%MAXSIZE==front)
	cout<< "OVER_FLOW"<<endl;
		
	else{
		elem[rear]=x;
		rear=(rear+1)%MAXSIZE;
		cout<<" SUCCESS"<<endl;
	}
 }
 ElemType SeQueue::DelQ()//将此成员函数补充完整，使得程序能够正确运行
 {   ElemType e;
	 if(rear!=front){
		
		e=elem[front];
		front=(front+1)%MAXSIZE;
		cout<<" SUCCESS"<<endl;
		return e;
	 }
	 else
	 {
		 cout<<" UNDER_FLOW"<<endl;
		 return -1;
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
