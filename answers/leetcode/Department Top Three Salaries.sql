# Write your MySQL query statement below
SELECT d.Name AS Department, cte.Name AS Employee, cte.Salary
FROM (
	SELECT t.*, if(t.DepartmentId = @pred, if (t.Salary = @pres, @rank, @rank := @rank + 1), @rank := 1) AS rank, @pred := t.DepartmentId, @pres := t.Salary
	FROM Employee t, (SELECT @rank := 0, @pred := 0, @pres := 0) r
	ORDER BY DepartmentId, Salary DESC
) cte
INNER JOIN Department d
ON d.Id = cte.DepartmentId
WHERE cte.rank <= 3
ORDER BY d.Id, cte.Salary DESC
