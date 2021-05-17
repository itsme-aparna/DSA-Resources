#include <iostream>
using namespace std;

int main() {
	int T, N, x, k;
	cin>>T;
	for(int i=0; i<=T; i++){
	    cin>>N>>x>>k;
	    int y=0;
	    while(y<N+2){
	    
	    y=y+k;
	    if(y==x){
	        cout<<"Yes"<<endl;
	        break;
	    }
	        
	    }
	    
	    y=N+1;
	    while(y=0){
	        y=y-k;
	        if(y==N+1-k){
	            cout<<"Yes"<<endl;
                break;
	        }
	    }
	  cout<<"No"<<endl;  
	}
	
	return 0;
}
