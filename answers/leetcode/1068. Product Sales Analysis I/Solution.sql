# Write your MySQL query statement below
SELECT product_name, year, price
    FROM Sales
    JOIN Product ON Sales.product_id = Product.product_id;