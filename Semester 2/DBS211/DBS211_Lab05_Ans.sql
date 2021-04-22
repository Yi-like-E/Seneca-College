-- Q1 SOLUTION -- 
SELECT employeenumber, 
       firstname, 
       lastname, 
       city, 
       phone || ' ' || extension phonenumber, --concat of extn is optional but makes more sense
       postalcode
FROM employees
JOIN offices 
USING (officecode)
WHERE country = 'France';


-- Q2 SOLUTION -- 
SELECT customernumber,
       customername,
       TO_CHAR(paymentdate, 'Mon DD, YYYY') AS paymentdate,
       amount
FROM payments
JOIN customers
USING (customernumber)
WHERE country = 'Canada'
ORDER BY 1;


-- Q3 SOLUTION --
SELECT employeenumber, 
       firstname || ' ' || lastname AS employeefullname,
       email
FROM employees
LEFT JOIN customers
ON employeenumber = salesrepemployeenumber
WHERE salesrepemployeenumber IS NULL
ORDER BY 2;


-- Q4 SOLUTION -- 
CREATE VIEW vw_customer_order AS 
SELECT customernumber, 
       ordernumber, 
       orderdate,
       productname,
       quantityordered,
       priceeach
FROM orders
JOIN orderdetails
USING (ordernumber)
JOIN products
USING (productcode);

SELECT * FROM vw_customer_order;


-- Q5 SOLUTION -- I have chosen some columns here, your columns may vary
SELECT v.ordernumber,
       orderlinenumber,
       orderdate,
       od.productcode,
       productname,
       v.quantityordered,
       v.priceeach
FROM vw_customer_order v
JOIN orderdetails od
ON v.ordernumber = od.ordernumber
WHERE customernumber = 124
ORDER BY 1, 2;


-- Q6 SOLUTION --
SELECT c.customernumber, 
       contactfirstname,
       contactlastname,
       phone,
       creditlimit
FROM customers c
LEFT JOIN orders o
ON c.customernumber = o.customernumber
WHERE o.customernumber IS NULL;


-- Q7 SOLUTION -- 
CREATE VIEW vw_employee_manager AS
SELECT emp.*,
       mgr.firstname || ' ' || mgr.lastname AS manager --may also be shown as separate columns too
FROM employees emp
LEFT JOIN employees mgr
ON emp.reportsto = mgr.employeenumber;


-- Q8 SOLUTION -- 
CREATE OR REPLACE VIEW vw_employee_manager AS
SELECT emp.*,
       mgr.firstname || ' ' || mgr.lastname AS manager --may also be shown as separate columns too
FROM employees emp
JOIN employees mgr
ON emp.reportsto = mgr.employeenumber;


-- Q9 SOLUTION -- 
DROP VIEW vw_customer_order;
DROP VIEW vw_employee_manager;