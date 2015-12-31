class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """

        version1 = version1.split(".")
        version2 = version2.split(".")
        length1 = len(version1)
        length2 = len(version2)
        for i in range(max(length1, length2)):
            num1 = None
            if i < length1:
                num1 = int(version1[i])
            num2 = None
            if i < len(version2):
                num2 = int(version2[i])
            if (i < length1 and i < length2 and num1 > num2) or (i >= length2 and num1 > 0):
                return 1
            elif (i < length1 and i < length2 and num1 < num2) or (i >= length1 and num2 > 0):
                return -1
        return 0
