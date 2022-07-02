# Write your MySQL query statement below
select name AS Customers
From Customers
Left join orders on Customers.id = orders.customerid
where orders.customerid is NULL;
