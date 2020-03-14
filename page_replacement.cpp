#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define max 100
#define min 10

void autoinput();
void input();
void FIFO();
void LRU();

int ref[max];
int count,frame[min];
int n,counter,i,temp;

int main()
{
	int choice;
	while(1)
	{        
		cout<<"\n\t\torder";
        cout<<"\n1. Enter value introduction";
		cout<<"\n2. FIFO Algorithm";
		cout<<"\n3. LRU Algorithm";
		cout<<"\n4. exit";
		cout<<"\n\n please choose order what yo want\n";
		cin>>choice;   
		switch(choice)
		{
			 case 1:
			 	input();
			 		break;
			case 2:
				FIFO();
					break;
			case 3:
				LRU();
					break;
			case 4:
				exit(0);
		}
	}
    return 0;
}


void input()
{
	
	count = 0;
    cout<<"\n\nEnter member frame for search : ";
	cin>>n;
	cout<<"\n\nReference (-1 for stopEnterValue) : \n";
	cin>>temp;

	while(temp != -1)
	{
		ref[count++]=temp;
		cin>>temp;
	}
}

void FIFO()
{
	int i,j,fault=0;

	for(i=0;i<n;i++)
	frame[i]=-1;

		for(i=0;i<count;i++)
		{
			for(j=0;j<n;j++)
			if(frame[j]==ref[i])
			break;
			if(j==n)
			frame[fault%n]=ref[i], fault++;
			cout<<"\n\nafter entervalue   : "<<ref[i];
            cout<<"\nQueue: ";
			for(j=0;j<n;j++)
				cout<<frame[j];
		}
	cout<<"\n\n\tfinished reference";
    cout<<"\n\nEnter member frame for search : "<<fault;
}

void LRU()
{
	int i,j,k,stack[min];
	int top=0,fault=0;

	for(i=0;i<count;i++)
	{
		if(top<n)
			stack[top++]=ref[i],fault++;
		else
		{
			for(j=0;j<n;j++)
				if(stack[j]==ref[i])
					break;
			if(j<n)
			{
				for(k=j;k<n-1;k++)
					stack[k]=stack[k+1];
				stack[k]=ref[i];
			}
			else
			{
				for(k=0;k<n-1;k++)
					stack[k]=stack[k+1];
				stack[k]=ref[i];
				fault++;
			}
		}
		cout<<"\n\nafter entervalue   : "<<ref[i];
        cout<<"\nQueue: ";
		for(j=0;j<top;j++)
			cout<<stack[j];
	}
	cout<<"\n\n\tfinished reference";
    cout<<"\n\nEnter member frame for search : "<<fault;
}
