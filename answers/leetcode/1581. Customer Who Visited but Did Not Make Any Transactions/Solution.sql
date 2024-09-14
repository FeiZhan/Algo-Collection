# Write your MySQL query statement below
SELECT Visits.customer_id, COUNT(*) AS count_no_trans
    FROM Visits
    LEFT JOIN Transactions ON Visits.visit_id = Transactions.visit_id
    WHERE Transactions.visit_id IS NULL
    GROUP BY Visits.customer_id