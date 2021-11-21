class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> clone = strs;
        vector<vector<string>>ans;
        unordered_map<string, vector<string>> map;
        for(int i=0; i<n; i++){
            
            sort(clone[i].begin(), clone[i].end());
            
        }
        for(int i=0; i<n; i++){
            map[clone[i]].push_back(strs[i]);
        }
        for(auto it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};