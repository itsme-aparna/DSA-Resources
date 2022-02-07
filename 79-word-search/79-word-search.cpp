class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        int n = board.size();
        int m = board[0].size();
        if(x<0 || x>n-1 || y<0 || y>m-1){
            return false;
        }
        return true;
    }
    
    bool recur(vector<vector<char>>& board, string word, int x, int y, int idx, vector<vector<bool>> &vis){
        if(idx>=word.size()){
            return true;
        }
        
        if(isValid(board, x, y) && board[x][y]==word[idx] && !vis[x][y]){
            vis[x][y] = true;
            bool ret = recur(board, word, x+1, y, idx+1, vis) || recur(board, word, x-1, y, idx+1, vis) || recur(board, word, x, y+1, idx+1, vis) || recur(board, word, x, y-1, idx+1, vis);
            vis[x][y] = false;
            return ret;
            
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && recur(board, word, i, j, 0, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};