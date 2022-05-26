class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    
    int solve(int i, int j, string& s, vector<int>& memo){
        if(i==j)
            return 0;
        if(memo[i]!= -1)
            return memo[i];
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            if(isPalindrome(i, k, s)){
                int cost = 1 + solve(k+1, j, s, memo);
                mini = min(mini, cost);
            }
                
        }
        
        return memo[i] = mini;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> memo(n, -1);
        return solve(0, n, s, memo)-1;
    }
};