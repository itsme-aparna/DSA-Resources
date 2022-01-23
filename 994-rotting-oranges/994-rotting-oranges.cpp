class Solution {
public:
    
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 || x>=n || y<0 || y>=m){
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int x = q.front().first;
                int y = q.front().second;
            
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if((isValid(x+dx[i], y+dy[i], grid)) && grid[nx][ny]==1){
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            
            if(!q.empty()){
                ans++;
            }
        }
        if(fresh == 0)
            return ans;
        return -1;
    }
};