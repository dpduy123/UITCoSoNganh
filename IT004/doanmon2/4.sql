PRAGMA recursive_triggers = OFF;
DROP TRIGGER IF EXISTS Upgrade;
CREATE TRIGGER Upgrade
AFTER UPDATE ON Highschooler
FOR EACH ROW
WHEN OLD.grade + 1 = NEW.grade
BEGIN
    UPDATE Highschooler
    SET grade = grade + 1
    WHERE ID IN (
        SELECT ID1 FROM Friend WHERE ID2 = NEW.ID
    );
END;
