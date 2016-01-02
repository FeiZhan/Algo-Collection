# 21 / 21 test cases passed. Status: Accepted Runtime: 1318 ms Submitted: 0 minutes ago You are here! Your runtime beats 5.67% of mysql submissions.

# Write your MySQL query statement below
DELETE p1 FROM Person p1 INNER JOIN Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id;