# Write your MySQL query statement below
SELECT stock_name,
    SUM(price * IF(operation = 'Sell', 1, -1)) AS capital_gain_loss
    FROM Stocks
    GROUP BY stock_name
