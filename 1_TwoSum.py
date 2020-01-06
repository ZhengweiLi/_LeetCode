class Solution(object):
    def twoSum(self, nums, target):
        i=0
        while i<len(nums):
            if i==len(nums)-1:
                return "No solutions"
            r=target-nums[i]
            nums_follow=nums[i+1:]
            if r in nums_follow:
                return [i,nums_follow.index(r)+i+1]
