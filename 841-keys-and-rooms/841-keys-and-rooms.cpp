class Solution {
public:
    
    void dfs(unordered_map<int, vector<int> >& adj, vector<bool>& vis, int node){
        // if(vis[node]==true)
        //     return;
        vis[node] = true;
        for(auto i: adj[node]){
            if(!vis[i])
                dfs(adj, vis, i);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int> > adj;
        for(int i=0; i<rooms.size(); i++){
            for(int j=0; j<rooms[i].size(); j++){
                if(i!= rooms[i][j]){
                    adj[i].push_back(rooms[i][j]);
                }
            }
            
        }
        
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        vis[0] = true;
        dfs(adj, vis, 0);
        
        for(int i=0; i<rooms.size(); i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};