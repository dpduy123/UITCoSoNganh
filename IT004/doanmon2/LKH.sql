------01.sql
DROP TRIGGER IF EXISTS dambaotinhdx_them;
CREATE TRIGGER dambaotinhdx_them
BEFORE INSERT ON Friend
FOR EACH ROW
BEGIN
    -- Ngăn chèn nếu cặp (ID1, ID2) đã tồn tại
    SELECT RAISE(IGNORE) 
    WHERE EXISTS (SELECT 1 FROM Friend WHERE ID1 = NEW.ID1 AND ID2 = NEW.ID2);

    -- Chèn dòng đối xứng (ID2, ID1) nếu chưa tồn tại
    INSERT INTO Friend (ID1, ID2)
    SELECT NEW.ID2, NEW.ID1
    WHERE NOT EXISTS (SELECT 1 FROM Friend WHERE ID1 = NEW.ID2 AND ID2 = NEW.ID1);
END;

DROP TRIGGER IF EXISTS dambaotinhdx_xoa;
CREATE TRIGGER dambaotinhdx_xoa
AFTER DELETE ON Friend
FOR EACH ROW
BEGIN
    DELETE FROM Friend
    WHERE ID1 = OLD.ID2 AND ID2 = OLD.ID1;
END;

DROP TRIGGER IF EXISTS dambaotinhdx_sua;
CREATE TRIGGER dambaotinhdx_sua
AFTER UPDATE ON Friend
FOR EACH ROW
BEGIN
    -- Xóa dòng đối xứng cũ
    DELETE FROM Friend
    WHERE ID1 = OLD.ID2 AND ID2 = OLD.ID1;

    -- Chèn dòng đối xứng mới
    INSERT INTO Friend (ID1, ID2)
    SELECT NEW.ID2, NEW.ID1
    WHERE NOT EXISTS (SELECT 1 FROM Friend WHERE ID1 = NEW.ID2 AND ID2 = NEW.ID1);
END;


------02.sql

DROP TRIGGER IF EXISTS manage_grade_on_insert_CHECK;
CREATE TRIGGER manage_grade_on_insert_CHECK
BEFORE INSERT ON Highschooler
FOR EACH ROW
WHEN (NEW.grade < 9 OR NEW.grade > 12)
BEGIN
    SELECT RAISE(IGNORE);
END;

DROP TRIGGER IF EXISTS manage_grade_on_insert_UPD;
CREATE TRIGGER manage_grade_on_insert_UPD
AFTER INSERT ON Highschooler
FOR EACH ROW 
WHEN (NEW.grade is NULL)
BEGIN
	UPDATE Highschooler
	SET grade = 9
	WHERE ID = NEW.id;
END;


------03.sql
DROP TRIGGER IF EXISTS remove_graduates;

CREATE TRIGGER remove_graduates
AFTER UPDATE OF grade ON Highschooler
FOR EACH ROW
WHEN (NEW.grade > 12)
BEGIN
        DELETE FROM Friend
        WHERE ID1 = OLD.ID OR ID2 = OLD.ID;

        -- Xóa các quan hệ thích liên quan
        DELETE FROM Likes
        WHERE ID1 = OLD.ID OR ID2 = OLD.ID;

        -- Xóa học sinh khỏi bảng Highschooler
        DELETE FROM Highschooler
        WHERE ID = OLD.ID;
END;

------04.sql
DROP TRIGGER IF EXISTS promote_friends;

CREATE TRIGGER promote_friends
AFTER UPDATE OF grade ON Highschooler
FOR EACH ROW
WHEN (NEW.grade - OLD.grade = 1) 
BEGIN
    UPDATE Highschooler
    SET grade = grade + 1
    WHERE ID IN (
        SELECT ID2 FROM Friend WHERE ID1 = NEW.ID
        UNION
        SELECT ID1 FROM Friend WHERE ID2 = NEW.ID
    );
END;
---test 04.sql

------05.sql
CREATE VIEW JordanFriend AS
SELECT H2.name, H2.grade
FROM Highschooler H1
JOIN Friend F ON H1.ID = F.ID1
JOIN Highschooler H2 ON F.ID2 = H2.ID
WHERE H1.name = 'Jordan';

DROP TRIGGER IF EXISTS update_jordanfriend;

CREATE TRIGGER update_jordanfriend
INSTEAD OF UPDATE ON JordanFriend
FOR EACH ROW
BEGIN
    -- Kiểm tra nếu grade nằm ngoài khoảng từ 9 đến 12
    SELECT RAISE(ABORT, 'Invalid grade: must be between 9 and 12')
    WHERE NEW.grade < 9 OR NEW.grade > 12;

    -- Kiểm tra tính duy nhất của (name, grade)
    SELECT RAISE(ABORT, 'Duplicate (name, grade) not allowed')
    WHERE EXISTS (
        SELECT 1 FROM Highschooler
        WHERE name = NEW.name AND grade = NEW.grade
        AND ID <> (SELECT ID FROM Highschooler WHERE name = OLD.name AND grade = OLD.grade)
    );

    -- Cập nhật bảng Highschooler
    UPDATE Highschooler
    SET name = NEW.name, grade = NEW.grade
    WHERE name = OLD.name AND grade = OLD.grade;
END;