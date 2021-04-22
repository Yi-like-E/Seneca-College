-- ***********************
-- Name: YiHsun Lee
-- ID: 129713202
-- Date:03/17/2021
-- Purpose: Lab 7 DBS211
-- ***********************

-- Part A Transaction --
-- 1.
CREATE TABLE new_employees(
employeenumber NUMBER(38,0) primary key,
lastname VARCHAR(50) NOT NULL,
firstname VARCHAR(50) NOT NULL,
extension VARCHAR(50) NOT NULL,
email VARCHAR(100) NOT NULL,
officecode VARCHAR(10) NOT NULL,
reportsto NUMBER(38,0) DEFAULT NULL,
jobtitle VARCHAR(50) NOT NULL,
CONSTRAINT fk_officecode FOREIGN KEY (officecode) REFERENCES offices(officecode),
CONSTRAINT fk_reportsto FOREIGN KEY (reportsto) REFERENCES employees(employeenumber)
);

-- 2.
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

-- 3.
INSERT ALL 
INTO new_employees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- 4.
SELECT * FROM new_employees;
/* 5 rows are fetched */

-- 5.
ROLLBACK;
SELECT * FROM new_employees;
/* 0 rows are fetched */

-- 6.
INSERT ALL 
INTO new_employees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;
COMMIT;
SELECT * FROM new_employees;
/* 5 rows are selected */

-- 7.
UPDATE new_employees SET jobtitle = 'unknown';

-- 8.
COMMIT;

-- 9.
ROLLBACK;
-- 9a.
SELECT * FROM new_employees WHERE jobtitle = 'unknown';
/* 5 rows are still updated*/
-- 9b.
/* The rever wasn't effective.*/
-- 9c.
/* This revert execution is different than the Task 5 is that the change is being made permanently due to commit command. 
Thus, the rollback here doesn't work as the transaction was finished successfully and can't be undone.*/

-- 10.
COMMIT;
TRUNCATE TABLE new_employees;

-- 11.
CREATE VIEW vw_new_emps AS
SELECT * FROM new_employees
ORDER BY lastname, firstname;

-- 12.
ROLLBACK;
-- 12a.
SELECT * FROM new_employees;
/* 0 employees in the new_employees table */
-- 12b.
/* The deletion wasn't undone, since truncate is a DDL statement, and a DDL fires an auto-commit so the transaction is completed
and a new transaction begins. Therefore, the rollback only undone the create view statement. */

-- 13.
COMMIT;
INSERT ALL 
INTO new_employees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- 14.
SAVEPOINT insertion;

-- 15.
UPDATE new_employees SET jobtitle = 'unknown';
SELECT * FROM new_employees;

-- 16.
ROLLBACK TO insertion;
SELECT * FROM new_employees;
/* The jobtitle for all the rows are no longer unknown, they're back to Sales Rep. With the rollback to savepoint insertion, 
the update statement from Q15 is undone.*/

-- 17.
ROLLBACK;
SELECT * FROM new_employees;
/* The roll back undone all the actions and statements of the whole transaction. Thus, the data inside the new_employess table
that we inserted in Q13 no longer exist.*/


-- Part B Permission --
-- 18.
REVOKE ALL ON new_employees FROM public;

-- 19.
GRANT SELECT ON new_employees TO dbs211_211h02;

-- 20.
GRANT INSERT, UPDATE, DELETE ON new_employees TO dbs211_211h02;

-- 21.
REVOKE ALL ON new_employees FROM dbs211_211h02;


-- Part C Clean up --
-- 22.
DROP TABLE new_employees;
DROP VIEW vw_new_emps;