class Solution:
    def splitArray(self, arr, k):
        def can_split(mid):
            current_sum = 0
            count = 1  # At least one subarray
            for num in arr:
                current_sum += num
                if current_sum > mid:
                    count += 1
                    current_sum = num
                    if count > k:
                        return False
            return True

        low, high = max(arr), sum(arr)

        while low < high:
            mid = (low + high) // 2
            if can_split(mid):
                high = mid
            else:
                low = mid + 1

        return low