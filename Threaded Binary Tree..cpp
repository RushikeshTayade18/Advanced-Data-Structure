#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	int lth,rth;
};
class TBST
{
	public:
	node *root,*dummy;
	TBST()
	{
		root=NULL;
	}
	void Create()
	{
		node *nn;
		nn=new node;
		nn->left=nn->right=NULL;
		cout<<"Enter the data to store in node \n";
		cin>>nn->data;
		nn->lth=nn->rth=1;

		if(root==NULL)
		{
			dummy=new node;
			dummy->data=10;
			root=nn;
			dummy->left=root;
			nn->left=dummy;
			nn->right=dummy;
			nn->lth=1;
			nn->rth=1;

		}
		else
		{
			node *cn;
			cn=root;
			while(1)
			{
				if(cn->data > nn->data)
				{
					if(cn->lth==1)
					{
						cn->lth=0;
						nn->left=cn->left;
						
						nn->right=cn;
						cn->left=nn;

						break;
					}
					else
					{
						cn=cn->left;
					}
				}
				else if(cn->data < nn->data)
				{
					if(cn->rth==1)
					{
						cn->rth=0;
						nn->right=cn->right;
						cn->right=nn;
						nn->left=cn;
					

						break;
					}
					else
					{
						cn=cn->right;
					}
				}
			}
		}
	}
	void Inorder()
	{
		node *temp;
		temp=root;

		while(temp!=dummy)
		{
			while(temp->lth==0)
			{
				temp=temp->left;
			}
			cout<<temp->data<<"\t"<<endl;

			while(temp->rth==1)
			{
				temp=temp->right;
				if(temp!=dummy)
				{
					cout<<temp->data<<endl;
				}
				else
				{
					return;
				}
			}
			temp=temp->right;
		}
		
	}
	
	void Postorder()
	{
	 	node *cn;
	 	cn=root;
	 	int i=0;
	 	int arr[20];
	 	while(cn!=dummy)
	 	{
	 		while(cn->rth==0)
	 		{
	 		 	arr[i++]=cn->data;
	 		 	cn=cn->right;
	 		}
	 		arr[i++]=cn->data;
	 		while(cn->lth==1&&cn->left!=dummy)
	 		{
	 		 cn=cn->left;
	 		 }
	 		 cn=cn->left;
		}
		i--; 
		for(int k=i;k>=0;k--)
		{
		cout<<endl<<arr[k]<<"\t";
		}
		
	}				  	
	 	void Preorder()
	 	{
	 	
	 	node *temp;
		temp=root;

		while(temp!=dummy)
		{
			cout<<temp->data<<"\t"<<endl;
			while(temp->lth==0)
			{
				temp=temp->left;
				cout<<temp->data<<"\t"<<endl;
			}
			

			while(temp->rth==1)
			{
				temp=temp->right;
				if(temp==dummy)
				{
					return;
				}
				
			}
			temp=temp->right;
			
		}
	 	
	 	}
	
	
};
int main()
{
		TBST t1;
		int ch;
		char a;
		do
		{
		   cout<<"1.Create TBT \n";
		   cout<<"2.Display Inorder \n";
		   cout<<"3.Display POstorder\n";
		   cout<<"4.Display Preorder \n";
		   cout<<"Enter your choice \n";
		   cin>>ch;
		   switch(ch)
		   {
		   
		   case 1:
		   		t1.Create();
			break;
			case 2:
			
				t1.Inorder();
			break;
			case 3:
			   t1.Postorder();
			   break;
			   case 4:
			   t1.Preorder();
			   break;
			default:
			cout<<"Wrong Input \n";
			}
			cout<<"Do you want to contineu \n";
			cin>>a;
		}while(a=='y'||a=='Y');	
		return 0;
}
