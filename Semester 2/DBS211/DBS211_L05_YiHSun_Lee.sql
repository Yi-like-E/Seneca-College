-- ***********************
-- Name: YiHsun Lee
-- ID: 129713202
-- Date:02/17/2021
-- Purpose: Lab 0 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT e.employeenumber, e.lastname, e.firstname, o.city, o.phone, o.postalcode
FROM employees e JOIN offices o
USING (officecode)
WHERE LOWER(o.country) = 'france'
ORDER BY 1;

-- Q2 SOLUTION --
SELECT *
FROM payments p JOIN customers c
USING (customernumber)
WHERE c.country = 'Canada';

-- Q2.a SOLUTION --
SELECT *
FROM payments p JOIN customers c
USING (customernumber)
WHERE c.country = 'Canada'
ORDER BY customernumber;

-- Q2.b SOLUTION --
SELECT c.customernumber, c.customername, p.paymentdate, p.amount
FROM payments p JOIN customers c
ON p.customernumber = c.customernumber
WHERE c.country = 'Canada'
ORDER BY 1;

-- Q2.c SOLUTION --
SELECT c.customernumber, c.customername, to_Char(p.paymentdate, 'Mon DD, YYYY') AS paymentdate, p.amount
FROM payments p JOIN customers c
ON p.customernumber = c.customernumber
WHERE c.country = 'Canada'
ORDER BY 1;

-- Q3 SOLUTION --
SELECT employeenumber, firstname || ' ' || lastname employeename, email 
FROM employees LEFT OUTER JOIN customers 
ON employees.employeenumber = customers.salesrepemployeenumber
WHERE salesrepemployeenumber IS NULL
ORDER BY 2;

-- Q4.a SOLUTION --
CREATE VIEW vw_customer_order AS
SELECT o.customernumber, o.ordernumber, o.orderdate, p.productname, od.quantityordered, od.priceeach
FROM orderdetails od LEFT JOIN orders o ON od.ordernumber = o.ordernumber 
LEFT JOIN products p ON od.productcode = p.productcode;

-- Q4.b SOLUTION --
SELECT * FROM vw_customer_order
ORDER BY customernumber;

-- Q5 SOLUTION --
CREATE OR REPLACE VIEW vw_customer_order AS
SELECT o.customernumber, o.ordernumber, o.orderdate, p.productname, od.quantityordered, od.priceeach, od.orderlinenumber
FROM orderdetails od LEFT JOIN orders o ON od.ordernumber = o.ordernumber 
LEFT JOIN products p ON od.productcode = p.productcode
WHERE o.customernumber = 124;

SELECT * FROM vw_customer_order
ORDER BY ordernumber, orderlinenumber;

-- Q6 SOLUTION --
SELECT c.customernumber, c.contactfirstname, c.contactlastname, c.phone, c.creditlimit
FROM customers c LEFT JOIN orders o
ON c.customernumber = o.customernumber
WHERE o.customernumber IS NULL
ORDER BY 1;

-- Q7 SOLUTION --
CREATE VIEW vw_employee_manager AS
SELECT e.*, m.firstname AS managerFirstName, m.lastname AS managerLastName
FROM employees e LEFT OUTER JOIN employees m
ON e.reportsto = m.employeenumber;
SELECT * FROM vw_employee_manager
ORDER BY employeenumber;

-- Q8 SOLUTION --
CREATE OR REPLACE VIEW vw_employee_manager AS
SELECT e.*,  m.firstname AS managerFirstName, m.lastname AS managerLastName
FROM employees e LEFT OUTER JOIN employees m
ON e.reportsto = m.employeenumber
WHERE e.reportsto IS NOT NULL;
SELECT * FROM vw_employee_manager
ORDER BY employeenumber;

-- Q9 SOLUTION --
DROP VIEW vw_customer_order;
DROP VIEW vw_employee_manager;