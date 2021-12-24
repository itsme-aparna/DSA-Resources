class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int globallen = 0;
        int len = 0;
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                len++;
            }
            else{
                globallen = max(globallen, len);
                len = 0;
                i= mp[s[i]];
                mp.clear();
            }
            globallen = max(globallen, len);
        }
        return globallen;
    }
};