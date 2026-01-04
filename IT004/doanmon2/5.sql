PRAGMA recursive_triggers = OFF;

DROP VIEW IF EXISTS JordanFriend; 
DROP TRIGGER IF EXISTS UpdateJordanFriend;

CREATE VIEW JordanFriend AS
SELECT name, grade
FROM Highschooler
WHERE ID IN (
    SELECT ID1
    FROM Friend
    WHERE ID2 IN (
        SELECT ID FROM Highschooler WHERE name = 'Jordan'
    )
);

CREATE TRIGGER UpdateJordanFriend
INSTEAD OF UPDATE ON JordanFriend
FOR EACH ROW 
BEGIN
    SELECT RAISE(FAIL, 'Grade must be between 9 and 12') 
    WHERE NEW.grade < 9 OR NEW.grade > 12;

    SELECT RAISE(FAIL, 'Duplicate (name, grade) detected') 
    WHERE EXISTS (
        SELECT 1
        FROM Highschooler 
        WHERE name = NEW.name 
          AND grade = NEW.grade
          AND (name != OLD.name OR grade != OLD.grade)
    );
    
    UPDATE Highschooler
    SET name = NEW.name, grade = NEW.grade
    WHERE name = OLD.name AND grade = OLD.grade;
END;
