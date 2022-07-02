class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        long maxh = hc[0] - 0;
        for(int i=1; i<hc.size(); i++){
            maxh = max(maxh, (long)(hc[i] - hc[i-1]));
        }
        int n = hc.size();
        int m = vc.size();
        
        
        maxh = max(maxh, (long)(h - hc[n-1]));
        long maxv = vc[0] - 0;
        maxv = max(maxv, (long)(w - vc[m-1]));
        for(int i=1; i<vc.size(); i++){
            maxv = max(maxv, (long)(vc[i] - vc[i-1]));
        }
        cout<<maxv<< " "<< maxh;
        int ans = (long)(maxv*maxh) % 1000000007;
        return ans;
    }
};