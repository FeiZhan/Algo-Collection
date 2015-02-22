# Write your MySQL query statement below
select Scores.score, count(Ranking.Score) as rank
from Scores,
(select distinct score from Scores) Ranking 
where Scores.score <= Ranking.Score 
group by Scores.id, Scores.score 
order by Scores.score desc;
