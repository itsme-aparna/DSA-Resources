class Solution {
public:
    string findS(int n){
        if(n==1){
            return "0";
        }
        
        string s = findS(n-1);
        string s1 = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0'){
                s1 += '1';
            }
            else{
                s1 += '0';
            }
        }
        reverse(s1.begin(), s1.end());
        
        return s + "1" + s1;
    }
    
    char findKthBit(int n, int k) {
        string st = findS(n);
        return st[k-1];
    }
};