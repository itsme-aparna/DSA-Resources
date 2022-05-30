// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         long long n = dividend;
//         long long m = divisor;
//         int sign = n<0 ^ m<0 ? -1 : 1;
//         n = abs(n);
//         m = abs(m);
//         long long q = 0;
//         long long t = 0;
//         // Traverse from the highest bit 
//         for(long long i = 31; i>=0; i--){
//             if(t + (m<<i) <=n){
//                 t+= m<<i;
//                 q = q| (1<<i);
//             }
            
//         }
//         if(sign < 0){
//             q = -q;
//         }
        
//         if(q>=INT_MAX){
//             return INT_MAX;
//         }
//         if(q<= INT_MIN){
//             return INT_MIN;
//         }
//         return q;
//     }
// };

class Solution
{
    public:
    int divide(int dividend, int divisor) 
    {
        long long n=dividend, m=divisor;
        int sign= n<0 ^ m<0 ?-1:1;
        m=abs(m);
        n=abs(n);
        long long q=0;
        long long t=0;
        for(long long i=31; i>=0;i--){
            if(t+(m<<i)<=n){
                t+= (m<<i);
                q = q | (1LL << i);
            }
        }
        if(sign<0)q=-q;
        return q>=INT_MAX or q<INT_MIN ? INT_MAX:q;
        
    }
};