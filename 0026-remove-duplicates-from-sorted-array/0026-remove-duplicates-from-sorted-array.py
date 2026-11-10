class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        x = 1
        prev = nums[0]

        for i in range(1,n):
            if nums[i] == prev:
                continue
            else:
                nums[x] = nums[i]
                prev = nums[x]
                x += 1
        return x 




        