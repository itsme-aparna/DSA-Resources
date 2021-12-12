class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int i;
        int n=arr.size();
        int s=0;       
        for(i=0;i<n;i++)
        s+=arr[i];    
        
        if(s%2!=0)     
           return 0;     
           
           else
        {
            int sum = s/2;   
            int t[n+1][sum+1];
             int j;
        
         for(j=0;j<=sum;j++)    // fill 1st row with 0
        t[0][j]=0;
        
        for(i=0;i<=n;i++)    // fill 1st colun with 1
        t[i][0]=1;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=sum;j++)
            {
                
            if(arr[i-1]<=j)      // 2 choices are there - include or exclude
                 t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]] ;
            else       // if sum value is greater than element value
            t[i][j]=t[i-1][j];
         
            }
        }
        return t[n][sum];
        }
    }
};