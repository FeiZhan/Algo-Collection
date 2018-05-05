class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """

        combinations = []
        mapping = {
            1: "",
            2: "abc",
            3: "def",
            4: "ghi",
            5: "jkl",
            6: "mno",
            7: "pqrs",
            8: "tuv",
            9: "wxyz",
            0: " "
        }
        if len(digits) == 1:
            for i in mapping[int(digits[0])]:
                combinations.append(i)
        elif len(digits) > 1:
            temp = self.letterCombinations(digits[1 :])
            for i in temp:
                for j in mapping[int(digits[0])]:
                    combinations.append(j + i)
        return combinations
