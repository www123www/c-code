#include <iostream.h>
#include <conio.h>
#include <string.h>
class String
{public:
     String(){};
     ~String(){};
     String SubString(int pos,int num);
     void Insert(String t,int pos);
     void Delete(int pos,int num);
     void Creat();
     void Display();
  private:
     char *str;
     int size;
 };
 //�������ַ�������
void String:: Creat()
 { char *s=new char(100); 
   cin>>s;
    size=strlen(s);
    str=new char[size];
    if(str==0)  cout<<"û�����뵽�ռ䣡";
    strcpy(str,s);
 }
//���
void String::Display()
{ int i;
  for(i=0;i<size;i++)  cout<<str[i];
  cout<<endl;
}
//���Ӵ�
String String::SubString(int pos,int num)
{ 
//���˳�Ա��������������ʹ�ó����ܹ���ȷ����
String t;
	int i,j;
	if((pos>0&&pos<size+1)&&(num>=0&&pos+num<=size+1)){
		t.str=new char[num+1];
		t.size=num;
		for(i=0,j=pos-1;i<num;i++,j++)
			t.str[i]=str[j];
	}
	else{
		t.str=NULL;
		t.size=0;
	}
	return t;
}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t,int pos)
{
	
	String s;
	if(s.size+t.size>= *str)
		cout<<"���"<<endl;
	else{
		for(int i=s.size-1;i>=pos;--i)
			
			s.str[i+s.size]=s.str[i];

		for(i=0;i<=t.size;++i)
		s.str[pos++]=t.str[i];
		//s.size=s.size+t.size;
	}
}

//ɾ�� :ɾ�����е�һ���Ӵ�
void  String:: Delete(int pos,int num)
{ String s;
	if((pos<1)||(pos>s.size))
		cout<<" "<<endl;

		int i=pos-1;
		int j=pos+num-1;

		while(str[i++]=str[j++]){
;
		}
		cout<<"ɾ���ɹ�";
	}

//���˳�Ա��������������ʹ�ó����ܹ���ȷ����

//������
int main(int argc, char* argv[])
{  int pos,num,k;
   String s,s1,t;
   do{  cout<<"\n\n    1.�����ַ���"  ;
        cout<<"\n\n    2.ȡ�Ӵ�";
        cout<<"\n\n    3.�����Ӵ�s1";
        cout<<"\n\n    4.ɾ���Ӵ�";
        cout<<"\n\n    5.��������";
        cout<<"\n******************************** ";
        cout<<"\n    ���������ѡ��(1,2,3,4,5)";  cin>>k;
  switch(k){
       case 1:{cout<<"������һ���ַ�����";
               s.Creat();
               cout<<"�ַ���Ϊ��       ";     s.Display();
              }break;
       case 2:{ cout<<"�������Ӵ��Ľ�ȡλ��pos���Ӵ�����num"<<endl;
                cin>>pos>>num;
                t=s.SubString(pos,num);
                cout<<"����ȡ���Ӵ�Ϊ������";  t.Display();
               }break;
       case 3:{ cout<<"�������Ӵ�����λ��pos"<<endl;
                cin>>pos;
                cout<<"������Ҫ������Ӵ�:  ";   s1.Creat();
                s.Insert(s1,pos);
                cout<<"�������ַ���Ϊ��   ";  s.Display();
              }break;
       case 4:{ cout<<"������Ҫɾ���Ӵ��Ŀ�ʼλ��pos���Ӵ�����num"<<endl;
               cin>>pos>>num;
               s.Delete(pos,num);
               cout<<"ɾ������ַ���Ϊ��   ";
               s.Display();
             }break;
     default:break;
  } //switch
     cout<<"\n--------------------------------- ";
}while(k>=1&&k<5);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
  return 0;
}
	