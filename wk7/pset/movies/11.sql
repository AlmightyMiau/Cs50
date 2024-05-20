SELECT title
FROM movies
-- JOIN ratings ON movies.id = ratings.movie_id
WHERE id IN (
    SELECT movie_id
    FROM ratings
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = "Chadwick Boseman"
    )
)
ORDER BY rating
;
