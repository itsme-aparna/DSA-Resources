class Solution {
public:
    bool isSafe(int row, int col, vector<string>& vec, int n){
        int r = row;
        int c = col;
        
        while(row>=0 && col>=0){
            if(vec[row][col] == 'Q'){
                return false;
            }
            row--, col--;
        }
        
        row = r;
        col = c;
        
        while(col >=0){
            if(vec[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        row = r;
        col = c;
        
        while(row<n && col >=0){
            if(vec[row][col] == 'Q'){
                return false;
            }
            col--;
            row++;
        }
        
        return true;
    }
    
    void solve(int n, vector<vector<string>>& ans, vector<string>& vec, int col){
        if(col == n){
            ans.push_back(vec);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, vec, n)){
                vec[row][col] = 'Q';
                solve(n, ans, vec, col+1);
                vec[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string st = "";
        for(int i=0; i<n; i++){
            st+= ".";
        }
        vector<string> vec;
        for(int i=0; i<n; i++){
            vec.push_back(st);
        }
        
        solve(n, ans, vec, 0);
        return ans;
    }
};