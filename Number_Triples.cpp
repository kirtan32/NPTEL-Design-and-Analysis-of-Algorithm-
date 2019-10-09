#include<iostream>
#include<limits.h>
#include <set> 
#include <iterator> 
#include<list>
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
int max_value(int a[][3],int size)
{
	int max=0;
	for(int i=0;i<size;i++)
	{
		if(max<a[i][0]){max=a[i][0];}
		if(max<a[i][2]){max=a[i][2];}
	}
	return max;
}
int find_position(int node[],int size,int no)
{
	for(int i=0;i<size;i++)
	{
		if(no==node[i]){	return i;	}
	}
	return -1;
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
	int traverse(int v1,int v2)
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
		return E_burn_time[v2];
	}
		
};
int main()
{	//list<int> *l1;
	set <int> set1; 
	long int no;
	int start,end;
	cin>>no>>start>>end;
	long int ar[no][3];
	for(int i=0;i<no;i++)
	{
		cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
		set1.insert(ar[i][0]);
		set1.insert(ar[i][2]);
	}
	int nodes[set1.size()];
	int i=0;
	for (auto itr = set1.begin(); itr != set1.end(); ++itr) 
    { 
        nodes[i]=*itr;
		i++;
    } 
	int size=set1.size(); 
	int match1=0,match2=0;
	for(int i=0;i<size;i++)
	{
		if(start==nodes[i]){match1=1;}
		if(end==nodes[i]){match2=1;}
	}
	if(match1==1 && match2==1)
	{
		dijk d1(size);
		for(int i=0;i<no;i++)
		{
			d1.addEdge(find_position(nodes,size,ar[i][0]),find_position(nodes,size,ar[i][2]),ar[i][1]);
		}
		int trvs=d1.traverse(find_position(nodes,size,start),find_position(nodes,size,end));
		cout<<"\nYES\n"<<trvs;
	}
	else
	{	cout<<"\nNO";	}
	return 0;
}
