class Solution {
public:
    
    bool helper(const string& str, int sIndex, const string& pattern, int pIndex, vector<vector<int>> &dp){
        
        const int sLen = str.length();
        const int pLen = pattern.length();
        
        if(pIndex >= pLen){
            if(sIndex >= sLen){
                return dp[sIndex][pIndex] = true;
            }else{
                return dp[sIndex][pIndex] = false;
            }
        }
        
        if(sIndex >= sLen){
            while(pIndex < pLen && (pattern[pIndex]=='*')){
                pIndex++;
            }
            if(pIndex == pLen){
                return dp[sIndex][pIndex] = true;
            }
            return dp[sIndex][pIndex] = false;
        }
        
        if(dp[sIndex][pIndex] != -1){ // return computed value
            return dp[sIndex][pIndex];
        }
        
        char currS = str[sIndex];
        char currP = pattern[pIndex];
        
        if(currS == currP || currP == '?'){
            return helper(str, sIndex+1, pattern, pIndex+1, dp);
        }
        
        bool res = false;
        
        if(currP == '*'){
            res = helper(str, sIndex+1, pattern, pIndex, dp);
            if(res){
                return dp[sIndex][pIndex] = true;
            }
            res = helper(str, sIndex, pattern, pIndex+1, dp);
        }
        
        return dp[sIndex][pIndex] = res;
    }
    
    bool isMatch(string s, string p) {
        const int sLen = s.length();
        const int pLen = p.length();
        
        vector<vector<int>> dp(sLen+1, vector<int>(pLen+1, -1));
        return helper(s, 0, p, 0, dp);
    }
};