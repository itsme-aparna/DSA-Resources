class Solution {
public:
    int kIncreasing(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v{A[i]};
            int len = 1;
            for (int j = i + k; j < N; j += k) {
                auto i = upper_bound(begin(v), end(v), A[j]);
                if (i == end(v)) v.push_back(A[j]);
                else *i = A[j];
                ++len;
            }
            ans += len - v.size();
        }
        return ans;
    }
};