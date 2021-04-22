-- ***********************
-- Name: 
-- ID: 
-- Date: 2021-02-02
-- Purpose: Lab 02 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT officecode,
       city,
       state,
       country,
       phone
FROM offices;

-- Q2 SOLUTION --
SELECT employeenumber,
       firstname,
       lastname,
       extension
FROM employees
WHERE officecode = 1
ORDER BY 1;

-- Q3 SOLUTION --
SELECT customernumber,
       customername,
       contactfirstname,
       contactlastname,
       phone
FROM customers
WHERE LOWER(city) = 'paris'
ORDER BY 1;

-- Q4 SOLUTION --
SELECT customernumber,
       customername,
       contactlastname ||', ' || contactfirstname AS contact_name,
       phone
FROM customers
WHERE country = 'Canada'
ORDER BY 2;

-- Q5 SOLUTION --
SELECT DISTINCT customernumber
FROM payments
ORDER BY 1;

-- Q6 SOLUTION --
SELECT customernumber,
       checknumber,
       amount
FROM payments
WHERE amount NOT BETWEEN 1500 AND 120000
ORDER BY 3 DESC;

-- Q7 SOLUTION --
SELECT productcode,
       productname,
       buyprice,
       msrp,
       (msrp - buyprice) AS markup,
       ROUND(100 * ((msrp - buyprice) / buyprice), 1) AS percmarkup
FROM products
WHERE (100 * ((msrp - buyprice) / buyprice)) > 140
ORDER BY 6;

-- Q8 SOLUTION --
SELECT REPLACE(productcode, '_', ' ') AS productcode,
       productname,
       quantityinstock 
FROM products
WHERE LOWER(productname) LIKE '%co%'
ORDER BY 3;

-- Q9 SOLUTION --
SELECT customernumber,
       contactfirstname,
       contactlastname
FROM customers
WHERE LOWER(contactfirstname) LIKE 's%e%'
ORDER BY 1;