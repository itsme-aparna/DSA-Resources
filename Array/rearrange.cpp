#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int D,d,P,Q;
	    cin>>D>>d>>P>>Q;
	    int n=1;
	    int sum = P;
	    for(int j=1; j<D; j++){
	        
	        if(j%d==0){
	            Q=n*Q;
	            n++;
                
	        }
	        sum = sum + P + Q;
	        cout<<sum<<endl;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
