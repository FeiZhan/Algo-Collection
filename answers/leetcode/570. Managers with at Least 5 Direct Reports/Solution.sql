# Write your MySQL query statement below
SELECT name
    FROM Employee
    JOIN (
        SELECT managerId
            FROM Employee
            WHERE managerId IS NOT NULL
            GROUP BY managerId
            HAVING COUNT(id) >= 5
    ) AS managers
        ON Employee.id = managers.managerId
