class Solution {
public:
    bool isPalindrome(string st, int i, int j){
        while(i<j){
            if(st[i]!= st[j]){
                return false;
            }
            else{
                
            
            i++;
            j--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i=0, j = s.size()-1; i<j; i++, j--){
            if(s[i]!= s[j]){
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};