class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        convert = {
            1000: "M",
            900: "CM",
            500: "D",
            400: "CD",
            100: "C",
            90: "XC",
            50: "L",
            40: "XL",
            10: "X",
            9: "IX",
            5: "V",
            4: "IV",
            1: "I",
        }
        roman = ""
        for i in sorted(convert.keys(), reverse=True):
            while num >= i:
                roman += convert[i]
                num -= i
        return roman
