#include<iostream>
using namespace std;
 struct node
 {
 	int data;
	 node* next;	
 };
class Graph
{
 	public:
 		int s[10];
 		int visited[10];
 	int ver,edges;
 	node* root[10];
 	node *cn;
 	int m,n;
 	int mat[10][10];
	int top;
	Graph()
	{
		top=-1;
	
	}
	void push(int ele)
	{
		top++;
		s[top]=ele;
	}
	int pop()
	{
		return(s[top--]);
	}
	bool isEmpty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
 	void Adj_list()
 	{
 		
 		cout<<"Enter no of Vertices in graph \n";
 		cin>>ver;
 		for(int i=1;i<=ver;i++)
 		{
 			root[i]=NULL;
		 }
		 cout<<"Enter the No of Edges in graph \n";
		 cin>>edges;
		 for(int i=1;i<=edges;i++)
		 {
		 	cout<<"Enter the Edge M and N for Edge \n";
		 	cin>>m>>n;
		 	AddEdge(m,n);
		 	AddEdge(n,m);
		 }
		 
	 }
	 void AddEdge(int m,int n)
	 {
	 	node *nn;
	 	nn=new node;
	 	nn->next=NULL;
	 	nn->data=n;
	 	if(root[m]==NULL)
	 	{
	 		root[m]=nn;
		 }
		 else
		 {
		 	cn=root[m];
		 	while(cn->next!=NULL)
		 	{
		 		cn=cn->next;
			 }
			 cn->next=nn;
		 }
	 }
	 void Disp_Adj_list()
	 {
	 	cout<<"########## Adjacency List ###########\n";
	 	for(int i=1;i<=ver;i++)
	 	{
	 		cn=root[i];
	 		cout<<"["<<i<<"]";
	 		while(cn!=NULL)
	 		{
	 			cout<<"->"<<cn->data;
	 			cn=cn->next;
			 }
			 cout<<"\n";
		 }
	 }
	 
	 void Adj_mat()
	 {
	 	cout<<"Enter how many Vertices ! \n";
	 	cin>>ver;
	 	for(int i=1;i<=ver;i++)
	 	{
	 		for(int j=1;j<=ver;j++)
	 		{
	 			mat[i][j]=0;
			 }
		 }
		 cout<<"Enter how many Edges You have in graph \n";
		 cin>>edges;
		 for(int i=1;i<=edges;i++)
		 {
		 	cout<<"Enter the Edge Beetween M and N int m,n Vertices \n";
		 	cin>>m>>n;
		 	mat[m][n]=1;
		 	mat[n][m]=1;
		 	
		 }
		 
	 }
	 void Disp_Adj_mat()
	 {
	 	cout<<"########## Adjacency Matrix ###########\n";
	 	for(int i=1;i<=ver;i++)
	 	{
	 		for(int j=1;j<=ver;j++)
	 		{
	 			cout<<mat[i][j]<<" ";
			 }
			 cout<<"\n";
		 }
	 }
	 void Dfs_Adj_list()
	 {
	 	Graph g2;
	 	
	 	for(int i=0;i<ver;i++)
		{
			visited[i]=0;
		}
	 	
	 	int v1;
	 	cout<<"Enter the starting vertex \n";
	 	cin>>v1;
	 	g2.push(v1);
	 	visited[v1]=1;
	 	
	 	while(!g2.isEmpty())
	 	{
	 		v1=g2.pop();
	 		cout<<v1<<"->";
	 		
	 		cn=root[v1];
	 		while(cn!=NULL)
	 		{
	 			if(visited[cn->data]==0)
	 			{
	 				visited[cn->data]=1;
	 				g2.push(cn->data);
				 }
				 cn=cn->next;
			 }
		 }
	 	
	 }
	/* void Dfs_Adj_Mat(int start)
	 {
	 	
	 	for(int i=0;i<ver;i++)
		{
			visited[i]=0;
		}
		cout<<start<<"->";
		visited[start]=1;
		for(int i=0;i<ver;i++)
		{
			if(mat[i][start]==1 && visited[i]==0)
			{
				Dfs_Adj_Mat(i);
			}
		}
	 }*/
	 void Dfs_Adj_Mat()
	 {
	 	Graph g1;
	 	int s;
	 	for(int i=1;i<=ver;i++)
		{
			visited[i]=0;
		}
		cout<<"Enter the starting vertex \n";
		cin>>s;
		visited[s]=0;
		g1.push(s);
		
		while(!g1.isEmpty())
		{ 
			int x=g1.pop();
			cout<<x<<"->";
			for(int i=1;i<=ver;i++)
			{
				if(mat[x][i]==1 && visited[i]==0)
				{
					g1.push(i);
					visited[i]=1;
				}
			}
		}
		
	 }
 };
 int main()
 {
 	Graph g1;
 	int ch;
 	char a;
 	
 	do
 	{
 		cout<<"1.Insert in Adjacency list \n";
		cout<<"2.Display Adjacency List \n";
		cout<<"3.Insert in Adjacency Matrix \n";
		cout<<"4.Display Adjacency Matrix \n";
		cout<<"5.DFS of Adjacency List \n";
		cout<<"6.DFS of Adjacency Matrix\n";
		cout<<"Enter your Choice \n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				g1.Adj_list();
			break;
			
			case 2:
				g1.Disp_Adj_list();
			break;
			
			case 3:
				g1.Adj_mat();
			break;
			
			case 4:
				g1.Disp_Adj_mat();
			break;
			case 5:
				g1.Dfs_Adj_list();
			break;	
			
			case 6:
			/*	int start;
				cout<<"Enter starting Vertex \n";
				cin>>start;*/
				g1.Dfs_Adj_Mat();					
		} 		
 		cout<<"Do you want to continue \n";
 		cin>>a;
	 }while(a=='Y'||a=='y');
 	
 	return 0;
 }
