class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        
        num1 = num1[: : -1]
        num2 = num2[: : -1]
        multi = [0 for i in range(len(num1) + len(num2))]
        for i in range(len(num1)):
            for j in range(len(num2)):
                multi[i + j] += int(num1[i]) * int(num2[j])
        carry = 0
        for i in range(len(multi)):
            carry += multi[i]
            multi[i] = str(carry % 10)
            carry /= 10
        while carry:
            multi.append(carry % 10)
            carry /= 10
        while len(multi) > 1 and '0' == multi[-1]:
            del multi[-1]
        return "".join(multi)[: : -1]