#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
class Tree
{
	
	public:
		node *root;
		Tree()
		{
			root=NULL;
		}
		
		void Create()
		{
			int pos;
			char ch;
			do
			{
			
			
			node *nn;
			node *parent;
			nn=new node;
			nn->left=nn->right=NULL;
			
			cout<<"Enter data in for node \n";
			cin>>nn->data;
			
			if(root==NULL)
			{
				root=nn;
			}
			else
			{
				node *cn;
				cn=root;
			
				
				while(cn!=NULL)
				{
					cout<<"Enter position (0/1) 0 for left 1 for right \n";
					cin>>pos;
				
						
						parent=cn;
						if(pos==0)
						{
							cn=cn->left;
						}
						else
						{
							cn=cn->right;
						}
				
				}
				if(pos==0)
				{
					parent->left=nn;
				}
				else
				{
					parent->right=nn;
				}
			}
			
			cout<<"Do you want to contineu \n";
		cin>>ch;
		}
		while(ch=='Y'||ch=='y');
	}
	
	void Display(node* root)
	{
		if(root!=NULL)
		{
			cout<<root->data;
			Display(root->left);
			Display(root->right);
		}
	}

};

int main()
{
	Tree t1;
	t1.Create();
	t1.Display(t1.root);
	
	
	return 0;
}




