class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int n = g.size();
        int ans = 0;
        int j = 0;
        if(s.size()==0){
            return 0;
        }
        for(int i=0; i<n; i++){
            if(j<s.size() && s[j]>=g[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};