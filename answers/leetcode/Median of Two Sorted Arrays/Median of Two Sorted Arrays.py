class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        len_a = len(nums1)
        len_b = len(nums2)
        if (len_a + len_b) % 2:
            return self.getKth(nums1, nums2, (len_a + len_b) / 2 + 1)
        else:
            return (self.getKth(nums1, nums2, (len_a + len_b) / 2) + self.getKth(nums1, nums2, (len_a + len_b) / 2 + 1)) / 2.0
    def getKth(self, nums1, nums2, k):
        len_a = len(nums1)
        len_b = len(nums2)
        if len_a > len_b:
            return self.getKth(nums2, nums1, k)
        elif 0 == len_a:
            return nums2[k - 1]
        elif 1 == k:
            return min(nums1[0], nums2[0])
        middle_a = min(k / 2, len_a)
        middle_b = k - middle_a
        if nums1[middle_a - 1] <= nums2[middle_b - 1]:
            return self.getKth(nums1[middle_a :], nums2, middle_b)
        else:
            return self.getKth(nums1, nums2[middle_b :], middle_a)
