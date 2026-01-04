CREATE TABLE "Movie" (
	"mID"	INTEGER,
	"title"	TEXT UNIQUE,
	"year"	INTEGER CHECK("year" > 1900) UNIQUE,
	"director"	TEXT,
	PRIMARY KEY("mID")
);

CREATE TABLE "Reviewer" (
	"rID"	INTEGER,
	"name"	TEXT NOT NULL,
	PRIMARY KEY("rID")
);

CREATE TABLE "Rating" (
	"rID"	INTEGER,
	"mID"	INTEGER,
	"stars"	INTEGER NOT NULL CHECK("stars" IN (1, 2, 3, 4, 5)),
	"ratingDate"	DATE CHECK(strftime('%Y', "ratingDate") > '2000'),
	FOREIGN KEY("mID") REFERENCES "Movie"("mID"),
	FOREIGN KEY("rID") REFERENCES "Reviewer"("rID")
);

CREATE TRIGGER SpielbergMoviesBefore1990
BEFORE INSERT ON Movie
WHEN NEW.director = 'Steven Spielberg' AND NEW.year >= 1990
BEGIN
    SELECT RAISE(FAIL, 'Movies by Steven Spielberg must be before 1990');
END