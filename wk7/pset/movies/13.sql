SELECT name
FROM people
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = "Bradley Cooper"
    )
) AND (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = "Jennifer Lawrence"
    )
)
;
