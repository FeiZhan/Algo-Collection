# Write your MySQL query statement below
SELECT Scores.score, COUNT(DISTINCT Higher.score) AS "rank"
    FROM Scores
        JOIN Scores AS Higher
        ON Scores.score <= Higher.score
    GROUP BY Scores.id
    ORDER BY Scores.score DESC;
