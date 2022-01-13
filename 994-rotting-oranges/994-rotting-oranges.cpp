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
        int fresh=0;
        int rotten = 0;
        int day=0;
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j] == 2){ 
                    rotten++;
                    q.push({i, j});
                }
                
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                if(isValid(x+dx[i], y+dy[i], grid)){
                    if(grid[x+dx[i]][y+dy[i]]==1){
                        fresh--;
                        grid[x+dx[i]][y+dy[i]]=2;
                        q.push({x+dx[i], y+dy[i]});
                    }
                }
            }
            }
            if(!q.empty())
             day++;
        }
        if(fresh==0)
            return day;
        return -1;
    }
};