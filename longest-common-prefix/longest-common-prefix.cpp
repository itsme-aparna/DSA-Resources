class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        string res = "";
        int i=0;
        int index = 0;
        while(i<strs.size()-1){
            if(!strs[i][index] || !strs[i+1][index]){
                break;
            }
            
            if(strs[i][index]!=strs[i+1][index]){
                break;
            }
            
            if(i+1==strs.size()-1){
                res+=strs[i+1][index];
                i=0;
                index++;
                continue;
            }
            i++;
        }
        return res;
    }
};