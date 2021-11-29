class Solution {
    private:
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> adjList;
        unordered_set<string> vis;
public:
    
    
    void dfs(string& email) {
        vis.insert(email);
        ans.back().push_back(email);
        for(auto& adjEmail : adjList[email]) 
            if(!vis.count(adjEmail)) 
                dfs(adjEmail);        
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto it: accounts){
            for(int i=2; i<it.size(); i++){
                adjList[it[i]].push_back(it[i-1]);
                adjList[it[i-1]].push_back(it[i]);
            }
        }
        
        for(auto it: accounts){
            if(!vis.count(it[1])){
                ans.push_back({it[0]});
                dfs(it[1]);
                sort(begin(ans.back())+1, end(ans.back()));
                
            }
        }
        return ans;
    }
};