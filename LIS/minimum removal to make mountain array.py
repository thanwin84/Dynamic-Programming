class Solution:
    def nextGreaterIndex(self, nums, target):
        low = 0
        high = len(nums) - 1
        ind = 0
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] >= target:
                ind = mid
                high = mid - 1
            else:
                low = mid + 1
        return ind
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        v1 = [nums[0]]
        lisFromForward = [1 for i in range(n)]

        for ind in range(1, n):
            if nums[ind] > v1[-1]:
                v1.append(nums[ind])
            else:
                newIndex = self.nextGreaterIndex(v1, nums[ind])
                v1[newIndex] = nums[ind]
            lisFromForward[ind] = len(v1)
        
        v2 = [nums[-1]]
        maxMountain = 0
        for ind in range(n - 2, -1, - 1):
            if nums[ind] > v2[-1]:
                v2.append(nums[ind])
            else:
                newIndex = self.nextGreaterIndex(v2, nums[ind])
                v2[newIndex] = nums[ind]
            if lisFromForward[ind] > 1 and len(v2) > 1:
                maxMountain = max(maxMountain, lisFromForward[ind] + len(v2) - 1)

        return n - maxMountain



