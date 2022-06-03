class NumMatrix {
public:
    int m,n;
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        mat=matrix;
        int i=0,j;
        while(i<m)
        {
            j=1;
            while(j<n)
            {
                mat[i][j]+=mat[i][j-1]; 
                j++;
            }
            i++;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long sum=0,i=row1;
        while(i<=row2)
        {
            if(col2==0)sum+=mat[i][col1];
            else if(col1==0)
                sum+=mat[i][col2];
            else
            sum+=(mat[i][col2]-mat[i][col1-1]); 
            i++;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */