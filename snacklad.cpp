#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Mat
{
	public:
		int mat[10][10];
		int ptr=1;
		int dice;
		int no;
		string name[10];
		int lad[8],laddist[8],snake[8],snakedist[8];
		
	
	
	Mat()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				mat[i][j]=0;
			}
		}
		lad[0]=1,lad[1]=4,lad[2]=8,lad[3]=21,lad[4]=28,lad[5]=50,lad[6]=71,lad[7]=80;
		laddist[0]=38,laddist[1]=14,laddist[2]=30,laddist[3]=42,laddist[4]=76,laddist[5]=67,laddist[6]=92,laddist[7]=99;
		snake[0]=32,snake[1]=36,snake[2]=48,snake[3]=62,snake[4]=88,snake[5]=95,snake[6]=97,snake[7]=17;
		snakedist[0]=10,snakedist[1]=6,snakedist[2]=26,snakedist[3]=18,snakedist[4]=24,snakedist[5]=56,snakedist[5]=78,snakedist[7]=60;
		
		
	}
	
	void insert()
	{
		int n=1;
		for(int i=0;i<10;i++)
		{
			if((i+1)%2!=0)
			{
				for(int j=0;j<10;j++)
				{
					mat[i][j]=n;
					n++;
				}
				
			}
			else
			{
				for(int j=9;j>=0;j--)
				{
					mat[i][j]=n;
					n++;
				}
				
			}
			
			cout<<"Enter no of players :";
			cin>>no;
			for(int i=0;i<no;no++)
			{
				cout<<"Enter name of player "<<i+1<<" : \n";
				cin>>name[i];
			}
			
		}
		
		
	}
	
	void display()
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=0;j<10;j++)
			{
				cout<<mat[i][j]<<" \t";
			}
			cout<<"\n";
		}
	}
	
	void roll_dice()
	{
		int l=0;
		int s=0;
		int l_i,s_i;
		
		srand(time(0));
		dice=rand()%6+1;
		if(ptr+dice<=100)
		{
			ptr=ptr+dice;
		}
		else
		{
			ptr=ptr;
		}
		
		for(int i=0;i<8;i++)
		{
			if(ptr==lad[i])
			{
				
				ptr=laddist[i];
				l=1;
				l_i=i;
				break;
			}
			else if(ptr==snake[i])
			{
				
				ptr=snakedist[i];
				s=1;
				s_i=i;
				break;
			}
			
		}
		
		if(l==1)
		{
			Mat::show_plate();
			cout<<"****LADDER****  "<<lad[l_i]<<"->"<<laddist[l_i]<<endl;
			cout<<"Your at position :"<<ptr<<endl;
		}
		else if(s==1)
		{
			Mat::show_plate();
			cout<<"****SNAKE****   "<<snake[s_i]<<"->"<<snakedist[s_i]<<endl;
			cout<<"Your at position :"<<ptr<<endl;
		}
		else
		{
			Mat::show_plate();
			cout<<"Your at position :"<<ptr<<endl;
			cout<<"Dice :"<<dice<<endl;
		}
		
				
		
		
		if(ptr>=100)
		{
			cout<<"You have won the game ";
			return;
			
		}
	}
	
	void show_plate()
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=0;j<10;j++)
			{
				if(mat[i][j]==ptr)
				{
					cout<<"->"<<mat[i][j]<<"<-\t";
				}
				else
				{
					cout<<mat[i][j]<<"\t";
				}
			}
			cout<<"\n";
		}
	}
};

int main()
{
	Mat m;
	Mat n;
	m.insert();
	n.insert();
	int ch,c;
	do
	{
		cout<<"\nMenu\n1.Roll Dice\n2.Show Plate\n3.Exit\n";
		cout<<"Enter your choice :\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(m.ptr>=100)
				{
					cout<<"Game is Over Enter 5 to play again :\n";
					cin>>c;
					if(c==5)
					{
						cout<<"Lets play\n";
						m.ptr=1;
						break;
					}
					else
					{
						cout<<"Bye\n";
						break;
					}
				}
				else
				{
					m.roll_dice();
					n.roll_dice();
					break;
				}
				m.roll_dice();
				break;
			case 2:
				m.show_plate();
				break;
			case 3:
				break;
		}
	}while(ch!=3);
	
}
