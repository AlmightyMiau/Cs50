SELECT title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN people ON ratings.person_id = people.id
WHERE name = "Chadwick Boseman"
ORDER BY rating
;
