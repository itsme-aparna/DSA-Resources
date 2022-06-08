class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0;
        int j = 0;
        int n = word1.length();
        int m = word2.length();
        string merge = "";
        while(i<word1.length() && j<word2.length()){
            if(word1[i]>word2[j]){
                merge += word1[i];
                i++;
            }
            else if(word1[i]==word2[j]){
                if(word1.substr(i, n-i) > word2.substr(j, m-j)){
                    merge += word1[i];
                    i++;
                }
                else{
                    merge += word2[j];
                    j++;
                }
            }
            else{
                merge += word2[j];
                j++;
            }
        }
        while(i<word1.length()){
            merge += word1[i];
            i++;
        }
        while(j<word2.length()){
            merge += word2[j];
            j++;
        }
        return merge;
    }
};