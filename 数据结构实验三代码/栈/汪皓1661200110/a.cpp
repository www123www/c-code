#include<iostream>
#include<string.h>
#include<stack>//���ñ�׼��
using namespace std;
int main()
{
    char s[5];
    stack<char>st;//����һ���ַ���ջ
    while(cin>>s) 
    {
        while(!st.empty())
        {st.pop();}
        int len=strlen(s),flag=1;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);//��������ѹ��ջ��
            else 
            {
                if(st.empty())
                {
                    flag=0;
                    break;  
                }
                char t=st.top();
                st.pop();
                if(s[i]==')'&&(t=='['||t=='{'))
                {
                    flag=0;
                    break;
                }
				else if(s[i]==')'&&t!='(')
                {
                    flag=0;
                    break;
                }
                else if(s[i]=='}'&&(t=='('||t=='['))
                {
                    flag=0;
                    break;
                }
                else if(s[i]==']'&&(t=='{'||t=='('))
                {
                    flag=0;
                    break;
                }
				else if(s[i]==']'&&t!='[')
                {
                    flag=0;
                    break;
                }
            }
        }
        if(!st.empty())
		{
			flag=0;
		}
        if(flag==1)
        {
			cout<<"true!"<<endl;
		}
        else
        {
			cout<<"false!"<<endl;
		}
    }
    return 0;
} 
