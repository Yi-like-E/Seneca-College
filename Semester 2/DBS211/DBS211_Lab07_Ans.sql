-- Q1 SOLUTION -- .1
CREATE TABLE new_employees AS
SELECT * 
FROM employees 
WHERE 1 = 2;


-- Q2 SOLUTION -- 
SET AUTOCOMMIT OFF;

SET TRANSACTION READ WRITE;


-- Q3 SOLUTION -- .1
INSERT ALL
INTO new_employees VALUES (100, 
                           'Patel', 
                           'Ralph', 
                           22333, 
                           'rpatel@mail.com', 
                           1, 
                           NULL,
                           'Sales Rep')
INTO new_employees VALUES (101, 
                           'Denis', 
                           'Betty', 
                           33444, 
                           'bdenis@mail.com', 
                           4, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (102, 
                           'Biri', 
                           'Ben', 
                           44555, 
                           'bbirir@mail.com', 
                           2, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (103, 
                           'Newman', 
                           'Chad', 
                           66777, 
                           'cnewman@mail.com', 
                           3, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (104, 
                           'Ropeburn', 
                           'Audrey', 
                           77888, 
                           'aropebur@mail.com', 
                           1, 
                           NULL, 
                           'Sales Rep')
SELECT *
FROM dual;


-- Q4 SOLUTION -- .2
SELECT * FROM new_employees; -- 5 rows fetched


-- Q5 SOLUTION -- .2
ROLLBACK;

SELECT * FROM new_employees; -- No rows fetched


-- Q6 SOLUTION -- .2
INSERT ALL
INTO new_employees VALUES (100, 
                           'Patel', 
                           'Ralph', 
                           22333, 
                           'rpatel@mail.com', 
                           1, 
                           NULL,
                           'Sales Rep')
INTO new_employees VALUES (101, 
                           'Denis', 
                           'Betty', 
                           33444, 
                           'bdenis@mail.com', 
                           4, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (102, 
                           'Biri', 
                           'Ben', 
                           44555, 
                           'bbirir@mail.com', 
                           2, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (103, 
                           'Newman', 
                           'Chad', 
                           66777, 
                           'cnewman@mail.com', 
                           3, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (104, 
                           'Ropeburn', 
                           'Audrey', 
                           77888, 
                           'aropebur@mail.com', 
                           1, 
                           NULL, 
                           'Sales Rep')
SELECT *
FROM dual;

COMMIT;

SELECT * FROM new_employees; -- 5 rows fetched


-- Q7 SOLUTION -- .1
UPDATE new_employees
SET jobtitle = 'unknown';


-- Q8 SOLUTION -- .1
COMMIT;


-- Q9 SOLUTION -- .1
ROLLBACK; 


-- Q9a -- .2
SELECT * 
FROM new_employees 
WHERE jobtitle = 'unknown'; -- 5 rows updated 

-- Q9b -- .1
-- No, the revert was ineffective.

-- Q9c -- .1
/* Before this revert, a commit was fired after the UPDATE DML in Q7, thus making the changes permanant.
However, the revert execution in Task 5 worked because the rollback was fired before the INSERT DML in Q3 wase made permanent.*/


-- Q10 SOLUTION -- .1
SET TRANSACTION READ WRITE; --you may use any other form of beginning a transaction apart from unnecessary DDL

DELETE FROM new_employees;


-- Q11 SOLUTION -- .1
CREATE VIEW vw_new_emps AS
SELECT * 
FROM new_employees
ORDER BY lastname, firstname;


-- Q12 SOLUTION -- .1
ROLLBACK;

-- Q12a --.1
SELECT * 
FROM new_employees; -- no employees in the new_employees table.

-- Q12b --.2
/* The deletion was NOT undone because CREATE VIEW is a DDL statement which fires an autocommit,
due to which the Delete DML statement executated prior to it got committed.*/

-- Q13 SOLUTION --
SET TRANSACTION READ WRITE;

INSERT ALL
INTO new_employees VALUES (100, 
                           'Patel', 
                           'Ralph', 
                           22333, 
                           'rpatel@mail.com', 
                           1, 
                           NULL,
                           'Sales Rep')
INTO new_employees VALUES (101, 
                           'Denis', 
                           'Betty', 
                           33444, 
                           'bdenis@mail.com', 
                           4, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (102, 
                           'Biri', 
                           'Ben', 
                           44555, 
                           'bbirir@mail.com', 
                           2, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (103, 
                           'Newman', 
                           'Chad', 
                           66777, 
                           'cnewman@mail.com', 
                           3, 
                           NULL, 
                           'Sales Rep')
INTO new_employees VALUES (104, 
                           'Ropeburn', 
                           'Audrey', 
                           77888, 
                           'aropebur@mail.com', 
                           1, 
                           NULL, 
                           'Sales Rep')
SELECT *
FROM dual;


-- Q14 SOLUTION -- .1
SAVEPOINT insertion;


-- Q15 SOLUTION --
UPDATE new_employees
SET jobtitle = 'unknown';

SELECT * FROM new_employees;


-- Q16 SOLUTION -- .2
ROLLBACK TO insertion;

SELECT * FROM new_employees;
/*
The query displays the same data that was inserted in Q13 before the Savepoint creation because the transaction was rolled back
only till the Savepoint. The UPDATE DML after this savepoint which changed the jobtitle to "unknown" was therefore undone.
*/


-- Q17 SOLUTION -- .2
ROLLBACK;

SELECT * FROM new_employees;
/*
No rows fetched. 
This is because the current transaction was rolled back till the beginning of the transaction,
therefore the INSERT ALL DML which was part of this transaction was undone.
*/


-- Q18 SOLUTION -- .1
REVOKE ALL ON new_employees FROM PUBLIC;


-- Q19 SOLUTION -- .1
GRANT SELECT ON new_employees TO dbs211_211h02;


-- Q20 SOLUTION -- .1
GRANT INSERT, UPDATE, DELETE ON new_employees TO dbs211_211h02;


-- Q21 SOLUTION -- .1
REVOKE ALL ON new_employees FROM dbs211_211h02;


-- Q22 SOLUTION -- .2
DROP VIEW vw_new_emps;
DROP TABLE new_employees;
