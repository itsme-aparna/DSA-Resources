class Solution {
public:
    void lpsFill(string word, vector<int>& lps){
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while(i<word.size()){
            if(word[i] == word[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
            
        }
    }
    
    int solve(string sequence, string word){
        vector<int> lps(word.size(), 0);
        lpsFill(word, lps);
        int i=0, j=0;
        while(i<sequence.size() && j<word.size()){
            if(sequence[i] == word[j]){
                i++;
                j++;
            }
            else if(i<sequence.size() && sequence[i] != word[j]){
                if(j!= 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        if(j == word.size()){
            return 1;
        }
        return 0;
    }
    
    int maxRepeating(string sequence, string word) {
        int res = 0;
        string pattern = word;
        while(true){
            int x = solve(sequence, pattern);
            res+= x;
            pattern += word;
            if(x==0){
                break;
            }
        }
        return res;
    }
    
    
};