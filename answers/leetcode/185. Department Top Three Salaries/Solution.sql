# Write your MySQL query statement below
SELECT Department.name AS Department,
    Employee.name AS Employee,
    Employee.salary AS Salary
FROM Employee
    JOIN Department
        ON Employee.departmentId = Department.id
WHERE 3 > (
    SELECT COUNT(DISTINCT e2.Salary)
    FROM Employee AS e2
    WHERE e2.salary > Employee.salary
        AND e2.departmentId = Employee.departmentId
)
