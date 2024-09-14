# Write your MySQL query statement below
SELECT Users.name, SUM(amount) AS balance
    FROM Users
    JOIN Transactions ON Users.account = Transactions.account
    GROUP BY Users.account
    HAVING SUM(amount) > 10000