class Solution {
public:

    
    void dfs(int i, int j, int mid, vector<vector<bool>> &vis, vector<vector<int>> &heights){
        vis[i][j] = true;
        if(i==heights.size()-1 && j==heights[0].size()-1)
            return;
        if(i+1<heights.size() && !vis[i+1][j] && abs(heights[i][j]-heights[i+1][j])<=mid){
            dfs(i+1, j, mid, vis, heights);
        }
        if(i-1>=0 && !vis[i-1][j] && abs(heights[i-1][j] - heights[i][j])<=mid){
            dfs(i-1, j, mid, vis, heights);
            
        }
        if(j+1<heights[0].size() && !vis[i][j+1] && abs(heights[i][j] - heights[i][j+1])<=mid){
            dfs(i, j+1, mid, vis, heights);
        }
        if(j-1>=0 && !vis[i][j-1] && abs(heights[i][j]-heights[i][j-1])<=mid){
            dfs(i, j-1, mid, vis, heights);
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        int low = 0;
        int high = INT_MAX;
        while(low<high){
            int mid = low + ((high-low)/2);
            vector<vector<bool>> vis(heights.size(), vector<bool>(heights[0].size(),false));
            dfs(0, 0, mid, vis, heights);
            if(vis[n-1][m-1]){
                high = mid;
                
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
