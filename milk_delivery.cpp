#include<iostream>

using namespace std;

//use Insertion Sort here
void assending_order(int a[],int size)
{
	int i, key, j;  
    for (i = 1; i < size; i++) 
    {  
        key = a[i];  
        j = i - 1;  
        while (j >= 0 && a[j] > key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }
}
void descending_order(int a[],int size)
{
	int i, key, j;  
    for (i = 1; i < size; i++) 
    {  
        key = a[i];  
        j = i - 1;  
        while (j >= 0 && a[j] < key) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  	
}

int main()
{
	int n,p,f;   // p-->limit,  f--> fine
	cin>>n>>p>>f;
	int i;
	int morning[n];
	int night[n];
	for(i=0;i<n;i++)
	{	cin>>morning[i];	}
	for(i=0;i<n;i++)
	{	cin>>night[i];	}
	assending_order(morning,n);
	descending_order(night,n);
	float total_fine=0;
	for(i=0;i<n;i++)
	{	
		if(morning[i]+night[i]>p)
		{	
			total_fine+=(morning[i]+night[i]-p)*f;
		}
	}
	cout<<total_fine<<"\n";

	return 0;
}
