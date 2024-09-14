# Write your MySQL query statement below
SELECT id + IF(id MOD 2 = 0, -1, IF(id = (SELECT COUNT(*) FROM Seat), 0, 1)) AS id,
    student
    FROM Seat
    ORDER BY id;
