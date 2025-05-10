# 250510
# DP
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = [[1]]
        for i in range(2, numRows+1):
            child = []
            for j in range(i):
                if j == 0 or j == i-1:
                    child.append(1)
                else:
                    child.append(ans[i-2][j-1]+ans[i-2][j])
            ans.append(child)
        return ans
        
