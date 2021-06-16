#include <bits/stdc++.h>
using namespace std;

long long int generate(int no){
    long long int num = 11;
    for(long long int i=2; i<=no; i++){
        num+=(long long int)(pow(10,i));
    }
    return num;
}

long long int check(long long int x){
    while(x>0){
            if(x<11 && x>0){
                return 0;
            }
            
            long long int n = to_string(x).length();
            long long int gen = generate(n);
            
            if(x==gen || x==0){ 
               return 1;
                }
                
            if(x>gen){
                x=x-gen;
                cout<<x<<endl;
            }
            else{
                x=x-gen/10;
                cout<<x<<endl;
            }          
        }
        
}

int main(){
    long long int t;
    cin>>t;
    for(long long int i=0; i<t; i++){
        long long int x;
        cin>>x;
        if(check(x)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}