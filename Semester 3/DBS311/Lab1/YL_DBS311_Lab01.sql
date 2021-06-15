-- 1.
SELECT TO_CHAR(SYSDATE+2, 'fmMonth" "ddth" of year "YYYY') "After Tomorrow"
FROM DUAL;

-- 2.
SELECT last_name, first_name, salary, ROUND(salary*1.07, 1) AS "Good Salary",
salary*0.07*12 "Annual Pay Increase"
FROM employee
WHERE department_id IN (50, 60);

-- 3.
SELECT UPPER(last_name)||', '||UPPER(first_name)||' is '||
       DECODE(job_id ,'ST_CLERK', 'Store Clerk',
                      'ST_MAN', 'Store Manager')"Person and Job"
FROM employee
WHERE last_name LIKE '%s' AND (first_name LIKE 'C%' OR first_name LIKE 'K%')
ORDER BY last_name;

-- 4.
SELECT last_name, salary, hire_date, 
ROUND((SYSDATE-hire_date) / 365) "Years Worked"
FROM employee
WHERE hire_date < TO_DATE('01-Jan-1992', 'DD-Mon-YYYY') AND salary > 10000
ORDER BY 2 DESC, 4 DESC;

-- 5.
SELECT city, country_id, nvl(state_province, TO_CHAR('Unknown Province')) "State Province"
FROM location
WHERE city LIKE 'S%' AND LENGTH(city) >= 8;

-- 6.
SELECT last_name, hire_date, 
TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date, 12), 'Tuesday'), 'fmDAY, Month "the" Ddspth "of year"YYYY') "REVIEW DAY"
FROM employee
WHERE hire_date > TO_DATE('31-Dec-1997', 'DD-Mon-YYYY');
