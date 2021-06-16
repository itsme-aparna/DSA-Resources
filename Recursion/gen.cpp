#include <bits/stdc++.h>
using namespace std;

int generate(int no){
    int num = 11;
    for(int i=2; i<no; i++){
        num+=(int)(pow(10,i));
    }
    return num;
}

int main(){
    cout<<generate(3)/10;
    return 0;
}