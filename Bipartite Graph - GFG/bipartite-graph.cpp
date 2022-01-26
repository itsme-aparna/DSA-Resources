// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(int src, vector<int> adj[], vector<int>&vis){
	        
	        for(auto x: adj[src]){
	            if(vis[x]==-1){
	                vis[x] = 1-vis[src];
	                if(!dfs(x, adj, vis)){
	                    return false;
	                }
	            }
	            else if(vis[x]==vis[src]){
	                return false;
	            }
	        }
	        return true;
	}
    
	bool isBipartite(int V, vector<int>adj[]){
	    //dfs

	    vector<int> vis(V, -1);
	    for(int i=0; i<V; i++){
	        if(vis[i]==-1){
	            vis[i] = 1;
	            if(!dfs(i, adj, vis)){
	                return false;
	            }
	        }
	    }
	    return true;
	    
	    
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends