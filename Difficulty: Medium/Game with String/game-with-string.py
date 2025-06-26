class Solution:
    def minValue(self, s, k):
        #code here
        from collections import Counter
        import heapq
        freq = Counter(s)
        # Convert frequencies into a max-heap (using negative values)
        max_heap = [-f for f in freq.values()]
        heapq.heapify(max_heap)

        # Perform k reductions on the max frequency elements
        while k > 0 and max_heap:
            top = -heapq.heappop(max_heap)
            top -= 1
            k -= 1
            heapq.heappush(max_heap, -top)

        # Sum of squares of remaining frequencies
        return sum((-x) * (-x) for x in max_heap)