CREATE VIEW RatingStats AS
SELECT 
    title,
    COUNT(*) AS reviewCount,
    AVG(stars) AS averageRating
FROM 
    TNS
GROUP BY 
    title

SELECT title
FROM RatingStats
WHERE reviewCount >= 3
ORDER BY averageRating DESC
LIMIT 1;
