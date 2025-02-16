class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        numbers_present = set()
        for i in nums:
            if i in numbers_present:
                return True
            numbers_present.add(i)
        return False
