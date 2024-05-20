SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM directors
    WHERE movie_id = (
        SELECT id
        FROM movies
        WHERE year = 2004
        )
    )
;
