class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;
        
        for(int i=1; i<n; i++){
            int val2 = dp[ptr2]*2;
            int val3 = dp[ptr3]*3;
            int val5 = dp[ptr5]*5;
            
            int mini = min(val2, min(val3, val5));
            dp[i] = mini;
            if(mini == val2){
                ptr2++;
            }
            if(mini==val3)
                ptr3++;
            if(mini==val5)
                ptr5++;
            
             
        }
        return dp[n-1];
    }
};