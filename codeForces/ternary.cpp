#include <bits/stdc++.h>
using namespace std;

bool isValid(string x, int mid){
    int ar[4] = {0};
    for(int i=0; i<mid; i++){
        int idx = x[i] - '0';
        ar[idx]++;
    }

    for(int i=mid-1; i<x.length(); i++){
        int idx = x[i] - '0';
        ar[idx]++;

        if(ar[1]>0 && ar[2]>0 && ar[3]>0){
            return true;
        }

        ar[x[i-mid+1] - '0']--;
    }
    return false;
}


int giveLength(string x){
    int res = 0;
    int l = 3;
    int h = x.length();
    while(l<h){

        int mid = l+h/2;
        if(isValid(x, mid)){
            res = min(res, mid);
            h = mid-1;

        }
        else{
            l = mid+1;
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        string st;
        cin>>st;
        cout<<giveLength(st)<<endl;
    }
    return 0;
}