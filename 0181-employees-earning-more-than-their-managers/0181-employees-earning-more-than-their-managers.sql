# Write your MySQL query statement below
select e.name  as Employee
From Employee e
join Employee m
where e.managerId = m.id and e.salary>m.salary

 