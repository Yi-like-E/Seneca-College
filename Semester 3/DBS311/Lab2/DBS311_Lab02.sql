--1.
SELECT department_id,
       MAX(salary) "High",
       MIN(salary) "Low",
       ROUND(AVG(salary)) "Avg"
FROM employee
GROUP BY department_id
ORDER BY "Avg" DESC;

--2. 
SELECT department_id "Dept#", job_id "Job", 
       COUNT(employee_id) "HowMany"
FROM employee
GROUP BY department_id, job_id
HAVING COUNT(employee_id) > 1
ORDER BY COUNT(employee_id) DESC;

--3.
SELECT job_id, SUM(salary)"Total Amount Paid per Month"
FROM employee
WHERE UPPER(job_id) NOT IN ('AD_PRES', 'AD_VP')
GROUP BY job_id
HAVING SUM(salary) > 15000
ORDER BY 2 DESC;

--4.
SELECT manager_id, COUNT(employee_id) "# of Person Supervise"
FROM employee
GROUP BY manager_id
HAVING manager_id NOT IN (100, 101, 102) AND COUNT(employee_id) > 2
ORDER BY COUNT(employee_id) DESC;

--5.
SELECT department_id, MAX(hire_date) "Latest Hire Date", 
       MIN(hire_date) "Earliest Hire Date"
FROM employee
WHERE department_id NOT IN (10, 20)
GROUP BY department_id 
HAVING EXTRACT(YEAR FROM(MAX(hire_date))) != 2000
ORDER BY 2 DESC;

--6.
SELECT d.department_name, l.city, COUNT(e.employee_id)"Total Workers"
FROM department d JOIN location l
ON (d.location_id = l.location_id)
JOIN employee e
ON (e.department_id = d.department_id)
WHERE INSTR(d.department_name, 'S') = 0
GROUP BY d.department_name, l.city
HAVING COUNT(e.employee_id) >= 3
ORDER BY d.department_name;

--7.
SELECT d.department_name, l.city, COUNT(e.employee_id)"Total Workers"
FROM department d JOIN location l
ON (d.location_id = l.location_id)
LEFT JOIN employee e ON (e.department_id = d.department_id)
WHERE INSTR(d.department_name, 'A') = 0 
GROUP BY d.department_name, l.city
HAVING COUNT(e.employee_id)< 3
ORDER BY d.department_name;

