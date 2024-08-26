// cpp program to implement Kruskal's Algorithm for finding MST(Minimum Cost Spanning Tree) in a graph(using disjoint subsets - data structure)
#include<iostream>
#include<vector>

#define I 32767     // int - 4 bytes - maximum integer - to denote infinity

using namespace std;

// class for graph edges
class Graph
{
    private:
        int v;                  // v - no. of vertices of the graph
        int e;                  // e - no. of edges of the graph
        vector<vector<int>> edges;   // cost - cost edge matrix - undirected and weighted graph - 1st,2nd-rows -> vertex, 3rd-row -> cost of that edge
        vector<int> set;        // set - disjoint subset (data structure) - to detect cycles while selecting minimum cost edge from the graph
        vector<int> included;   // to know the selected edges for the solution
        vector<vector<int>> t;  // t - to store the result edges from Kruskal's Algorithm of the graph

    public:
        Graph(vector<vector<int>> graph, int vertices, int edge);

        // To perform operation on disjoint subsets (data structure)
        void Union(int u, int v);   // weighted union
        int Find(int u);            // find (not collapsing find)

        vector<vector<int>> kruskalsAlgorithm();      // Kruskal's Algorithm is used to find the MST(Minimum Cost Spanning Tree) in the graph
};

// implementing the functions of the above class
Graph :: Graph(vector<vector<int>> graph, int vertices, int edge)
{
    this->v = vertices;
    this->e = edge;

    edges.resize(3, vector<int>(this->e, 0));     // assigns default values to all indices as vector<int> -> with size-e, default values as 0

    set.resize(this->v+1, -1);                      // assigns default values to all indices as '-1' and with size-> v+1

    included.resize(this->e, 0);                    // resize the vector - included - with size(e) and value (0)

    t.resize(2, vector<int>(this->v-1, 0));         // assigns default values to all indices as vector<int> -> with size-(v-1), default values as 0

    // getting input for the graph
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<this->e;j++)
            edges[i][j] = graph[i][j];
    }
}

// function to perform union operation on two parents sets
void Graph :: Union(int u, int v)
{
    if(set[u] < set[v])
    {
        set[u] = set[u] + set[v];

        set[v] = u;
    }
    else
    {
        set[v] = set[u] + set[v];

        set[u] = v;
    }
}

// function to perform find operation - to find the parent of a node(set element)
int Graph :: Find(int u)
{
    int x = u;

    while(set[x] > 0)     // until set[x] is positive
        x = set[x];
    
    return x;
}

// function to implement Kruskal's Algorithm on a graph
vector<vector<int>> Graph :: kruskalsAlgorithm()
{
    int i, j, k, u, v, min;

    i = 0;

    // repetitive process
    while(i < this->v-1)
    {
        min = I;

        // step1 - finding minimum cost edge from edge matrix
        for(j=0;j<this->e;j++)
        {
            if(included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                u = edges[0][j], v = edges[1][j];
                k = j;
            }
        }

        // step2 - find whether the selection of the two vertices - selecting that edge will form a cycle or not
        if(Find(u) != Find(v))
        {
            t[0][i] = u, t[1][i] = v;   // add vertices - edge to the result array

            Union(Find(u), Find(v));    // perform weighted union on the parent of u, v
            
            i++;
        }

        included[k] = 1;                // update the included array
    }

    return t;
}

int main()
{
    vector<vector<int>> graph = {   
                                    { 1, 1,  2,  2, 3,  4,  4,  5,  5},
                                    { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                                    {25, 5, 12, 10, 8, 16, 14, 20, 18}
                                };

    int vertices, edges;   // vertices - 7, edges - 9

    cout<<"Enter the number of the vertices of the graph : ";
    cin>>vertices;

    cout<<"Enter the number of the edges of the graph : ";
    cin>>edges;

    Graph g(graph, vertices, edges);

    // output - display

    vector<vector<int>> result;  // to store the result of Kruskal's Algorithm

    result = g.kruskalsAlgorithm();

    // to display the result of Kruskal's Algorithm
    cout<<"\nResult of Kruskal's Algorithm : "<<endl;

    for(int j=0;j<result[0].size();j++)
        cout<<"("<<result[0][j]<<", "<<result[1][j]<<")"<<endl;    

    return 0;
}