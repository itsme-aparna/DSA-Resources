class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        if(time.size()==1){
            return (long long)time[0]*totalTrips;
        }
        
        sort(time.begin(), time.end());
        long long maxi = time[time.size()-1];
        long long minDays = 0;
        long long maxDays = 1e14;
        long long result = 0;
        
        while(minDays<maxDays){
            long mid = (minDays + maxDays) / 2;
            long u = 0;
            for (long m : time) {
                u += mid / m;
            }
            if (u < totalTrips) {
                minDays = mid+1;
            } else {
                result = mid;
                maxDays = mid;
            }
        }
        return result;
    }
};


