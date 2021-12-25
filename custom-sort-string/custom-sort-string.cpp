class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        string ans = "";
        for(auto c: order){
            if(mp.find(c)!=mp.end()){
                while(mp[c]){
                    mp[c]--;
                    ans+= c;
                }
            }
        }
        for(auto it: mp){
            if(it.second!=0){
                while(it.second){
                    ans+= it.first;
                    it.second--;
                }
            }
        }
        return ans;
    }
};