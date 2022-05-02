class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        int map1[256] = {0};
        int map2[256] = {0};
        int n = s.length();
        for(int i=0; i<n; i++){
            if(map1[s[i]]!= map2[t[i]]){
                return false;
            }
            
            map1[s[i]] = map2[t[i]] = i+1;
        }
        return true;
    }
};