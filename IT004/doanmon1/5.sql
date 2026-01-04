CREATE VIEW Favorites AS
SELECT 
    rID, 
    mID
FROM 
    Rating
WHERE 
    stars = (SELECT MAX(stars) 
             FROM Rating AS R2 
             WHERE Rating.rID = R2.rID);

SELECT 
    R1.name AS Reviewer1, 
    R2.name AS Reviewer2, 
    M.title AS Movie
FROM 
    Favorites F1
JOIN 
    Favorites F2 ON F1.mID = F2.mID AND F1.rID < F2.rID
JOIN 
    Reviewer R1 ON F1.rID = R1.rID
JOIN 
    Reviewer R2 ON F2.rID = R2.rID
JOIN 
    Movie M ON F1.mID = M.mID;
