class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.length()-1;
        for(int i=n;i>=0;i--){
            if(s[i]!= ' '){
                while(i>=0 && s[i]!=' '){
                        ans++;
                        i--;
                }
                return ans;
            }
        }
        return ans;
    }
};

