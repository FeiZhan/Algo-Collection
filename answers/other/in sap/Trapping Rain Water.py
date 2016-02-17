class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        left = []
        for i in range(len(height)):
            prev = left[i - 1] if i else 0
            left.append(max(prev, height[i]))
        right = 0
        water = 0
        for i in reversed(range(len(height))):
            right = max(right, height[i])
            water += max(0, min(left[i], right) - height[i])
        return water
