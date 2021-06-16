#include <iostream>
using namespace std;

void printInc(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    printInc(n-1);
    cout<<n<<endl;
}

int main(){
    printInc(5);
    return 0;
}