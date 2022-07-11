class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<richer.size(); i++){
            adj[richer[i][1]].push_back(richer[i][0]);
            
        }
        
        vector<int> ans(quiet.size(), -1);
        for(int i=0; i<quiet.size(); i++){
            dfs(quiet, adj, i, ans);
            
        }
        return ans;
    }
    
    int dfs(vector<int>& quiet, unordered_map<int, vector<int>>& adj, int n, vector<int>& ans){
        if(ans[n]!=-1)
            return ans[n];
        ans[n] = n;
        for(auto &i: adj[n]){
            if(quiet[ans[n]]> quiet[dfs(quiet, adj, i, ans)]){
                ans[n] = ans[i];
            }
        }
        return ans[n];
    }
};