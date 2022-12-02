#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>

using namespace std;


class Game
{
	public:
		int mat[10][10];
		int ptr1=1;
		int ptr2=1;
		int dice;
		int no;
		char name1[10];
		char name2[10];
		int lad[8],laddist[8],snake[8],snakedist[8];
		
		
	Game()
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
		cout<<"Enter name of palyer 1 :";
		cin>>name1;
		cout<<"Enter name of player 2 :";
		cin>>name2;
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
		}
	}
	
	void roll_dice_1()
	{
		int l=0;
		int s=0;
		int l_i,s_i;
		
		srand(time(0));
		dice=rand()%6+1;
		if(ptr1+dice<=100)
		{
			ptr1=ptr1+dice;
		}
		else
		{
			ptr1=ptr1;
		}
		
		for(int i=0;i<8;i++)
		{
			if(ptr1==lad[i])
			{
				
				ptr1=laddist[i];
				l=1;
				l_i=i;
				break;
			}
			else if(ptr1==snake[i])
			{
				
				ptr1=snakedist[i];
				s=1;
				s_i=i;
				break;
			}
			
		}
		
		if(l==1)
		{
			Game::show_plate();
			cout<<"****LADDER****  "<<lad[l_i]<<"        [IIIIIIIIIIIIIIII]      "<<laddist[l_i]<<endl;
			cout<<"Your at position :"<<ptr1<<endl;
		}
		else if(s==1)
		{
			Game::show_plate();
			cout<<"****SNAKE****   "<<snake[s_i]<<"   .-'-.-'-.-'-.-'-.-(',')    "<<snakedist[s_i]<<endl;
			cout<<"Your at position :"<<ptr1<<endl;
		}
		else
		{
			Game::show_plate();
			cout<<"Your at position :"<<ptr1<<endl;
			cout<<"Dice :"<<dice<<endl;
		}
		
	}
		
	void roll_dice_2()
	{
		int l=0;
		int s=0;
		int l_i,s_i;
		
		srand(time(0));
		dice=rand()%6+1;
		if(ptr1+dice<=100)
		{
			ptr2=ptr2+dice;
		}
		else
		{
			ptr2=ptr2;
		}
		
		for(int i=0;i<8;i++)
		{
			if(ptr2==lad[i])
			{
				
				ptr2=laddist[i];
				l=1;
				l_i=i;
				break;
			}
			else if(ptr2==snake[i])
			{
				
				ptr2=snakedist[i];
				s=1;
				s_i=i;
				break;
			}
			
		}
		if(l==1)
		{
			Game::show_plate();
			cout<<"****LADDER****  "<<lad[l_i]<<"    [IIIIIIIIIIIIIIII]    "<<laddist[l_i]<<endl;
			cout<<"Your at position :"<<ptr2<<endl;
		}
		else if(s==1)
		{
			Game::show_plate();
			cout<<"****SNAKE****   "<<snake[s_i]<<"   .-'-.-'-.-'-.-'-.-(',')    "<<snakedist[s_i]<<endl;
			cout<<"Your at position :"<<ptr2<<endl;
		}
		else
		{
			Game::show_plate();
			cout<<"Your at position :"<<ptr2<<endl;
			cout<<"Dice :"<<dice<<endl;
		}
		
	}
	
	void show_plate()
	{
		system("CLS");
		
		for(int i=9;i>=0;i--)
		{
			for(int j=0;j<10;j++)
			{
				if(mat[i][j]==ptr1)
				{
					if(ptr1==ptr2)
					{
						cout<<"{["<<mat[i][j]<<"]}\t";
					}
					else
					{
						cout<<"["<<mat[i][j]<<"]\t";
					}
				}
				else if(mat[i][j]==ptr2)
				{
					cout<<"{"<<mat[i][j]<<"}\t";
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
	Game m;
	m.insert();
	int chance=0;
	int ch;
	
	while(m.ptr1<=100 and m.ptr2<=100)
	{
		if(chance==0)
		{
			cout<<m.name1<<" your chance Enter 1 to Roll dice  :";
			cin>>ch;
			
			if(ch==1)
			{
				m.roll_dice_1();
				
			}
			chance++;
			
		}
		else if(chance==1)
		{
			cout<<m.name2<<" your chance Enter 1 to Roll dice  :";
			cin>>ch;
			
			if(ch==1)
			{
				m.roll_dice_2();
				
			}
			chance--;
		}
		
		
		if(m.ptr1>=100)
		{
			int ch;
			cout<<"================================================\n";
			cout<<m.name1<<" has won the game\n";
			cout<<"================================================\n";
			
			cout<<"To play agian Press 5  :";
			cin>>ch;
			if(ch==5)
			{
				cout<<"Lets Play\n";
				m.ptr1=1;
				m.ptr2=1;
			}
			else
			{
				break;
			}
			
		}
		else if(m.ptr2>=100)
		{
			cout<<"================================================\n";
			cout<<m.name1<<" has won the game\n";
			cout<<"================================================\n";
			
			cout<<"To play agian Press 5  :";
			cin>>ch;
			if(ch==5)
			{
				cout<<"Lets Play\n";
				m.ptr1=1;
				m.ptr2=1;
			}
			else
			{
				break;
			}
			
		}
		
	
	}
	return 0;
}
