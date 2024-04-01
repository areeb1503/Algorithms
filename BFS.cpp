#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class BFS{
    public:
    vector<int>bfsOfGraph(vector<int>adj[],int V){
        int vis[V]={0};
        queue <int> q;
         vis[0]=1;
         q.push(0);
         vector<int>bfs;
         while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
           for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
         }
         return bfs;

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
     vector<int>ans=g.bfsOfGraph(adj,7);
     g.printAns(ans);      //printing the answer

    
return 0;
}