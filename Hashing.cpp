#include<iostream>
#include<math.h>
using namespace std;
struct client
{
	int tel;
	string name;
	string Add;	
};
class Hashing
{
	public:
	client HT[20];
	int flag[20];
	int n;
	int chain[20];
		
		Hashing()
		{
			for(int i=0;i<20;i++)
			{
				HT[i].Add=" ";
				HT[i].name=" ";
				HT[i].tel=0;
				flag[i]=0;
				chain[i]=-1;
				n=20;
			}
		}
		int Insert_lpwor()
		{
			int Tel;
			string Name;
			string Add;
			cout<<"Enter the Tel no,name, Add \n";
			cin>>Tel>>Name>>Add;
			
			int pos=Tel%n;
			
			for(int i=0;i<n;i++)
			{
				if(flag[pos]==0)
				{
					HT[pos].tel=Tel;
					HT[pos].name=Name;
					HT[pos].Add=Add;
					flag[pos]=1;
					return pos;
				}
				else
				{
					pos=(pos+1)%n;
				}
			}
			return -1;
		}
		int Insert_QP()
		{
			int Tel;
			string Name;
			string Add;
			cout<<"Enter the Tel no,name, Add \n";
			cin>>Tel>>Name>>Add;
			
			int pos=Tel%n;
			
			for(int i=0;i<n;i++)
			{
				if(flag[pos]==0)
				{
					HT[pos].tel=Tel;
					HT[pos].name=Name;
					HT[pos].Add=Add;
					flag[pos]=1;
					return pos;
				}
				else
				{
					pos=(pos+i*i)%n;
				}
			}
			return -1;
		}
		void Display()
		{
			cout<<"Telephone"<<"\t"<<"Name"<<"\t"<<"Address"<<"\n";
			for(int i=0;i<n;i++)
			{
					cout<<HT[i].tel<<"\t";
					cout<<HT[i].name<<"\t";
					cout<<HT[i].Add;
					
					cout<<"\n";
			}
			
		}
		void Searching_lpwor()
		{
			int ser;
			cout<<"Enter the tel no to search \n";
			cin>>ser;
			int flag=0;
			int pos=ser%n;
			for(int i=0;i<n;i++)
			{
				if(HT[pos].tel==ser)
				{
					cout<<"Pressent !\n";
					flag=1;
					break;
				}
				else
				{
					pos=(pos+1)%n;
				}
			}
			if(flag==0)
			{
				cout<<"Not Present !\n";
			}
		}
		void Searching_QP()
		{
			int ser;
			cout<<"Enter the tel no to search \n";
			cin>>ser;
			int flag=0;
			int pos=ser%n;
			for(int i=0;i<n;i++)
			{
				if(HT[pos].tel==ser)
				{
					cout<<"Pressent !\n";
					flag=1;
					break;
				}
				else
				{
					pos=(pos+i*i)%n;
				}
			}
			if(flag==0)
			{
				cout<<"Not Present !\n";
			}
		}
		void Insert_lpworwc()
		{
			int i=0,j;
			int tel;
			string name,add;
			
			cout<<"Enter the Tell No, Name, Address \n";
			cin>>tel>>name>>add;
			
			int pos=tel%n;
			while(flag[pos]==1 && i<n)
			{
				if(HT[pos].tel % n == tel % n)
				{
					break;
				}
				pos=(pos+1)%n;
				i++;
			}
			if(i==n)
			{
				cout<<"Overflow \n";
				return;
			}
			while(chain[pos]!=-1)
			{
				pos=chain[pos]+1;
			}
			j=pos;
			while(flag[j]==1 && i<n)
			{
				j=(j+1)%n;
				i++;
			}
			if(i==n)
			{
				cout<<"hash is full \n";
				return;
			}
			
			HT[j].tel=tel;
			HT[j].name=name;
			HT[j].Add=add;
			
			flag[j]=1; 
			if(j!=pos)
			{
				chain[pos]=j;
			}
		}
		
		int search_LPWORWC()
		{
			int key;
			int i=0,j;
			cout<<"Enter the telephone Number to Search \n";
			cin>>key;
			j=key%n;
			while(i<n && flag[j]==1 && HT[j].tel%n != key%n)
			{
				i++;
				j=(j+1)%n;
			}
			if(flag[j]==0||i==n)
			{
				return -1;
			}
			
			while(j!=-1)
			{
					if(HT[j].tel==key)
					{
						return j;
					}						
					j=chain[j];
			}	
								return -1;		
		}		
};
int main()
{

	Hashing h1,h2,h3;
	int ch,b;
	char a;
	do
	{
			cout<<endl<<"############# MENU ########### \n";
			cout<<"1.Insert LPWOR\n";
			cout<<"2.Display LPWOR\n";
			cout<<"3.Search in LPWC\n";
			cout<<"4.Insert In Quadratic Probing \n";
			cout<<"5.Display Quadratic Probing \n";
			cout<<"6.Search in Quadratic Probing \n";
			cout<<"7.Insert LPWORWC\n";
			cout<<"8.Display LPWORWC\n";
			cout<<"9.Search in LPWORWC\n";
			cout<<endl<<"Enter your choice \n";						
			cin>>ch;
			switch(ch)
			{
			 case 1:				
					h1.Insert_lpwor();
				break;
			case  2:
				
					h1.Display();
				break;
			case 3:
					h1.Searching_lpwor();
			case 4:
					h2.Insert_QP();
				break;
				
			case 5:
					h2.Display();
				break;
				
			case 6:
					h2.Searching_QP();
				break;	
			
			case 7:
					h3.Insert_lpworwc();
				break;
				
			case 8:
					h3.Display();
				break;				
			case 9:
					b =h3.search_LPWORWC();
					if(b==-1)
					{
						cout<<"Number is not present in the hash \n";
					}		
					else
					{
						cout<<"Number is present \n";
					}
					
				break;
						
				default:
				cout<<"Wrong Input \n";
			}
		cout<<endl<<"Do you want to contineu \n";
		cin>>a;
	}while(a=='Y'||a=='y');					

		return 0;
}
