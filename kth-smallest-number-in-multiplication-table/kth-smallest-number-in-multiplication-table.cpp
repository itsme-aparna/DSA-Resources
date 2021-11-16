class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int hi =m*n , lo =0 ,count=0;
        while(lo<hi){
            int mid = (lo+hi)/2;
            count=0;
            for(int i=1;i<=m;i++){
                count += min(mid/i,n);
            }
            if(count>=k)
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};