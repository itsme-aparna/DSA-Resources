class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 || x>=n || y<0 || y>= m || grid[x][y]==0){
            return false;
        }
        return true;
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                
                if(isValid(x+1, y, grid) && grid[x+1][y]==1){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                }
                if(isValid(x-1, y, grid) && grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                }
                if(isValid(x, y+1, grid) && grid[x][y+1]==1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                }
                if(isValid(x, y-1, grid) && grid[x][y-1]==1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                }
            }
            if(!q.empty())
                time++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};