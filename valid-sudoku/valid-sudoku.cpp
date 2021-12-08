class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_check[9][9] = {0};
        int col_check[9][9] = {0};
        int squ_check[9][9] = {0};
        
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (board[i][j] != '.'){
                int num = board[i][j] - '1';
                
                if (row_check[i][num] == 0) row_check[i][num]=1;
                else return false;
                
                if (col_check[j][num] == 0) col_check[j][num]=1;
                else return false;                    

                int s = (i/3) + 3*(j/3);
                if (squ_check[s][num] == 0) squ_check[s][num]=1;
                else return false; 
            }
        }
    }

    return true;
    }
};