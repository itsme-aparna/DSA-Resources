class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "C"){
                ans.pop_back();
            }
            
            else if(ops[i] == "D"){
                
                int x = ans[ans.size()-1];
                ans.push_back(2*x);
            }
            
            else if(ops[i]== "+"){
                int x = ans[ans.size()-1]+ans[ans.size()-2];
                ans.push_back(x);
            }
            
            else{
                int x = stoi(ops[i]);
                ans.push_back(x);
            }
            
            
        }
        
        int a = 0;
        for(int i=0; i<ans.size(); i++){
            a+= ans[i];
        }
        return a;
    }
};