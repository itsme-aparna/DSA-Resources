class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int res = -1;
        vector<int> inO (n+1, 0);
        vector<int> outO (n+1, 0);
        
        for(auto x: trust){
            inO[x[1]]++;
            outO[x[0]]++;
        }
        for(int i=1; i<=n; i++){
            if(inO[i]==n-1 && outO[i]==0){
                res = i;
            }
        }
        return res;
    }
};