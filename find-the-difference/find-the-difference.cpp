class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = t.size();
        int n = 0;
        for(int i=0; i<s.size(); i++){
            n = n^((s[i]-'a')^(t[i]-'a'));
        }
        n=n^(t[x-1]-'a');
        return (char)n+'a';
    }
};