class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dp = [False] * len(nums)
        dp[0] = True
        
        for idx in range(len(nums)):
            if len(nums) - 1 == idx:
                return dp[idx]
            if dp[idx] == False:
                return False
            for i in range(1, nums[idx]+1):
                if idx + i >= len(nums) - 1:
                    return True
                dp[idx+i] = True
