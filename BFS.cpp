#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(vector<vector<int>>& adj, int s, vector<bool>& visited){
    //create a queue for BFS
    queue<int> q;

    //mark the current node as visited
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";


        for (int i : adj[curr]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);//since it is an undirected graph
}

int main(){
    int vertices = 5;
    vector<vector<int>> adj(vertices);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    //mark all vertices as not visited
    vector<bool> visited(vertices, false);

    cout<<"BFS traversal starting from vertex 0 : \n";
    BFS(adj, 0, visited);

    return 0;
}