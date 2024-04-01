#include<iostream>
#include<vector>

using namespace std;
class BFS{
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
    vector<int>adj[7];  //graph is represented as an array of vectors
     BFS g;
     g.addEdge(adj,0,1);   //adding edges
     g.addEdge(adj,1,2);   //adding edges
     g.addEdge(adj,1,3);   //adding edges
     g.addEdge(adj,5,4);   //adding edges
     g.addEdge(adj,5,6);   //adding edges
     g.addEdge(adj,0,5);   //adding edges
     vector<int>ans=g.dfsOfGraph(7,adj);
     g.printAns(ans);      //printing the answer

    
return 0;
}