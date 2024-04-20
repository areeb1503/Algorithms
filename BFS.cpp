#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class BFS {
public:
    vector<int> bfsOfGraph(vector<int> adj[], int V) {
        int vis[V] = {0};
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }

    void addEdge(vector<int> adj[], int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAns(vector<int>& ans) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<int> adj[V];  // graph is represented as an array of vectors
    BFS g;
    
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(adj, u, v);
    }
    
    vector<int> ans = g.bfsOfGraph(adj, V);
    cout << "BFS Traversal: ";
    g.printAns(ans);      // printing the answer
    
    return 0;
}
