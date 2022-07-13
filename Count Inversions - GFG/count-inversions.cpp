// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int cnt;
void merge(long long arr[], long long int s, long long int mid, long long int e){
    long long int i = s;
    long long int j = mid+1;
    while(i<= mid && j<=e){
        if(arr[i]>arr[j]){
            cnt+= mid-i+1;
            j++;
        }
        else
        i++;
    }
    sort(arr+s, arr+e+1);
}

void mergeSort(long long arr[], long long int s, long long int e){
    if(s>=e)
    return;
    long long int mid = s + ((e-s)>>1);
    
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, mid, e);
}


long long int inversionCount(long long arr[], long long N)
{
    cnt = 0;
    mergeSort(arr, 0, N-1);
    return cnt;
}

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends