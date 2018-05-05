class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """

        dp = [0 for i in s]
        if len(dp):
            dp[0] = int('0' != s[0])
        for i in range(1, len(s)):
            num = int(s[i - 1 : i + 1])
            if num > 10 and num <= 26 and num != 20:
                dp[i] = dp[i - 1] + (dp[i - 2] if i >= 2 else 1)
            elif 10 == num or 20 == num:
                dp[i] = dp[i - 2] if i >= 2 else 1
            elif '0' != s[i]:
                dp[i] = dp[i - 1]
            else:
                dp[i] = 0
        return dp[-1] if len(dp) else 0
