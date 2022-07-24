class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int curr = 0;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i])!= mp.end()){
                
                curr = 0;
                i= mp[s[i]];
                mp.clear();
            }
            else{
                mp[s[i]]=i;
                curr++;
            }
            ans = max(ans, curr);
        }
        
        return ans;
    }
};