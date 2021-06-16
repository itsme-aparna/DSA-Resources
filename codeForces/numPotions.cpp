#include <bits/stdc++.h>
using namespace std;

int countUtil(int sum, int count, int arr[], int n){
    int sum_till_now;
    for(int i=0; i<n- count; i++){
         

    }
}

int count(int arr[], int n){
    int sum=0;
    int c = 0;
    for(int i=0; i <n; i++){
        if(sum+arr[i]>=0){
            countUtil(sum, c, arr, n);
        }
        else{
            continue;
        }
    }
    cout<<c;
    return sum;
}

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++){
        
        cin>>arr[i];

    }
    count(arr, t);
    return 0;
}