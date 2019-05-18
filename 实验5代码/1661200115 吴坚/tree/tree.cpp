// tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <queue>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int leafCount = 0;

typedef int ElemType;
struct NodeType       	                    //定义结点 结构体
{
	ElemType   data;
	NodeType  *left, *right;
};
class BiTree    	                     //定义 二叉树类 class
{
public:
	BiTree() { root = NULL; };                    //构造函数
	~BiTree() { destroy(root); }                  //析构函数
	void level() {
		level(root);
	}
	void inorder()                            //中序遍历
	{
		inorder(root);
	}
	void preordertswap()                       //利用先序遍历方法交换左右子树
	{
		preorderswap(root);
	}
	int  tleaf()                             //求中叶子节点的个数
	{
		return leaf(root);
	}
	void creat0();
private:
	NodeType *root;                         //数据成员，树根
	NodeType *creat();                       //建立二叉树递归方法
	void level(NodeType *p);//层次遍历
	
	void inorder(NodeType *p);                //中序遍历
	void preorderswap(NodeType *p);           //利用先序遍历方法交换左右子树
	int leaf(NodeType *p);	               //求二叉树中叶子节点的个数
	void  destroy(NodeType* &p);             //删除二叉树所有结点
};
void  BiTree::creat0()                         //建立树函数，
{
	cout << "请按照树的先序遍历顺序组织数据" << endl;
	cout << "若结点信息是int，把每个结点的空孩子以0输入;" << endl;
	cout << "一个结点的二叉树11，输入：11 0 0;" << endl;
	root = creat();                            //调用私有creat();
}
NodeType * BiTree::creat()                      //递归建立二叉树算法
{
	NodeType *p;   ElemType x;
	cout << "\n 输入数据：";  
	cin >> x;
	if (x == 0) p = NULL;
	else {
		p = new NodeType; 
		p->data = x;
		p->left = creat();                  //递归调用自身
		p->right = creat();
	}
	return p;
}
//层次遍历
void BiTree::level(NodeType *T) {
	if (!T)
		return;
	NodeType *temp;
	queue<NodeType*>q;
	q.push(T);
	while (!q.empty())
	{
		temp = q.front();
		cout << temp->data<<"  ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
		q.pop();
	}
	
}
void BiTree::inorder(NodeType *p)             //中序遍历
{

	if (p == NULL)return;
	inorder(p->left);//左子树
	cout << p->data<<" ";
	inorder(p->right);//右子树



}
void BiTree::preorderswap(NodeType *p)         //利用先序遍历方法交换左右子树
{
	if (p != NULL)
	{
		NodeType *r; r = p->left;
		p->left = p->right; p->right = r;
		//上面几条语句可以认为对结点的访问（交换左右孩子）
		//替换了原来的： cout<<p->data<<" ";  语句
		preorderswap(p->left);
		
		preorderswap(p->right);
	}
}
void  BiTree::destroy(NodeType* &p)            //删除二叉树所有结点
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}
int BiTree::leaf(NodeType *p)                //求二叉树中叶子节点的个数
{
	if (p == NULL)return 0;
	if (p->left == NULL && p->right == NULL)leafCount++;//leafCount 全局变量 ，统计叶子节点的个数
	leaf(p->left);
	leaf(p->right);
	return leafCount;
}
//---------------------------------------------------------------------------
int main()
{
	int k;     BiTree root0;                     //声明创建二叉树对象，调用构造函数
	do {
		cout << "\n\n";
		cout << "\n\n     1. 建立二叉树";
		cout << "\n\n     2. 交换左右子树 ";
		cout << "\n\n     3. 求二叉树中叶子节点的个数  ";
		cout << "\n\n     4. 层次遍历";
		cout << "\n\n     5. 结束程序运行";
		cout << "\n======================================";
		cout << "\n     请输入您的选择 (0,1,2,3,4,5):"; cin >> k;
		switch (k)
		{
		case 1: {  cout << "\n  s输入（0 0）结束：";
			root0.creat0();
			cout << "\n     中序遍历结果：";  root0.inorder();
		} break;
		case 2: {  cout << "\n     交换左右子树结果：";
			root0.preordertswap();
			cout << "\n     中序遍历结果：";
			root0.inorder();
		} break;
		case 3: {   int number;
			number = root0.tleaf();
			cout << "\n  叶子节点的个数是：" << number;
		} break;
		case 4:
			cout << "\n     层次遍历结果：";
			root0.level();
			
			break;
		case 5: exit(0);
		} //  switch
		cout << "\n ----------------";
	} while (k >= 0 && k < 4);
	_getch();   return 0;
}//-----

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
