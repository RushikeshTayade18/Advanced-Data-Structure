#include<iostream>
using namespace std;
struct node
{
	char op;
	node *left;
	node *right;
};
class Stack
{
	public:
	node *s[20];
	int top;
	Stack()
	{
		top=-1;
	}
	bool isEmpty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool isFull()
	{
		if(top==19)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void push(node *ele)
	{
		if(!isFull())
		{
			top++;
			s[top]=ele;
		}
		else
		{
			cout<<"Stack is Empty \n";
		}
	}
	node* pop()
	{
		if(!isEmpty())
		{
			node *pnode;
			pnode=s[top];
			top--;
			return pnode;
		}
		else
		{
			cout<<"Stack is Full !\n";
		}
	 } 
	 char getchar()
	 {
	 	return(s[top]->op);
	 }
	
};
class Expression
{
	public:
	Stack oprand,oprator;
	string Exp;
	
	node *root;
	node *cn,*nn;
	Expression()
	{
		root=NULL;
	}
	
	void Create()
	{
			
			cout<<"Enter any Expression !\n";
			cin>>Exp;
			int i=0;
			
			while(Exp[i]!='\0')
			{
				nn=new node;
				nn->left=nn->right=NULL;
				nn->op=Exp[i];
				if(Exp[i]=='+'||Exp[i]=='-'||Exp[i]=='*'||Exp[i]=='/')
				{
					if(oprator.isEmpty())
					{
						oprator.push(nn);
					}
					else
					{
					
							char top=oprator.getchar();
							if(presition(top) >= presition(Exp[i]))
							{
								cn=oprator.pop();
								cn->right=oprand.pop();
								cn->left=oprand.pop();
								oprand.push(cn);
								oprator.push(nn);
							}
							else
							{
								oprator.push(nn);
							}
					}
				}
				else
				{
					oprand.push(nn);
				}
				i++;
			}
			
			if(!oprator.isEmpty())
			{
				while(!oprator.isEmpty())
				{
					cn=oprator.pop();
					cn->right=oprand.pop();
					cn->left=oprand.pop();
					oprand.push(cn);
				}
			}
			root=oprand.pop();
	}
	int presition(char ch)
	{
		if(ch=='+'||ch=='-')
		{
			return 1;
		}
		else if(ch=='*'||ch=='/')
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	node* Display(node *root)
	{
		if(root!=NULL)
		{
			
			Display(root->left);
			cout<<root->op;
			Display(root->right);
		}
	}
};
int main()
{
	Expression e1;
	e1.Create();
	e1.Display(e1.root);
	
	return 0;
	
}
