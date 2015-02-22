# Write your MySQL query statement below
select d.Name Department, e1.Name Employee, e1.Salary
from Employee e1, Department d,
(select max(Salary) Salary, DepartmentId from Employee group by DepartmentId) e2
where e1.Salary = e2.Salary 
and e1.DepartmentId = e2.DepartmentId
and d.Id = e2.DepartmentId;
