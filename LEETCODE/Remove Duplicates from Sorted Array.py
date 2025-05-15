class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = [0]*201
        
        for n in nums:
            n += 100
            if not ans[n]:
                ans[n] = 1

        idx = 0 
        for i in range(201):
            if ans[i]:
                nums[idx] = i-100
                idx += 1
        
        return sum(ans)
