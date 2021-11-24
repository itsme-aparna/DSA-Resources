class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int> vec(26,0), vec2(26,0);
        for(int i=0; i<s1.size(); i++){
            vec[s1[i]-'a']++;
            vec2[s2[i]- 'a']++;
        }
        int j=0;
        if(vec==vec2){
            return true;
        }
        while(j<s2.length()-s1.length()){
            vec2[s2[j]-'a']--;
            vec2[s2[j+s1.size()]-'a']++;
            if(vec==vec2){
                return true;
            }
            j++;
        }
        return false;
    }
};