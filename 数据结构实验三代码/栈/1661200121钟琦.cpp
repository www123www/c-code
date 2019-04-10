
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
    void Clear()                     //���ջ
    {
        top=-1;
    }
    bool Push(const int value)       //ѹ��
    {
        if(top==maxSize-1)
        {
            cout<<"ջ�����"<<endl;
            return false;
        }
        else
        {
            p[++top]=value;
            return true;
        }
    }
    bool Pop(int &value)               //��ȡջ��Ԫ�ص�ֵ��ɾ��
    {
        if(top==-1)
        {
            cout<<"ջΪ�գ����ܽ���ɾ������"<<endl;
            return false;
        }
        else
        {
            value=p[top--];
            return true;
        }
    }
    bool Top(int &value)                //��ȡջ��Ԫ�ص�ֵ����ɾ��
    {
        if(top==-1)
        {
            cout<<"ջΪ�գ����ܶ�ȡջ��Ԫ��"<<endl;
            return false;
        }
        else
        {
            value=p[top];
            return true;
        }
    }
    bool IsEmpty()                 //ջ�շ�
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool IsFull()                  //ջ����
    {
        if(top==maxSize-1)
            return true;
        else
            return false;
    }
    void show()                //�鿴ջ��Ԫ�ص�ֵ
    {
        int t=top;
        cout<<"ջ��Ԫ��:"<<endl;
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
    cout<<"����һ���������ʽ��\n";
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