class Solution:
    # brute force solution (pretty bad)
    def trap(self, height: list[int]) -> int:
        result: int = 0
        i: int = 0
        j: int = 0
        add: bool = True

        while i < len(height) - 1:
            add = True
            j = i + 1
            curr_result: int = 0
            while height[j] < height[i]:
                curr_result += height[i] - height[j]
                j += 1
                if j >= len(height):
                    add = False
                    break
            
            if add:
                result += curr_result
                i = j
            else:
                height[i] -= 1
        
        return result
