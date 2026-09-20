class Solution:
    def helper(self,i,j,nums):
        if i==j:
            return str(nums[i])
        else:
            return str(nums[i]) + "->" + str(nums[j])

    def summaryRanges(self, nums: list[int]) -> list[str]:
        
        nums.append(98764)
        n = len(nums)
        result = []

        i=0
        j=0

        while(j<n-1):
            if nums[j]+1 == nums[j+1]:
                j+=1
            else:
                result.append(self.helper(i,j,nums))
                j+=1
                i=j
        return result



        