class Solution {
public:
    
    int decode(string s, int idx, int len, vector<int> &dp){
        if(idx<len && s[idx]=='0')
            return 0;
        if(idx>=len)
            return 1;
        if(dp[idx]!=-1)
            return dp[idx];
        int ways = 0;
        
        //single pick
        if(s[idx]!='0')
            ways = decode(s, idx+1, len, dp);
        if(idx+1<len && ((s[idx]=='1' && s[idx+1]<='9')|| (s[idx]=='2' && s[idx+1] < '7')))
            ways+= decode(s, idx+2, len, dp);
        return dp[idx] = ways;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(102, -1);
        
        return decode(s, 0, n, dp);
    }
};