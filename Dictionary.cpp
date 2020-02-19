#include<iostream>
#include<string>

using namespace std;

struct node{
	string key;
	string meaning;
	node *left;
	node *right;
};

class Dictionary
{
	public:
	node *root;

public:
	Dictionary()
	{
		root=NULL;
	}

	void insert(node *nn)
	{

		if(root==NULL)
		{
			root=nn;
			cout<<"\nInserted "<<nn->key;
		}
		else
		{
			node *cn=root;
			node *parent=cn;

			while(cn!=NULL)
			{
				parent=cn;

				if(cn->key < nn->key)
				{
					cn=cn->right;
				}
				else
				{
					cn=cn->left;
				}
			}
			if(parent->key < nn->key)
			{
				parent->right=nn;
				cout<<"\nInserted "<<nn->key;
			}
			else
			{
				parent->left=nn;
				cout<<"\nInserted "<<nn->key;
			}
		}
	}

	void display(node *temp)
	{

		if(temp!=NULL)
		{
			display(temp->left);
			cout<<temp->key<<"\t"<<temp->meaning<<"\n";
			display(temp->right);
		}
	}

	void search(string word)
	{
		int count=0;

		if(root==NULL)
		{
			cout<<"No Tree!";
		}
		else
		{
			node *cn=root;

			while(cn!=NULL)
			{
				count++;
				if(cn->key == word)
				{
					cout<<"\nWord Found";
					cout<<"Max Comparisons is: "<<count;
					return;
				}
				else if(cn->key > word)
				{
					cn=cn->left;
				}
				else
				{
					cn=cn->right;
				}
			}
		}
		cout<<"\nWord not found!";
	}

	void update(string word)
	{
		node *cn=root;

		while(cn!=NULL)
		{
			if(cn->key == word)
			{
				cout<<"\nEnter the new meaning: ";
				cin>>cn->meaning;
				cout<<"\nMeaning updated!";
				return;
			}
			else if(cn->key > word)
			{
				cn=cn->left;
			}
			else
			{
				cn=cn->right;
			}
		}
		cout<<"\nWord not found!";
	}

	void del(string str)
	{
		
				int cnt=0;
				
				int flag=0;
				node *cn,*parent;
				cn=root;

				while(cn!=NULL && cn->key!=str)
				{
					parent =cn;
					if(cn->key > str)
					{
						cn=cn->left;
					}else if(cn->key < str)
					{
						cn=cn->right;
					}

				}				
				
				if(cn->right==NULL && cn->left==NULL)
				{
				
					if(cn==root)
					{
					root=NULL;
					return;
					}
					if(cn->key < parent->key)
					{
						parent->left=NULL;
					}else
					{
						parent->right=NULL;
					}
					delete cn;
					return;
				}
				
				if(cn->right!=NULL && cn->left==NULL)
				{
					
					if(cn==root)
					{
					root=cn->right;
					delete cn;
					return;
					}
					
					if(parent->key > cn->key)
					{
						parent->left=cn->right;
					}else
					{
						parent->right=cn->right;
					}
					delete cn;
					return;
				}
				if(cn->right==NULL && cn->left!=NULL)
					{
						if(cn==root)
						{
						root=cn->left;
						delete cn;
						return;
						}
									if(parent->key > cn->key)
									{
										parent->left=cn->left;
									}else
									{
										parent->right=cn->left;
									}
					delete cn;
					return;		
					}

				if(cn->right!=NULL && cn->left!=NULL)
				{
					node *tmp;
					tmp=cn->left;
					while(tmp->right!=NULL)
					{
						tmp=tmp->right;
					}
					string x;
					x=tmp->key;
					del(x);
					cn->key=x;
					return;
				}

	cout<<"\n not found::";
	}

};


int main()
{
	Dictionary d;
	int ch;
	string word;
	do
	{
		cout<<"\n\n**************Dictionary**************";
		cout<<"\n1.Insert new word\n2.Display all\n3.Search\n4.Update\n5.Delete\n>>";
		cin>>ch;

		switch(ch)
		{
			case 1:
			{
				node *nn=new node;
				cout<<"\nEnter the Word: ";
				cin>>nn->key;
				cout<<"\nEnter the Meaning: ";
				cin>>nn->meaning;
				nn->left=NULL;
				nn->right=NULL;

				d.insert(nn);
				break;
			}

			case 2:
			{
				cout<<"\nWord\tMeaning\n\n";
				d.display(d.root);
				break;
			}
			case 3:
			{
				cout<<"\nEnter the word to search: ";
				cin>>word;
				d.search(word);
				break;
			}
			case 4:
			{
				cout<<"\nEnter the word to update: ";
				cin>>word;
				d.update(word);
				break;
			}
			case 5:
			{
				cout<<"\nEnter the word to delete: ";
				cin>>word;
				d.del(word);
				break;
			}
		}
	}while(ch!=6);
	return 0;
}
