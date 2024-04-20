#include<iostream>
#include<vector>

using namespace std;
class DFS{
    public:
    void dfs(int node,vector<int> adj[],int vis[], vector<int>&ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
        
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int start=0;
        int vis[V]={0};
        vector<int>ls;
        dfs(start,adj,vis,ls);
        return ls;
    }
    void addEdge(vector<int>adj[],int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void printAns(vector<int>&ans){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
};

int main(){
 int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<int> adj[V];  // graph is represented as an array of vectors
    DFS g;
    
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(adj, u, v);
    }
    
    vector<int> ans = g.dfsOfGraph(V,adj);
    cout << "DFS Traversal: ";
    g.printAns(ans);      // printing the answer
    
    return 0;
}