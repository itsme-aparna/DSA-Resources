class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // use stack to store the positive/negative elements and when the opposite ones arrive, pop the smaller one 
        vector<int> vec;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i]>0 || vec.empty() || vec.back() < 0){
                vec.push_back(asteroids[i]);
            }
            else if(vec.back() <= -asteroids[i]){
                if(vec.back() < -asteroids[i])
                    i--;
                vec.pop_back();
            }
        }
        return vec;
    }
};