class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &memo){
        
        if(x==0 && y==0){
            return grid[x][y];
        }
        
        else if(x<0 || y<0)
            return INT_MAX;
        
        else if(memo[x][y]!=0){
            return memo[x][y];
        }
        
        int r = grid[x][y] + min(minPathSum(grid, x-1, y, memo), minPathSum(grid, x, y-1, memo));
        memo[x][y] = r;
        return r;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        //try all paths
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int> (m,0));
        return minPathSum(grid, n-1, m-1, memo);
    }
};
