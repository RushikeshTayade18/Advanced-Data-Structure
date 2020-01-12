#include<iostream>
using namespace std;
struct node 
{
	int data;
	node *left;
	node *right;
};
class BST
{
	public:
	node *root,*cn,*parent,*temp;;
	BST()
	{
		root=NULL;
	}
	void Create()
	{

			node *nn;
			nn=new node;
			cout<<"Enter the data in the node \n";
			cin>>nn->data;
			nn->left=nn->right=NULL;
			
			if(root==NULL)
			{
				root=nn;
			}
			else
			{
				cn=root;
				while(cn!=NULL)
				{
					parent=cn;
					if(nn->data < cn->data)
					{
						cn=cn->left;
					}
					else
					{
						cn=cn->right;
					}
				}
				if(nn->data < parent->data)
				{
					parent->left=nn;
				}
				else
				{
					parent->right=nn;
				}
			}
	}
	
	void Display(node* root)
	{
		if(root!=NULL)
		{
			Display(root->left);
			cout<<root->data<<"\t";
			Display(root->right);
		}
	}

	void Search()
	{
		int ser;
		int flag=0;
		cout<<"Enter the data to search in tree \n";
		cin>>ser;
		cn=root;
		while(cn!=NULL)
		{
			if(cn->data==ser)
			{
				flag==1;
				cout<<"Element is presentin the list \n";
				return;
			}
			else if(cn->data < ser)
			{
				cn=cn->right;
			}
			else
			{
				cn=cn->left;
			}
		}
		if(flag==0)
		{
			cout<<"Element is not present in the Tree \n";
		}
	}
	
	void Delete_node(int data)
	{
		
		cn=root;
		while(cn!=NULL && cn->data!=data)
		{
			parent=cn;
			if(cn->data > data)
			{
				cn=cn->left;
			}
			else
			{
				cn=cn->right;
			}
		}
		if(cn->left==NULL && cn->right==NULL)
		{
			if(cn->data > parent->data)
			{
				parent->right=NULL;
				cout<<"Element is deleted !";
			}
			else
			{
				parent->left=NULL;
				cout<<"Element is deleted !";
			}
			delete cn;
		}
		if(cn->left!=NULL && cn->right==NULL)
		{
			if(parent->data > cn->data)
			{
				parent->left=cn->left;
			}
			else
			{
				parent->right=cn->left;
			}
			delete cn;
		}
		if(cn->left==NULL && cn->right!=NULL)
		{
			if(parent->data > cn->data)
			{
				parent->left=cn->right;
			}
			else
			{
				parent->right=cn->right;
			}
			delete cn;
		}
		if(cn->left!=NULL && cn->right!=NULL)
		{
			
			temp=cn->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			int x;
			x=temp->data;
			Delete_node(x);
			cn->data=x;			
		}
	}
};
int main()
{
	int data;
	BST b1;
	char a;
	int ch;
	do
	{
		cout<<endl<<"***************** MENU ***************** \n";
		cout<<"1.Insert Element \n";
		cout<<"2.Display Element \n";
		cout<<"3.Search Element \n";
		cout<<"4.Delete Element \n";
		cout<<"Enter your choise \n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				b1.Create();
			break;
			
			case 2:
				b1.Display(b1.root);
			break;
			
			case 3:
				b1.Search();
			break;
			
			case 4:
				cout<<"Enter element to delete \n";
				cin>>data;
				b1.Delete_node(data);	
			break;
			
			default:
				cout<<"Wrong Input \n";
						
		}
		cout<<endl<<"Do you want to contineu \n";
		cin>>a;
	}while(a=='Y'||a=='y');
	
	return 0;
}

