#include<iostream>
#include<limits.h>
#include<list>
#define infinite 1000
using namespace std;

class bellman
{
	int v;
	list<int> *adj;
	int **time;
	int **iteration;
	int *maintain;
	public:
	bellman(int vertex)
	{
		v=vertex;
		adj = new list<int>[v];
		int i=0,j=0;
		time = new int*[v];
		iteration = new int*[v];
		maintain = new int[v];
		for(i=0;i<v;i++)
		{	
			time[i]=new int[v];
			iteration[i]=new int[v];
			maintain[i]=0;	
			for(j=0;j<v;j++)
			{	time[i][j]=0;iteration[i][j]=infinite;	}
		}
	}
	void addEdge(int v1,int v2,int w)
	{
		adj[v1].push_back(v2);
		time[v1][v2]=w;
	}
	void traverse(int v1)
	{
		iteration[v1][0]=0;
		int i=0,j=0,l=0;
		cout<<"\n\n";
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				cout<<"\t\t"<<iteration[i][j];
			}
			cout<<"\n";
		}
		cout<<"\n\n\n";
		for(i=1;i<v;i++)
		{
			iteration[v1][i]=0;
			for(j=0;j<v;j++)
			{
				list<int>::iterator k;
				for (k = adj[j].begin(); k != adj[j].end(); k++)
				{
					if(iteration[j][i-1]!=infinite)
					{
					if((iteration[*k][i-1]>iteration[j][i-1] + time[j][*k]))
					{
						iteration[*k][i]=iteration[j][i-1]+time[j][*k];
						maintain[*k]=1;
					}
					}
					//else if((iteration[*k][i]>iteration[j][i-1] + time[j][*k]) && maintain[*k]==1)
	
				}
			}
			for(l=0;l<v;l++)
			{
				if(maintain[l]==0)
				{	iteration[l][i]=iteration[l][i-1];	}
				else
				{	maintain[l]=0;	}
			}
		}
		cout<<"\n\n";
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				cout<<"\t\t"<<iteration[i][j];
			}
			cout<<"\n";
		}
	}
};
int main()
{
	bellman b1(8);
	b1.addEdge(0,1,10);
	b1.addEdge(0,7,8);
	b1.addEdge(1,5,2);
	b1.addEdge(2,1,1);
	b1.addEdge(2,3,1);
	b1.addEdge(3,4,3);
	b1.addEdge(4,5,-1);
	b1.addEdge(5,2,-2);
	b1.addEdge(6,1,-4);
	b1.addEdge(6,5,-1);
	b1.addEdge(7,6,1);
	return 0;
}
