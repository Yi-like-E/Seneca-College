----- CREATE TABLE -----
CREATE TABLE Customer(
  customerNum INT PRIMARY KEY,
  lastName VARCHAR2(50) NOT NULL,
  firstName VARCHAR2(50) NOT NULL,
  DoB DATE,
  streetAddress VARCHAR2(50) NOT NULL,
  city VARCHAR2(50) NOT NULL,
  province VARCHAR2(50) NOT NULL,
  zip VARCHAR2(50) NOT NULL,
  phoneNum VARCHAR2(50) NOT NULL,
  email VARCHAR2(50) NOT NULL UNIQUE
);

CREATE TABLE A2_Order(
  orderNum INT PRIMARY KEY,
  customerNum INT,
  orderDate DATE,
  orderTotal NUMBER(5,2) CHECK(orderTotal > 0) NOT NULL,
  CONSTRAINT customerNum_Order_FK FOREIGN KEY(customerNum) REFERENCES Customer(customerNum)
);

CREATE TABLE Payment(
  cardNum INT PRIMARY KEY,
  orderNum INT,
  cardHolderName VARCHAR2(50) NOT NULL,
  expiryDate DATE,
  cardType VARCHAR2(50) CHECK(cardType IN ('VISA', 'MAST', 'AMEX')),
  CONSTRAINT orderNum_Payment_FK FOREIGN KEY(orderNum) REFERENCES A2_Order(orderNum)
);

CREATE TABLE Label(
  labelID INT PRIMARY KEY,
  labelName VARCHAR2(25) NOT NULL,
  url VARCHAR2(50)
);

CREATE TABLE Category(
  categoryID INT PRIMARY KEY,
  catDescription VARCHAR2(25)
  CONSTRAINT check_catDescription
  CHECK (catDescription IN ('R'||'&'||'B', 'Jazz', 'Metal Rock', 'Alt Rock', 'Easy Rock', 'Classic Rock', 'Hip-Hop'))
);

CREATE TABLE Recording(
  recordingID INT PRIMARY KEY,
  categoryID INT,
  labelID INT,
  performerName VARCHAR2(25) NOT NULL,
  title VARCHAR2(25) NOT NULL,
  sellPrice NUMBER NOT NULL,
  stockQuantity INT NOT NULL,
  CONSTRAINT categoryID_Recording_FK FOREIGN KEY (categoryID) REFERENCES Category(categoryID),
  CONSTRAINT labelID_Recording_FK FOREIGN KEY (labelID) REFERENCES Label(labelID)
);

CREATE TABLE OrderLine(
  orderlineNum INT PRIMARY KEY,
  orderNum INT,
  recordingID INT,
  price NUMBER(5,2) CHECK(price > 0 AND 1000 > price) NOT NULL,
  quantityOrdered NUMBER CHECK(quantityOrdered >= 0) NOT NULL,
  CONSTRAINT orderNum_OrderLine_FK FOREIGN KEY(orderNum) REFERENCES A2_Order(orderNum),
  CONSTRAINT recordingID_OrderLine_FK FOREIGN KEY(recordingID) REFERENCES Recording(recordingID)
);

CREATE TABLE Recording_History (
  priceNum  NUMBER PRIMARY KEY,
  recordingID INT, 
  price NUMBER(5,2) CHECK(0 < price AND price < 1000.00) NOT NULL,
  startDate DATE NOT NULL,
  CONSTRAINT recordingID_RH_FK FOREIGN KEY(recordingID) REFERENCES Recording(recordingID)
);

CREATE TABLE Sales_Rep (
  repNum  NUMBER PRIMARY KEY,
  labelID INT, 
  lastName VARCHAR2(30) NOT NULL,
  firstName VARCHAR2(30) NOT NULL,
  phoneNum VARCHAR2(20) NOT NULL,
  email VARCHAR2(50) NOT NULL UNIQUE,
  CONSTRAINT labelID_SalesRep_FK FOREIGN KEY(labelID) REFERENCES Label(labelID)
);

CREATE TABLE Region (
  regionID  INT PRIMARY KEY,
  repNum NUMBER, 
  regionName VARCHAR2(30) NOT NULL,
  CONSTRAINT repNum_Region_FK FOREIGN KEY(repNum) REFERENCES Sales_Rep(repNum)
);

----- INSERT DATA -----
INSERT ALL
  INTO Customer VALUES (1, 'Sanghwa', 'Suh', to_date('07-JUN-91','DD-MON-RR'), '12 ad', 'Toronto', 'Ontario', '1A1', '516-111-2222', 'sanghwa@gmail.com')
  INTO Customer VALUES (2, 'Adam', 'Springett', to_date('07-JUN-92','DD-MON-RR'), '34 cd', 'York', 'Ontario', '2B2', '616-222-3333', 'adam@gmail.com')
  INTO Customer VALUES (3, 'Nozomi', 'Tuschiya', to_date('17-SEP-93','DD-MON-RR'), '56 ef', 'Peel', 'Ontario', '3C3', '716-333-4444', 'nozomi@gmail.com')
  INTO Customer VALUES (4, 'Yihsun', 'Lee', to_date('17-JUN-94','DD-MON-RR'), '78 gh', 'Muskoka', 'Ontario', '4D4', '816-444-5555', 'yihsun@gmail.com')
  INTO Customer VALUES (5, 'Chirs', 'OOP',to_date('13-JAN-95','DD-MON-RR'), '90 ij', 'Niagara', 'Ontario', '5E5', '916-555-6666', 'chris@gmail.com')
  SELECT * FROM dual;

INSERT ALL
  INTO A2_Order VALUES (1, 1, to_date('01-JAN-16','DD-MON-RR'), 10)
  INTO A2_Order VALUES (2, 2, to_date('02-FEB-17','DD-MON-RR'), 20)
  INTO A2_Order VALUES (3, 3, to_date('03-MAR-18','DD-MON-RR'), 30)
  INTO A2_Order VALUES (4, 4, to_date('04-APR-19','DD-MON-RR'), 40)
  INTO A2_Order VALUES (5, 1, to_date('05-MAY-20','DD-MON-RR'), 50)
  SELECT * FROM dual;

INSERT ALL
  INTO Payment VALUES (100, 1, 'Sanghwa', to_date('20-JUN-25','DD-MON-RR'), 'VISA')
  INTO Payment VALUES (200, 2, 'Adam', to_date('21-JUL-26','DD-MON-RR'), 'MAST')
  INTO Payment VALUES (300, 3, 'Nozomi', to_date('22-AUG-27','DD-MON-RR'), 'VISA')
  INTO Payment VALUES (400, 4, 'Yihsun', to_date('23-SEP-28','DD-MON-RR'), 'MAST')
  INTO Payment VALUES (500, 5, 'Sanghwa', to_date('24-OCT-29','DD-MON-RR'), 'AMEX')
  SELECT * FROM dual;

INSERT ALL
  INTO Label VALUES (1, 'Sony', 'www.sonymusic.com')
  INTO Label VALUES (2, 'Warner', 'www.warnermusic.com')
  INTO Label VALUES (3, 'Universal', 'www.universalmusic.com')
  INTO Label VALUES (4, 'EMI', 'www.emimusic.com')
  INTO Label VALUES (5, 'BMG', 'www.bmgmusic.com')
  SELECT * FROM dual;

INSERT ALL
  INTO Category VALUES (010, 'R'||'&'||'B')
  INTO Category VALUES (020, 'Jazz')
  INTO Category VALUES (030, 'Metal Rock')
  INTO Category VALUES (040, 'Alt Rock')
  INTO Category VALUES (050, 'Easy Rock')
  INTO Category VALUES (060, 'Classic Rock')
  INTO Category VALUES (070, 'Hip-Hop')
  SELECT * FROM dual;

INSERT ALL
  INTO Recording VALUES (1, 070, 5, 'Beyonce', 'Lemonade', 25.00, 150)
  INTO Recording VALUES (2, 010, 4, 'Emotional Oranges', 'The Juicebox', 20.50, 60)
  INTO Recording VALUES (3, 040, 3, 'LANY', 'I loved you', 20.50, 80)
  INTO Recording VALUES (4, 010, 2, 'Lauv', 'Without you', 15.85, 100)
  INTO Recording VALUES (5, 030, 1, 'Bazzi', 'Cosmic', 20.50, 75)
  SELECT * FROM dual;

INSERT ALL
  INTO Recording_History VALUES(001, 1, 11.25, TO_DATE('2020-01-01', 'YYYY-MM-DD'))
  INTO Recording_History VALUES(002, 2, 12.50, TO_DATE('2020-02-01', 'YYYY-MM-DD'))
  INTO Recording_History VALUES(003, 3, 13.75, TO_DATE('2020-03-01', 'YYYY-MM-DD'))
  INTO Recording_History VALUES(004, 4, 14.00, TO_DATE('2020-04-01', 'YYYY-MM-DD'))
  INTO Recording_History VALUES(005, 5, 15.15, TO_DATE('2020-05-01', 'YYYY-MM-DD'))
  SELECT * FROM dual;

INSERT ALL
  INTO Sales_Rep VALUES(101, 1, 'Leon', 'Kennedy', '416-111-2222', 'l.kennedy@gmail.com')
  INTO Sales_Rep VALUES(102, 2, 'Chris', 'Redfield', '416-222-3333', 'c.redfield@gmail.com')
  INTO Sales_Rep VALUES(103, 3, 'Claire', 'Redfield', '416-333-4444', 'claire.r@gmail.com')
  INTO Sales_Rep VALUES(104, 4, 'Jill', 'Valentine', '416-444-5555', 'j.valentine@gmail.com')
  INTO Sales_Rep VALUES(105, 5, 'Ada', 'Wong', '416-555-6666', 'a.wong@gmail.com')
  SELECT * FROM dual;
  
INSERT ALL
  INTO Region VALUES(1111, 101, 'Toronto')
  INTO Region VALUES(2222, 102, 'York')
  INTO Region VALUES(3333, 103, 'Peel')
  INTO Region VALUES(4444, 104, 'Muskoka')
  INTO Region VALUES(5555, 105, 'Niagara')
  SELECT * FROM dual;
  
INSERT ALL
  INTO OrderLine VALUES (101, 1, 1, 25.00, 10)
  INTO OrderLine VALUES (102, 2, 2, 20.50, 20)
  INTO OrderLine VALUES (103, 3, 3, 20.50, 30)
  INTO OrderLine VALUES (104, 4, 4, 15.85, 40)
  INTO OrderLine VALUES (105, 5, 5, 20.50, 50)
  SELECT * FROM dual; 

-----Part 3 procedure-----
SET SERVEROUTPUT ON;
CREATE OR REPLACE PROCEDURE Recording_Selling_Price_Report AS
high INT :=0;
low INT :=0;
same INT :=0;
avgsell recording.sellprice%type;
sell recording.sellprice%type;
catID recording.categoryID%type;
CURSOR sellcursor IS
    SELECT AVG(r2.sellprice), r1.categoryid, r1.sellprice
    FROM recording r1
    JOIN recording r2
    ON r2.categoryid = r1.categoryid
    GROUP BY r1.categoryid, r1.sellprice;

BEGIN   
OPEN sellcursor;

LOOP
    FETCH sellcursor into avgsell, catid, sell;
    EXIT WHEN sellcursor%notfound; 
    
        IF  sell > avgsell THEN
            high := high + 1;
        ELSIF sell < avgsell THEN
            low := low + 1;
        ELSIF sell = avgsell THEN
            same := same + 1;
        END IF;
 
    END LOOP;
    CLOSE sellcursor;

    DBMS_OUTPUT.PUT_LINE('Total of High Recordings: ' || high);
    DBMS_OUTPUT.PUT_LINE('Total of Low Recordings: ' || low);
    DBMS_OUTPUT.PUT_LINE('Total of Recordings Equal to Average: ' || same);
END;
/
execute Recording_Selling_Price_Report;

--DROP TABLE Cutomer CASCADE CONSTRAINTS;
--DROP TABLE A2_Order CASCADE CONSTRAINTS;
--DROP TABLE Payment CASCADE CONSTRAINTS;
--DROP TABLE OrderLine CASCADE CONSTRAINTS;
--DROP TABLE Label CASCADE CONSTRAINTS;
--DROP TABLE Category CASCADE CONSTRAINTS;
--DROP TABLE Recording CASCADE CONSTRAINTS;
--DROP TABLE Recording_History CASCADE CONSTRAINTS;
--DROP TABLE Sales_Rep CASCADE CONSTRAINTS;
--DROP TABLE Region CASCADE CONSTRAINTS;