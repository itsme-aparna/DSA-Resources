class Solution {
    public int nthUglyNumber(int n) {
  PriorityQueue<Long> pq = new PriorityQueue<>();
  pq.add(1l);
  for (int i = 0; i < n - 1; ++i) {
    long val = pq.remove();
    while (pq.size() > 0 && pq.peek() == val) pq.remove(); // remove duplicates
    pq.add(val * 2);
    pq.add(val * 3);
    pq.add(val * 5);
  }
  // return (int) pq.remove();   // 
  return pq.remove().intValue();
}
}