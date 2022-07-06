class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxF=0;
        int freq[26] = {0};
        int start = 0;
        int end = 0;
        for(end = 0;  end<s.size(); end++){
            maxF = max(maxF, ++freq[s[end]-'A']);
            int len = end-start+1;
            if(len-maxF > k)
                freq[s[start++] - 'A']--;
            
        }
        return s.size()-start;
    }
};