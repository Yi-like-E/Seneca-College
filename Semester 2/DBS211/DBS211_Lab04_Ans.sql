SET AUTOCOMMIT ON; 

-- Q1 SOLUTION -- 
CREATE TABLE employee2 AS
SELECT *
FROM employees
WHERE 1 = 2;


-- Q2 SOLUTION -- 
ALTER TABLE employee2
ADD PRIMARY KEY (employeenumber);

ALTER TABLE employee2 
ADD FOREIGN KEY (reportsto) 
REFERENCES employee2 (employeenumber);


-- Q3 SOLUTION -- 
INSERT INTO employee2
SELECT *
FROM employees;


-- Q4 SOLUTION -- 
INSERT INTO employee2
VALUES ((SELECT employeenumber + 1 FROM employee2 ORDER BY 1 DESC FETCH NEXT 1 ROW ONLY), --this query is optional, you may hardcode the value 1703
        'Ghosh',
        'Shweta',
        'x2222',
        'shweta.ghosh@senecacollege.ca',
        4,
        1088,
        'Head Cashier');


-- Q5 SOLUTION -- 
INSERT INTO employee2
VALUES ((SELECT employeenumber + 1 FROM employee2 ORDER BY 1 DESC FETCH NEXT 1 ROW ONLY), --this query is optional, you may hardcode the value 1704
        'Thakur',
        'Rabi',
        'x2223',
        'rthakur@bharat.com',
        4,
        (SELECT employeenumber from employee2 WHERE email = 'shweta.ghosh@senecacollege.ca'), --this query is optional, you may hardcode the value 1703
        'Cashier');


-- Q6 SOLUTION -- 
/*
DELETE FROM employee2
WHERE email = 'shweta.ghosh@senecacollege.ca'; --employeenumber, name, etc can be used too

This employee could not be deleted so as to maintain the 
referential integrity as the fictional employee created in
question 5 is its child record via a foreign key constraint
(without an ON DELETE clause). 
*/


-- Q7 SOLUTION -- 
DELETE FROM employee2
WHERE email = 'rthakur@bharat.com'; --child record

DELETE FROM employee2
WHERE email = 'shweta.ghosh@senecacollege.ca'; --parent record

/*
These statements worked because the child record was deleted prior to the parent record.
*/


-- Q8 SOLUTION -- 
INSERT ALL
INTO employee2 VALUES  ((SELECT employeenumber + 1 FROM employee2 ORDER BY 1 DESC FETCH NEXT 1 ROW ONLY), --this query is optional, you may hardcode the value 1703
                        'Ghosh',
                        'Shweta',
                        'x2222',
                        'shweta.ghosh@senecacollege.ca',
                        4,
                        1088,
                        'Head Cashier')
INTO employee2 VALUES  ((SELECT employeenumber + 1 FROM employee2 ORDER BY 1 DESC FETCH NEXT 1 ROW ONLY), --this query is optional, you may hardcode the value 1704
                        'Thakur',
                        'Rabi',
                        'x2223',
                        'rthakur@bharat.com',
                        4,
                        1088,
                        'Cashier')
SELECT *
FROM dual;


-- Q9 SOLUTION -- 
DELETE FROM employee2
WHERE email IN ('shweta.ghosh@senecacollege.ca','rthakur@bharat.com'); --employeenumber, name, etc can be used too


-- Q10 SOLUTION -- 
UPDATE employee2
SET firstname = 'Shweta',    
    lastname = 'Ghosh'
WHERE employeenumber = 1002;


-- Q11 SOLUTION -- 
DELETE FROM employee2;


-- Q12 SOLUTION -- 
DROP TABLE employee2;
