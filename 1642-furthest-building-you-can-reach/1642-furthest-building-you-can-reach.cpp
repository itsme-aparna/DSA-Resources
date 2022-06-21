class Solution {
public:
    int furthestBuilding(vector<int>& H, int bricks, int ladders) {
	priority_queue<int> pq;
	int n = size(H), i = 0, jump = 0;
	for(; i < n - 1; i++) {
		jump = H[i + 1] - H[i];
		if(jump <= 0) continue;
		pq.push(-jump); 
		if(size(pq) > ladders) 
			bricks += pq.top(), pq.pop();
		if(bricks < 0) return i;
	}
	return i;
}
};