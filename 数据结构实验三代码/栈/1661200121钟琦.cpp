
#include<iostream>
using namespace std;
class Stack
{
private:
    int maxSize;
    int top;
    int *p;
public:
    Stack(int size)
    {
        maxSize=size;
        top=-1;
        p=new int[maxSize];
    }
    ~Stack()
    {
        delete [] p;
    }
    void Clear()                     //清空栈
    {
        top=-1;
    }
    bool Push(const int value)       //压入
    {
        if(top==maxSize-1)
        {
            cout<<"栈满溢出"<<endl;
            return false;
        }
        else
        {
            p[++top]=value;
            return true;
        }
    }
    bool Pop(int &value)               //读取栈顶元素的值并删除
    {
        if(top==-1)
        {
            cout<<"栈为空，不能进行删除操作"<<endl;
            return false;
        }
        else
        {
            value=p[top--];
            return true;
        }
    }
    bool Top(int &value)                //读取栈顶元素的值并不删除
    {
        if(top==-1)
        {
            cout<<"栈为空，不能读取栈顶元素"<<endl;
            return false;
        }
        else
        {
            value=p[top];
            return true;
        }
    }
    bool IsEmpty()                 //栈空否？
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool IsFull()                  //栈满否？
    {
        if(top==maxSize-1)
            return true;
        else
            return false;
    }
    void show()                //查看栈内元素的值
    {
        int t=top;
        cout<<"栈内元素:"<<endl;
        while(t+1)
            cout<<p[t--];
        cout<<endl;
    }
};
void match()
{
    int temp;
	int i=0,flag=1,flag2=1;
    char s[20];
    char c;
    Stack formula(10);
    cout<<"输入一个算术表达式：\n";
    cin>>s;
    c=s[i];
	
    while(c&&flag)
    {
        if(c=='[')
        {
            formula.Push(c);
            flag2=0;
        }
        else if(c==']')
        {
            if(formula.IsEmpty())
            {
                flag=0;
                break;
            }
            formula.Pop(temp);
            if(temp==c-1||temp==c-2);
            else
            {
                flag=0;
                break;
            }
        }
        c=s[++i];
    }
    if(!formula.IsEmpty())
        flag=0;
    if(flag2)
        cout<<"no\n";
    else if(flag)
        cout<<"yes\n";
    else
        cout<<"no\n";

	cout<<(flag)<<endl;
}
int main()
{
    match();
    return 0;
}