#include<iostream>
#include<limits.h>
#include<list>
#include<array>
using namespace std;
int min(int a,int b)
{
	return (a<b)?a:b;
}
int min_array(int size,int a[],bool burn[])
{
	int min=INT_MAX;
	int position;
	for(int i=0;i<size;i++)
	{
		if(min>a[i] && burn[i]==false){	min=a[i];position=i;	}
	}
	return position;
}
class dijk
{
	int v;
  	list<int> *adj;
	int **time;
	int *parent;
	bool *burn_vertex;
	int *E_burn_time;
 	public:
  	dijk(int vt)
	{
		v=vt;
		adj = new list<int>[v];
		int i=0,j=0;
		time = new int*[v];
		parent = new int[v];
		burn_vertex = new bool[v];
		E_burn_time = new int[v];
		for(i=0;i<v;i++)
		{
			time[i]=new int[v];
			for(j=0;j<v;j++){	time[i][j]=0;	}
		}
		for(i=0;i<v;i++)
		{
			parent[i]=-1;
			burn_vertex[i]=false;
			E_burn_time[i]=INT_MAX;
		}
	}
  	void addEdge(int v1, int v2,int w)
	{
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		time[v1][v2]=w;
		time[v2][v1]=w;
	}
	void traverse(int v1)
	{
		int i=0,j=0;
		E_burn_time[v1]=0;
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(burn_vertex[j]==false && j==min_array(v,E_burn_time,burn_vertex))
				{	break;	}
			}
			burn_vertex[j]=true;
			list<int>::iterator k;
			for (k = adj[j].begin(); k != adj[j].end(); k++)
        	{
				if(burn_vertex[*k]==false)
				{
					if(E_burn_time[*k]>E_burn_time[j]+time[j][*k])
					{	E_burn_time[*k]=E_burn_time[j]+time[j][*k];	parent[*k]=j;	}
				}
			}
		}
		cout<<"\n PARENT ARRAY-->";
		for(i=0;i<v;i++)
		{	cout<<"\n---->"<<i<<"->"<<parent[i];	}
		int n;
		cout<<"\nEnter Ending node--->";
		cin>>n;
		cout<<"\n";
		while(n!=-1)
		{
			cout<<"--->"<<n<<"["<<E_burn_time[n]<<"]-";
			n=parent[n];
		}
	}
};
int main()
{
	dijk d1(7);
	d1.addEdge(0,1,10);
	d1.addEdge(0,2,80);
	d1.addEdge(2,1,6);
	d1.addEdge(2,3,70);
	d1.addEdge(1,4,20);
	d1.addEdge(4,5,50);
	d1.addEdge(4,6,10);
	d1.addEdge(5,6,5);
	d1.traverse(0);
	return 0;
}
