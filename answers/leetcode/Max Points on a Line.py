# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """

        if len(points) < 3:
            return len(points)
        max_points = 0
        for i in range(len(points)):
            slope_map = {}
            same_points = 1
            for j in range(len(points)):
                slope = None
                if i == j:
                    continue
                elif points[i].x == points[j].x:
                    if points[i].y == points[j].y:
                        same_points += 1
                    else:
                        if sys.maxint not in slope_map:
                            slope = sys.maxint / 10
                else:
                    slope = float(points[i].y - points[j].y) / float(points[i].x - points[j].x)
                if None != slope:
                    if slope not in slope_map:
                        slope_map[slope] = 0
                    slope_map[slope] += 1
            #print "debug", slope_map, same_points
            max_points = max(max_points, (max(slope_map.values()) if len(slope_map) else 0) + same_points)
        return max_points
