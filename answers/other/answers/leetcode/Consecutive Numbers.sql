# Write your MySQL query statement below
SELECT DISTINCT Num
FROM (
	SELECT Num, IF(Num = @last, @row := @row + 1, @row := 1) as times, @last := Num
	FROM Logs, (SELECT @last := 'x', @row := 0) r
) t
WHERE times >= 3
