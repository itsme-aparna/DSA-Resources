class Solution {
public:
    
    void solve(vector<vector<string>>& ans, vector<string>& temp, string s, int idx){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(ans, temp, s, i+1);
                temp.pop_back();
            }
            
        }
    }
    
    bool isPalindrome(string s, int idx, int end){
        while(idx<end){
            if(s[idx++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, temp, s, 0);
        return ans;
    }
};