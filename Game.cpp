#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<unordered_map>
//pankay 
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
		
		
		unordered_map<int,int> lad;
		unordered_map<int,int> snake;
		
		
	Game()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				mat[i][j]=0;
			}
		}
		
	    lad={{1,38},{4,14},{8,30},{21,42},{28,76},{50,67},{71,92},{80,99}};
	    snake={{32,10},{36,6},{48,26},{62,18},{88,24},{95,56},{97,78},{60,17}};
	    
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
		
		for(auto& x:lad){
		    if(ptr1==x.first){
		        ptr1=x.second;
		        l=1;
		        l_i=x.first;
		        break;
		    }
		    
		}
		
		for(auto& x:snake){
		    if(ptr1==x.first){
		        ptr1=x.second;
		        s=1;
		        s_i=x.first;
		        break;
		    }
		}
		
		if(l==1)
		{
			Game::show_plate();
			cout<<"****LADDER****  "<<l_i<<"        [IIIIIIIIIIIIIIII]      "<<lad[l_i]<<endl;
			cout<<"Your at position :"<<ptr1<<endl;
		}
		else if(s==1)
		{
			Game::show_plate();
			cout<<"****SNAKE****   "<<s_i<<"   .-'-.-'-.-'-.-'-.-(',')    "<<snake[s_i]<<endl;
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
		if(ptr2+dice<=100)
		{
			ptr2=ptr2+dice;
		}
		else
		{
			ptr2=ptr2;
		}
		
		for(auto& x:lad){
		    if(ptr2==x.first){
		        ptr2=x.second;
		        l=1;
		        l_i=x.first;
		        break;
		    }
		    
		}
		
		for(auto& x:snake){
		    if(ptr2==x.first){
		        ptr2=x.second;
		        s=1;
		        s_i=x.first;
		        break;
		    }
		}
		
		if(l==1)
		{
			Game::show_plate();
			cout<<"****LADDER****  "<<l_i<<"    [IIIIIIIIIIIIIIII]    "<<lad[l_i]<<endl;
			cout<<"Your at position :"<<ptr2<<endl;
		}
		else if(s==1)
		{
			Game::show_plate();
			cout<<"****SNAKE****   "<<s_i<<"   .-'-.-'-.-'-.-'-.-(',')    "<<snake[s_i]<<endl;
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
