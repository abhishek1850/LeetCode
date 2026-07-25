# Write your MySQL query statement below


select email as Email 
from Person 
group by email
having count(*)>1
-- select distinct e.email as Email from Person as e 
-- where e.email in (
--   select p.email from Person as p
--   where p.id != e.id
-- ) 