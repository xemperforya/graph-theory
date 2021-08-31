// Graph Theory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <deque>
using namespace std;
struct node
{
    int edge;
    int weight;
};
class graph 
{
    map<int, vector<node>> G;
    int n_nodes;
public:
    void create_graph(vector<vector<int>>);

    void DFS(int,int []);
    
    map<int,int> connected_comps(int);
    void DFS_CC(int, int[], map<int, int>&, int);
    
    void BFS(int,int []);

    void check_graph();
};

void graph::create_graph(vector<vector<int>> arr)
{
    n_nodes = arr[0].size();

    for (int i = 0; i < arr.size(); i++)
    {
        vector<node> v;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j])
            {
                node temp;
                temp.edge = j;
                temp.weight = arr[i][j];
                v.push_back(temp);
            }
        }
        G[i] = v;
    }
    

}

// Depth First Search 
// augment = Traversal
void graph::DFS(int node,int visited[])
{
    if (visited[node]) return;

    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < G[node].size(); i++)
        DFS(G[node][i].edge,visited);
}



//Depth First Search
// augment = connected components


void graph::DFS_CC(int node, int visited[],map<int,int> &components,int count)
{
    if (visited[node]) return;

    visited[node] = 1;
    components.insert({node,count});
    for (int i = 0; i < G[node].size(); i++)
        DFS_CC(G[node][i].edge, visited,components,count);
}

// connected components

map<int,int> graph::connected_comps(int node)
{
    int *visited = new int[this->n_nodes];
    memset(visited, 0, sizeof(int) * this->n_nodes);
    map<int,int> components;
    int count = 0;
    for (auto x : G)
    {
        if (!visited[x.first]) {
            DFS_CC(x.first, visited, components, count);
            count++;
        }
    }
    return components;
}



// Breadth First Search
// augmented = Traversal

void graph::BFS(int node, int visited[])
{
    deque<int> q;
    int queued[13] = { 0 };
    q.push_back(node);
    queued[node] = 1;
    while (!q.empty())
    {
        int elem = q.front();
        q.pop_front();
        visited[elem] = 1;
        cout << elem << " ";

        for (auto x : G[elem])
        {
            if (!visited[x.edge] && !queued[x.edge]) {
                q.push_back(x.edge);
                queued[x.edge] = 1;
            }
        }
    }
}
// check graph
void graph::check_graph()
{
    for (auto i : G)
    {
        cout << i.first << "-> ";
        for (int j = 0; j < i.second.size(); j++)
            cout << i.second[j].edge << " ";
        cout << endl;
    }
}


// 
int main()
{
    vector<vector<int>> arr = {
        { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 1 , 0 },
        { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 },
        { 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 },
        { 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
        { 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
        { 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
        { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
        { 1 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
        { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 },
        { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 },
        { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
        { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
        { 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
    };
    graph g;
    g.create_graph(arr);
    g.check_graph();
    int visited[13] = { 0 };
    g.BFS(0, visited);


    //vector<vector<int>> arr1 = {
    //    { 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
    //    { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 },
    //    { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 },
    //    { 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 },
    //    { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
    //};
    //graph g1;
    //g1.create_graph(arr1);
    //g1.check_graph();
    //map<int, int> m = g1.connected_comps(0);
 
    //for (auto x : m)
    //{
    //    cout << x.first << " " << x.second<<endl;
    //}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
