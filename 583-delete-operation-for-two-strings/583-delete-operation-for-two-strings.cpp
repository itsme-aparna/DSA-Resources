class Solution {
public:
    
    int lcs(string word1, string word2){
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> vec(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i==0 || j==0){
                    vec[i][j] = 0;
                    
                }
                else{
                    if(word1[i-1] == word2[j-1]){
                        vec[i][j] = 1 + vec[i-1][j-1];
                    }
                    else{
                        vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
                    }
                }
            }
        }
        return vec[n][m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        return n+m - 2*lcs(word1, word2);
    }
};