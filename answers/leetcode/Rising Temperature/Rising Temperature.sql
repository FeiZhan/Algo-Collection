# Write your MySQL query statement below
SELECT W2.Id FROM Weather W1, Weather W2
    WHERE W1.RecordDate + INTERVAL 1 DAY = W2.RecordDate AND W1.Temperature < W2.Temperature;