class StockSpanner {
public:
    vector<int> stock;
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        // stock.push_back(price);
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        int cnt = 1;
        while(!st.empty() && st.top().first <= price){
            auto i = st.top();
            
            cnt += i.second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */