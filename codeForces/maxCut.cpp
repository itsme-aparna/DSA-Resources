#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int v[N];
        for(int i=0; i<N; i++){
            cin>>v[i];
        }
        
        unordered_map<int, int> map;
        for(int i=0; i<N; i++){
            if(map.find(v[i])==map.end()){
                map[v[i]]=1;
            }
            else{
            map[v[i]]++;
            }
        }
        int count =0;
        int x=1;
        for(auto i: map){
            count+=i.first*(map.size()-x);
            cout<<count<<endl;
            x++;
            }
        
    }
	return 0;
}
