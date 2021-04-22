CREATE TABLE inventory(
product_id     NUMBER(*,0)   PRIMARY KEY,
product_name   VARCHAR2(100) NOT NULL              UNIQUE,
last_procured  DATE          DEFAULT (SYSDATE - 1) NOT NULL,
stock_quantity NUMBER(3,0)   DEFAULT 1,
cost_per_piece NUMBER(5,2),
perishable     VARCHAR2(1)
CHECK (perishable IN ('Y','N')));

CREATE TABLE invoices(
invoice_number VARCHAR2(20),
product_id     NUMBER(*,0) REFERENCES inventory(product_id) ON DELETE CASCADE,
quantity_sold  NUMBER(3,0) DEFAULT 1 NOT NULL CHECK (quantity_sold > 0),
rate           NUMBER(5,2) NOT NULL,
payment_type   VARCHAR2(30),
CONSTRAINT pk_invoices
PRIMARY KEY(invoice_number, product_id));

--Using Old Syntax
CREATE OR REPLACE VIEW vw_inventory_invoices AS
SELECT io.invoice_number,
       ie.product_id,
       ie.product_name,
       TO_CHAR(last_procured,'Day, DD Mon, YYYY') AS last_procured,
       ie.cost_per_piece * io.quantity_sold AS total_cost_price,
       io.rate * io.quantity_sold AS total_selling_price
FROM inventory ie,
     invoices io
WHERE ie.product_id = io.product_id
AND ie.cost_per_piece IS NOT NULL;

--Using New Syntax with ON
CREATE OR REPLACE VIEW vw_inventory_invoices AS
SELECT io.invoice_number,
       ie.product_id,
       ie.product_name,
       TO_CHAR(last_procured,'Day, DD Mon, YYYY') AS last_procured,
       ie.cost_per_piece * io.quantity_sold AS total_cost_price,
       io.rate * io.quantity_sold AS total_selling_price
FROM inventory ie JOIN invoices io
ON ie.product_id = io.product_id
WHERE ie.cost_per_piece IS NOT NULL;

--Using New Syntax with USING
CREATE OR REPLACE VIEW vw_inventory_invoices AS
SELECT invoice_number,
       product_id,
       product_name,
       TO_CHAR(last_procured, 'Day, DD Mon, YYYY') AS last_procured,
       (cost_per_piece * quantity_sold) AS total_cost_price,
       (rate * quantity_sold) AS total_selling_price
FROM inventory JOIN invoices
USING (product_id)
WHERE cost_per_piece IS NOT NULL;