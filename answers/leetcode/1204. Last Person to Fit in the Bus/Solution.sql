# Write your MySQL query statement below
SELECT Queue.person_name
    FROM Queue
        JOIN Queue AS Previous
        ON Queue.turn >= Previous.turn
    GROUP BY Queue.person_id
    HAVING SUM(Previous.weight) <= 1000
    ORDER BY Queue.turn DESC
    LIMIT 1;
