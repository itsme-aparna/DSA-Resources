class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()){
            return t[0];
        }
        unordered_map<char, int> mp;
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }
        for(int i=0; i<s.size(); i++){
                mp[s[i]]--;
        }
        for(auto i:mp){
            if(i.second==1){
                return i.first;
            }
        }
        return 'a';
    }
};