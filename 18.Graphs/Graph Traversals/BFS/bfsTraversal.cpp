// cpp program to implement BFS Traversal on a Graph
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// class for Graph
class Graph
{
private:
    int n;      // n - dimensional of the Adjacency matrix
    vector<vector<int>> G;    // G - Adjacency Matrix with n*n (dimension)
    vector<int> visited;    // visited - array which contains 0 / 1 => 0 - not visited, 1 - visited

public:
    Graph(vector<vector<int>>);

    void BFS(int start);   // start - starting vertex for BFS Traversal 
};

// implementing the above functions of the class
Graph :: Graph(vector<vector<int>> graph)
{
    this->n = graph.size();

    G.resize(n, vector<int>(n, 0));     // assigns default values to all indices as vector<int> -> with size-n, default values as 0

    visited.resize(n, 0);   // assigns default values to all indices as 0

    int i, j;

    // getting input for the graph
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            G[i][j] = graph[i][j];
        }
    }
}

// function to perform BFS Traversal on a graph
void Graph :: BFS(int start)
{
    int i, j;

    queue<int> q;

    cout<<start<<" ";

    visited[start] = 1;

    q.push(start);

    while(!q.empty())
    {
        i = q.front();

        q.pop();

        for(j=1;j<this->n;j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                cout<<j<<" ";

                visited[j] = 1;

                q.push(j);
            }
        }
    }
}

int main()
{  
    // row0, column0 - are not used in Adjacency matrix
    vector<vector<int>> graph = {
                                    {0,0,0,0,0,0,0},
                                    {0,0,1,1,0,0,0},
                                    {0,1,0,0,1,0,0},
                                    {0,1,0,0,1,0,0},
                                    {0,0,1,1,0,1,1},
                                    {0,0,0,0,1,0,0},
                                    {0,0,0,0,1,0,0}      
                                };
        

    Graph g(graph);     // 7 - size of the graph -> 7x7 - matrix dimension

    g.BFS(1);
}