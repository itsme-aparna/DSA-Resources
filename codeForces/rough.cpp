#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, q;
    cin>>t>>q;
    int arr[t];
    for(int i=0; i<t; i++){
        cin>>arr[i];
    }
    for(int i=0; i<q; i++){
        int low, high;
        cin>>low>>high;
        int ans=0;
        for(int j=low; j<=high; j++){
            ans+=arr[j-1];
            
        }
        cout<<ans;
    }
return 0;
}