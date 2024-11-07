# Write your MySQL query statement below
SELECT DISTINCT(Logs.num) AS ConsecutiveNums
    FROM Logs
        JOIN Logs AS l1
            ON Logs.id + 1 = l1.id
        JOIN Logs AS l2
            ON Logs.id + 2 = l2.id
    WHERE Logs.num = l1.num AND Logs.num = l2.num
