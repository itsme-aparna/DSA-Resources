class Solution {
public:
    bool isRobotBounded(string instructions) {
        char curr = 'N';
        int x = 0;
        int y = 0;
        for(int i=0; i<instructions.length(); i++){
            if(instructions[i] == 'G'){
                y+= curr == 'N' ? 1 : 0;
                y+= curr == 'S' ? -1: 0;
                x+= curr == 'E' ? 1:0;
                x+= curr == 'W' ? -1: 0;
                
            }
            else {
                char incoming = instructions[i];
                if(curr == 'N'){
                    curr = incoming == 'L' ? 'W' : 'E';
                }
                else if(curr == 'W'){
                    curr = incoming == 'L' ? 'S' : 'N';
                }
                else if(curr == 'S'){
                    curr = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    curr = incoming == 'L' ? 'N' : 'S';
                }
            }
        }
        
        if(x==0 && y==0 || curr != 'N'){
            return true;
        }
        
        return false;
    }
};