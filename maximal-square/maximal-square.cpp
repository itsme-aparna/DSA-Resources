class Solution {
public:
    int getMaxSquareLen(vector<vector<char>>& M, vector<vector<int>>& ones, int row, int col) {
        int allOnesRowLen = min(size(M)-row, size(M[0])-col), sqLen = 0;
        for(int i = 0, j; i < allOnesRowLen; i++) 
            allOnesRowLen = min(allOnesRowLen, ones[i+row][col]),
            sqLen = min(allOnesRowLen, i+1);
        return sqLen;
    }
    int maximalSquare(vector<vector<char>>& M) {
        int m = size(M), n = size(M[0]), ans = 0;
        vector<vector<int>> ones(m, vector<int>(n+1));
        for(int i = m-1; ~i; i--)
            for(int j = n-1; ~j; j--)
                ones[i][j] = (M[i][j] == '1' ? 1 + ones[i][j+1] : 0);
        
        for(int row = 0; row < m; row++)
            for(int col = 0; col < n; col++) 
                ans = max(ans, getMaxSquareLen(M, ones, row, col));
        return ans * ans;
    }
};