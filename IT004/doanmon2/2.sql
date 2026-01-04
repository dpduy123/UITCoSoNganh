PRAGMA recursive_triggers = OFF;
DROP TRIGGER IF EXISTS CheckGrade;
DROP TRIGGER IF EXISTS CheckGradeNull;
DROP TRIGGER IF EXISTS CheckRange;
DROP TRIGGER IF EXISTS CheckGradeNullUpdate;

CREATE TRIGGER CheckGrade
BEFORE INSERT ON Highschooler
FOR EACH ROW
BEGIN
    SELECT RAISE(FAIL, 'Grade must be between 9 and 12')
    WHERE NEW.grade IS NOT NULL AND (NEW.grade < 9 OR NEW.grade > 12);
END;
CREATE TRIGGER CheckGradeNull
AFTER INSERT ON Highschooler
FOR EACH ROW
BEGIN
    UPDATE Highschooler
    SET grade = 9
    WHERE ID = NEW.ID AND NEW.grade IS NULL;
END;

CREATE TRIGGER CheckGradeNullUpdate
AFTER Update ON Highschooler
FOR EACH ROW
BEGIN
    UPDATE Highschooler
    SET grade = 9
    WHERE ID = NEW.ID AND NEW.grade IS NULL;

    UPDATE Highschooler
    SET grade = 9
    WHERE name = NEW.name AND NEW.grade IS NULL;
END;
CREATE TRIGGER CheckRange
BEFORE UPDATE ON Highschooler
FOR EACH ROW
BEGIN
    SELECT RAISE(FAIL, 'Grade must be between 9 and 12')
    WHERE NEW.grade IS NOT NULL AND (NEW.grade < 9);
END;
