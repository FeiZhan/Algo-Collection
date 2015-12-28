class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """

        sum = [0 for i in range(max(len(a), len(b)))]
        for i in range(1, max(len(a), len(b)) + 1):
            if i <= len(a):
                sum[- i] += int(a[- i])
            if i <= len(b):
                sum[- i] += int(b[- i])
        carry = 0
        for i in reversed(range(len(sum))):
            carry += sum[i]
            sum[i] = carry % 2
            carry /= 2
        while carry:
            sum.insert(0, carry % 2)
            carry /= 2
        return "".join([str(i) for i in sum])
