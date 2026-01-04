CREATE VIEW TNS AS
SELECT 
    Movie.title, 
    Reviewer.name, 
    Rating.stars
FROM 
    Movie
JOIN 
    Rating ON Movie.mID = Rating.mID
JOIN 
    Reviewer ON Rating.rID = Reviewer.rID

SELECT Movie.mID, Movie.title, MAX(Movie.year) AS RecentYear
FROM TNS
JOIN Movie ON TNS.title = Movie.title
WHERE TNS.name = 'Chris Jackson';
