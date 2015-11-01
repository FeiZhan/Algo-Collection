# 9 / 9 test cases passed. Status: Accepted Runtime: 291 ms Submitted: 1 minute ago You are here! Your runtime beats 7.34% of mysql submissions.

# Write your MySQL query statement below
SELECT Request_at DAY,
       ROUND(SUM(IF(Status = 'completed', 0, 1)) / COUNT(*), 2) 'Cancellation Rate'
FROM   Trips t
LEFT   JOIN Users t1 ON t.Client_Id = t1.Users_Id
WHERE  t1.Banned = 'No' AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP  BY t.Request_at;