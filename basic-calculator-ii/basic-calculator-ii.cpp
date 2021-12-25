class Solution {
public:
    int calculate(string& s) {
        int cur = 0, ans = 0, interimRes = 0;
        char prevOp = '+';
        s += "##";                                     
        for(auto c : s)
            if(c == ' ') continue;
            else if(isdigit(c)) 
                cur = cur * 10 + (c-'0');
            else {
                if(prevOp == '*')                      
                    interimRes *= cur;
                else if(prevOp == '/')                 
                    interimRes /= cur;
                else                                   
                    ans += interimRes,
                    interimRes = prevOp == '+' ? cur : -cur;
                prevOp = c;
                cur = 0;
            }

        return ans;
    }
};