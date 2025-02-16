class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:

        m = dict()

        for i in range(len(nums)):

            if nums[i] in m.keys():
                return [m[nums[i]], i]

            else:
                m[target - nums[i]] = i


        return []
