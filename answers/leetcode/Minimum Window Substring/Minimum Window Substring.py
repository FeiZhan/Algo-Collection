class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """

        count0 = {}
        count1 = {}
        for i in t:
            if i not in count0:
                count0[i] = 1
                count1[i] = 1
            else:
                count0[i] += 1
                count1[i] += 1
        count = len(t)
        begin = 0
        min_window = sys.maxint
        min_begin = 0
        for i in range(len(s)):
            if s[i] in count1 and count1[s[i]] > 0:
                count0[s[i]] -= 1
                if count0[s[i]] >= 0:
                    count -= 1
            if 0 == count:
                while True:
                    if s[begin] in count1 and count1[s[begin]] > 0:
                        if count0[s[begin]] < 0:
                            count0[s[begin]] += 1
                        else:
                            break
                    begin += 1
                if min_window > i - begin + 1:
                    min_window = i - begin + 1
                    min_begin = begin
        return s[min_begin : min_begin + min_window] if min_window < sys.maxint else ""
