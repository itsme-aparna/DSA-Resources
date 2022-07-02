# Write your MySQL query statement below
select name AS Customers
From Customers
Left join orders on orders.customerid = Customers.id
where orders.customerid is NULL;
