-- ***********************
-- Name: YiHsun Lee
-- ID: 129713202
-- Date:02/12/2021
-- Purpose: Lab 04 DBS211
-- ***********************

SET AUTOCOMMIT ON;

-- Q1 SOLUTION --
CREATE TABLE employees2(
    employeenumber NUMBER(38,0) NOT NULL,
    lastname VARCHAR2(50) NOT NULL,
    firstname VARCHAR2(50) NOT NULL,
    extension VARCHAR2(10) NOT NULL,
    email VARCHAR2(100) NOT NULL,
    officecode VARCHAR2(10) NOT NULL,
    reportsto NUMBER(38,0),
    jobtitle VARCHAR2(50) NOT NULL,
    CONSTRAINT pk_employeenumber PRIMARY KEY (employeenumber)
);

-- Q2 SOLUTION --
ALTER TABLE employees2
ADD CONSTRAINT fk_reportsto
FOREIGN KEY (reportsto)
REFERENCES employees2;

-- Q3 SOLUTION --
INSERT INTO employees2 (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
SELECT employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle
FROM employees;

-- Q4 SOLUTION --
INSERT INTO employees2
VALUES (1703, 'Lee', 'YiHsun', 'x2222', 'ylee212@myseneca.ca', '4', 1088, 'Head Cashier');

-- Q5 SOLUTION --
INSERT INTO employees2
VALUES (1704, 'Ryan', 'Gosling', 'x1993', 'r.gosling@gmail.com', '4', 1703, 'Cashier');

-- Q6 SOLUTION --
/*
DELETE FROM employees2
WHERE employeenumber = 1703;

I can't delete myself from the table because the created fictional employee from question 5 reports to me through reportsto.
Thus, due to the connection I will not be able to delete myself. 
*/

-- Q7 SOLUTION --
DELETE FROM employees2
WHERE employeenumber = 1704;
DELETE FROM employees2
WHERE employeenumber = 1703;
/*
I am able to delete myself from the table after deleting the fictional employee first since the connection between me 
and the fictional employee through reportsto is no longer there after deleting the fictional employee.
*/

-- Q8 SOLUTION --
INSERT ALL 
    INTO employees2 VALUES (1703, 'Lee', 'YiHsun', 'x2222', 'ylee212@myseneca.ca', '4', 1088, 'Head Cashier')
    INTO employees2 VALUES (1704, 'Ryan', 'Gosling', 'x1993', 'r.gosling@gmail.com', '4', 1088, 'Cashier')
    SELECT * FROM dual;
    
-- Q9 SOLUTION --
DELETE FROM employees2
WHERE employeenumber IN (1703, 1704);

-- Q10 SOLUTION --
UPDATE employees2 
SET firstname = 'YiHsun',
    lastname = 'Lee'
WHERE employeenumber = 1002;

-- Q11 SOLUTION --
DELETE FROM employees2;    

-- Q12 SOLUTION --
DROP TABLE employees2;