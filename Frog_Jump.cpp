
#include <iostream>
#include <list>
using namespace std;


class Graph{
	int V;
  	list<int> *adj;
  public:
  	Graph(int V);
  	void addEdge(int v, int w);
  	int BFS();
};

Graph::Graph(int V)
{
	this->V = V;
  	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

int Graph::BFS()
{
  	int s = 0;
  	bool visited[V];
  	int parent[V];
  	for (int i = 0; i < V; i++)
    {
    	visited[i] = false;
      	parent[i] = -1;
    }
	list<int> Q;
	visited[s] = true;
  	Q.push_back(s);
  	list<int>::iterator i;
  	while (!Q.empty())
    {
    	s = Q.front();
      	Q.pop_front();
      	for (i = adj[s].begin(); i != adj[s].end(); i++)
        {

         	if (!visited[*i])
          	{
              	
          		visited[*i] = true;
              	parent[*i] = s;
            	Q.push_back(*i);
          	}
        }
    }
  
  
  	int count = 0;
  	for (int i = V-1; i >= 0; )
    {
    	i = parent[i];
      	count++;
                 
    }
  	return count-1;
}

int main()
{
	int m, n;
  	cin>> m >> n;
  	int r[m][n], d[m][n];
  
  	//graph object
  	Graph obj(m * n);
  
  	//input for program
  	for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
  		cin >> r[i][j];
      }
    }
  	for (int i = 0; i < m; i++)
  	{
  		for (int j = 0; j < n; j++)
  		{
  			cin>> d[i][j];
  		}
  	}
  
  	//real program
  	
  	int c = 0;
  	//right jump
  	for (int i = 0; i < m; i++)
    {
    	c++;
      for (int j = 0; j < n; j++)
      {
      	for (int k = 1; k <= r[i][j] && (i*n + k + j < c*n) ; k++)
      	{
      		obj.addEdge(i*n+j, i*n+k+j);
      	}
      }
    }
  
  	//down jump
  	for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
      	for (int k = 1; k <= d[i][j] && (n*i+j+k*n) < m* n; k++)
      	{
  			obj.addEdge(i*n+j,n*i+j+k*n);
      	}
      }
    }
  
  	int result = obj.BFS();
  	cout<< result << endl;
  	return 0;
  	
} 
