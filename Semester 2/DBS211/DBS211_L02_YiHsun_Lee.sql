-- ***********************
-- Name: YiHsun Lee
-- ID: 129713202
-- Date:01/27/2020
-- Purpose: Lab 02 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT * 
FROM offices; 

-- Q2 Solution –-
SELECT employeenumber, firstname, lastname, extension
FROM employees
WHERE officecode = 1
ORDER BY employeenumber;  

-- Q3 Solution --
SELECT customernumber, customername, contactfirstname, contactlastname, phone
FROM customers
WHERE lower(city) = 'paris'
ORDER BY customernumber;

-- Q4 Solution --
SELECT customernumber, customername, contactlastname || ' ' || contactfirstname AS "Contact Name",phone
FROM customers
WHERE lower(country) = 'canada'
ORDER BY customername;

-- Q5 Solution --
SELECT customernumber
FROM customers
WHERE creditlimit > 0
FETCH NEXT 10 ROWS ONLY;

-- Q6 Solution --
SELECT customernumber, checknumber, amount
FROM payments
WHERE amount NOT BETWEEN 1500 AND 120000
ORDER BY amount DESC;

-- Q7 Solution --
SELECT productcode,
       productname,
       buyprice, 
       msrp,
       msrp - buyprice AS "markup",
       round(100 * ((msrp - buyprice)/buyprice),1) AS percmarkup
FROM products
WHERE round(100 * ((msrp - buyprice)/buyprice),1) > 140
ORDER BY percmarkup;

-- Q8 Solution --
SELECT productcode, productname, quantityinstock
FROM products
WHERE lower(productname) LIKE '%co%'
ORDER BY quantityinstock;

-- Q9 Solution --
SELECT customernumber, contactfirstname, contactlastname
FROM customers
WHERE lower(contactfirstname) LIKE 's%e%'
ORDER BY customernumber ASC;
