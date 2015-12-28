class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        carry = 1
        for i in reversed(range(len(digits))):
            carry += digits[i]
            digits[i] = carry % 10
            carry /= 10
        while carry:
            digits.insert(0, carry % 10)
            carry /= 10
        return digits
