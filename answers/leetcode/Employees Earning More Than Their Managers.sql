# Write your MySQL query statement below
SELECT t.Name
FROM Employee t
LEFT JOIN Employee t2
ON t.ManagerId = t2.Id
WHERE t.Salary > t2.Salary
