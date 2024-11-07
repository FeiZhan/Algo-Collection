# Write your MySQL query statement below
(SELECT Users.name AS results
    FROM Users
        JOIN MovieRating
            ON Users.user_id = MovieRating.user_id
    GROUP BY MovieRating.user_id
    ORDER BY COUNT(MovieRating.user_id) DESC,
        Users.name
    LIMIT 1)
UNION ALL
    (SELECT Movies.title AS results
        FROM Movies
            JOIN MovieRating
                ON Movies.movie_id = MovieRating.movie_id
        WHERE EXTRACT(YEAR_MONTH FROM MovieRating.created_at) = 202002
        GROUP BY MovieRating.movie_id
        ORDER BY AVG(MovieRating.rating) DESC,
            Movies.title
        LIMIT 1)
