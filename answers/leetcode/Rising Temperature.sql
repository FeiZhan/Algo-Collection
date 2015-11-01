# 14 / 14 test cases passed. Status: Accepted Runtime: 1016 ms Submitted: 0 minutes ago You are here! Your runtime beats 97.52% of mysql submissions.

# Write your MySQL query statement below
SELECT w1.Id FROM Weather w1 INNER JOIN Weather w2 
ON TO_DAYS(w1.Date) = TO_DAYS(w2.Date) + 1 AND w1.Temperature > w2.Temperature;