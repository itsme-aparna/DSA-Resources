class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int s, int d){
        if(s==d)
            return true;
        if(vis[s])
            return false;
        vis[s] = 1;
        for(int i = 0; i<graph[s].size(); i++){
            if(dfs(graph, vis, graph[s][i], d)){
                return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
           
        }
        vector<int> vis(n, 0);
        return dfs(graph, vis, s, d);
    }
};