class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto i: strs){
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        vector<vector<string>> anagrams;
        for(auto it:mp){
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
};