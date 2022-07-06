class Solution {
public:
    
    bool dfs(unordered_map<int, vector<int>>& adj, vector<int>& vis, int x){
        if(vis[x]==1)
            return true;
        if(vis[x]==0){
            vis[x]=1;
            for(auto i: adj[x]){
                if(dfs(adj, vis, i)){
                    return true;
                }
            }
        }
        
        vis[x]=2;
        return false;
    }
    
    
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size()==1)
            return false;
        unordered_map<int, vector<int>> adj;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int next = i+nums[i];
            if(next<0){
                next = n - (abs(next)%n);
            }
            else{
                next = next%n;
            }
            if(next!=i && ((nums[next]<0 && nums[i]<0) || (nums[next]>0 && nums[i]>0))){
                adj[i].push_back(next);
            }
            
        }
        
        vector<int> vis(n, 0);
        for(int a = 0; a<n; a++){
            if(!vis[a] && dfs(adj, vis, a)){
                return true;
            }
        }
        
        return false;
    }
};