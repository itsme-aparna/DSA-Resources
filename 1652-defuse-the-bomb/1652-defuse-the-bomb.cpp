class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0){
            vector<int> vec(n, 0);
            return vec;
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            if(k<0){
                int total = 0;
                for(int j = -1; j>=k; j--){
                    int num = i+j;
                    if(num<0){
                        num += n;
                        
                    }
                    total += code[num];
                }
                ans[i] = total;
            }
            else{
                int total = 0;
                for(int j = 1; j<=k; j++){
                    int num = i+j;
                    num = num%n;
                    total += code[num];
                    
                }
                ans[i] = total;
            }
        }
        return ans;
    }
};