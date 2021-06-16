#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int i, int key){
      if(i==n){
          return -1;
      }
      if(arr[i]==key){
          cout<<i<<endl;
          return i;
      }
      firstOcc(arr, n, i+1, key);
}

int main(){
    int array[] = {1,2,3,2,4};
    firstOcc(array, 4, 0, 2);
    return 0;
}