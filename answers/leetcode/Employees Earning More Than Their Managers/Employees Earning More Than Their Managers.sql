# Write your MySQL query statement below
SELECT Employee.Name AS Employee
    FROM Employee, Employee AS Manager
    WHERE Employee.ManagerId = Manager.Id AND Employee.Salary > Manager.Salary;