// cpp program to implement Prim's Algorithm for finding MST(Minimum Cost Spanning Tree) in a graph
#include<iostream>
#include<vector>

#define I 32767     // int - 4 bytes - maximum integer - to denote infinity

using namespace std;

// class for graph G
class Graph
{
    private:
        int v;                  // v - no. of vertices of the graph cost
        vector<vector<int>> cost;   // cost - cost adjacency matrix - undirected and weighted graph
        vector<int> near;
        vector<vector<int>> t;  // t - to store the result edges of the graph

    public:
        Graph(vector<vector<int>> graph, int vertices);

        vector<vector<int>> primsAlgorithm();      // Prim's Algorithm is used to find the MST(Minimum Cost Spanning Tree) in the graph
};

// implementing the functions of the above class
Graph :: Graph(vector<vector<int>> graph, int vertices)
{
    this->v = vertices;

    cost.resize(this->v+1, vector<int>(this->v+1, I));     // assigns default values to all indices as vector<int> -> with size-v, default values as 0

    near.resize(this->v+1, I);                      // assigns default values to all indices as I

    t.resize(2, vector<int>(this->v-1, 0));         // assigns default values to all indices as vector<int> -> with size-(v-1), default values as 0

    // getting input for the graph
    for(int i=1;i<=this->v;i++)
    {
        for(int j=1;j<=this->v;j++)
        {
            if(graph[i][j] != I)
                cost[i][j] = graph[i][j];
        }
    }
}

// function to implement Prim's Algorithm on a graph
vector<vector<int>> Graph :: primsAlgorithm()
{
    int min = I, u, v;

    // finding the minimum cost edge from the graph only in the upper triangluar part of - cost adjacency matrix
    for(int i=1;i<=this->v;i++)
    {
        for(int j=i;j<=this->v;j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];

                u = i, v = j;
            }
        }
    }

    // updating t, near - 1st time
    t[0][0] = u, t[1][0] = v;
    near[u] = near[v] = 0;

    // updating near based on u, v - for the 1s time
    for(int i=1;i<=this->v;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // repetitive process - 1.  finding minimum cost edge which is connected to the previous vertices and should be minimum from near
    //                      2.  updating - t based on 'k'
    //                      3.  updating - 'near' based on 'k'

    int k;

    for(int i=1;i<this->v-1;i++)    // 1st edge (-with minimum cost edge) is already found and stored in 't'
    {
        min = I;
        
        // step-1
        for(int j=1;j<=this->v;j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        // step-2
        t[0][i] = k, t[1][i] = near[k];
        near[k] = 0;

        // step-3
        for(int j=1;j<=this->v;j++)
        {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    
    // cout<<"\nResult of Prim's Algorithm : "<<endl;
    
    // for(int j=0;j<this->v-1;j++)
    //     cout<<"("<<t[0][j]<<","<<t[1][j]<<")"<<endl;

    return t;
}

int main()
{
    vector<vector<int>> graph = {
                                    {I, I, I, I, I, I, I, I},
                                    {I, I, 25, I, I, I, 5, I},
                                    {I, 25, I, 12, I, I, I, 10},
                                    {I, I, 12, I, 8, I, I, I},
                                    {I, I, I, 8, I, 16, I, 14},
                                    {I, I, I, I, 16, I, 20, 18},
                                    {I, 5, I, I, I, 20, I, I},
                                    {I, I, 10, I, 14, 18, I, I}
                                };

    int n;

    cout<<"Enter the number of the vertices of the graph : ";
    cin>>n;

    Graph g(graph, n);

    vector<vector<int>> edges;  // to store the result of prim's Algorithm

    edges = g.primsAlgorithm();

    // to display the result of prim's Algorithm
    cout<<"\nResult of Prim's Algorithm : "<<endl;

    for(int j=0;j<edges[0].size();j++)
        cout<<"("<<edges[0][j]<<", "<<edges[1][j]<<")"<<endl;    
    
    g.primsAlgorithm();

    return 0;
}