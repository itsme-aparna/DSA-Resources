class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        for(auto i: boxTypes){
            int x = min(i[0], truckSize);
            ans+= x*i[1];
            truckSize -= x;
            if(!truckSize)
                break;
        }
        return ans;
    }
};