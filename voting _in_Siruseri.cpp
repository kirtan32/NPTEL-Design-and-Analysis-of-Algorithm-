#include<iostream>
using namespace std;
void merge(int [],int ,int ,int );
void mergesort(int [],int,int);
int main()
{
	int no[5],s=0;
	int i;
	for(i=0;i<5;i++)
	{
		cin>>no[i];
		s+=no[i];	
	}
	int array[s];
	for(i=0;i<s;i++)
	{	cin>>array[i];	}
	mergesort(array,0,s-1);
	int count=1;
	int counter=0;
	for(i=1;i<s;i++)
	{
		if(array[i]==array[i-1])
		{	count++;	}
		else
		{
			if(count>=3)
			{	counter++;	}
			count=1;
		}
	}
	cout<<counter;
	return 0;
}
void mergesort(int a[],int start,int end)
{
	if(start<end)
	{
		int m = start + ((end-start)/2);
		mergesort(a,start,m);
		mergesort(a,m+1,end);
		merge(a,start,m,end);
	}
}
void merge(int a[],int start,int m,int end)
{
	int size_of_1st = m-start+1;
	int size_of_2nd = end - m;
	int x[size_of_1st],y[size_of_2nd];
	int i,j,k;
	for(i=0;i<size_of_1st;i++)
	{
		x[i] = a[start+i];
	}
	for(i=0;i<size_of_2nd;i++)
	{
		y[i] = a[m+1+i];
	}
	i=0;
	j=0;
	k=start;
	while(i<size_of_1st && j<size_of_2nd)
	{
		if(x[i]<=y[j])
		{	
			a[k++]=x[i]; i++; 
		}
		else
		{
			a[k++]=y[j]; j++;
		}		
	}
	while(i<size_of_1st)
	{
		a[k++]=x[i++];
	}
	while(j<size_of_2nd)
	{
		a[k++]=y[j++];
	}
}
