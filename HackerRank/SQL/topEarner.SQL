select max(salary * months) as earning , count(*)
from employee
where salary*months = (select max(salary*months) from employee)
