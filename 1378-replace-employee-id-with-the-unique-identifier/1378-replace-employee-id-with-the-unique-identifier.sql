/* Write your PL/SQL query statement below */
select Em.unique_id,E.name from Employees E left join EmployeeUNI Em on E.id=Em.id; 