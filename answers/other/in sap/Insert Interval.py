# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
        i = 0
        flag = False
        while i < len(intervals):
            if intervals[i].start >= newInterval.start:
                intervals.insert(i, newInterval)
                flag = True
                break
            i += 1
        if False == flag:
            intervals.append(newInterval)
        i = max(1, i)
        while i < len(intervals):
            if intervals[i - 1].end >= intervals[i].start:
                intervals[i - 1].end = max(intervals[i - 1].end, intervals[i].end)
                del intervals[i]
            else:
                i += 1
        return intervals