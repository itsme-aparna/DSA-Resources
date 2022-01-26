class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it]==0){
                if(dfs(it, vis, pathVis, adj))
                    return true;
            }
            else if(pathVis[it]==1){
                return true;
            }
            
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};