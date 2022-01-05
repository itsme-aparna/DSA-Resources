// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull dp[n+1];
	    dp[1] = 1;
	    
	    ull p2 = 1;
	    ull p3 = 1;
	    ull p5 = 1;
	    
	    for(ull i=2; i<=n; i++){
	        ull f1 = 2*dp[p2];
	        ull f2 = 3*dp[p3];
	        ull f5 = 5*dp[p5];
	        
	        ull mini = min(f1, min(f2, f5));
	        dp[i] = mini;
	        
	        if(mini == f1)
	            p2++;
	        if(mini == f2)
	            p3++;
	        if(mini == f5)
	            p5++;
	           
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends