# Write your MySQL query statement below
SELECT name
    FROM SalesPerson
    WHERE name NOT IN
    (
        SELECT SalesPerson.name
            FROM SalesPerson
            LEFT JOIN Orders ON SalesPerson.sales_id = Orders.sales_id
            LEFT JOIN Company ON Orders.com_id = Company.com_id
            WHERE Company.name = 'Red'
    );