class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else if(str1[i-1]==str2[j-1]){            //DP for finding LCS
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s="";
        int i=m;
        int j=n;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){         // if equal add to ans string (s) 
                s=s+str1[i-1];
                i--;
                j--;
            }
            //Not equal check from which side of dp matrix we can get the LCS
            else if(dp[i-1][j]>=dp[i][j-1]){   
                s=s+str1[i-1];
                i--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                s=s+str2[j-1];
                j--;
            }
        }
        // now check is i ans j both equal to zero if not then make it to zero
        // and add strings in ans string (s)
        while(i>0){
            s=s+str1[i-1];
            i--;
        }
        while(j>0){
            s=s+str2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};