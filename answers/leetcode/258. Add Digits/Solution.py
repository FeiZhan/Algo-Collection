class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            temp = 0
            while num > 0:
                temp += num % 10
                num //= 10
            num = temp
        return num
