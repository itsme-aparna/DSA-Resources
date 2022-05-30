class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s= to_string(num);
        int cnt=0;
        for(int i=0;i<=s.size()-k;i++){
            int tmp=stoi(s.substr(i,k));
            if(tmp!=0 and num%tmp==0) cnt++;
        }
        return cnt;
    }
};