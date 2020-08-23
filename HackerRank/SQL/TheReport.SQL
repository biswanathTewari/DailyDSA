select  students.name , grades.grade ,students.marks
from students
inner join grades
on students.marks between grades.min_mark and grades.max_mark
where grades.grade > 7
order by grades.grade desc , students.name asc;

select  null , grades.grade , students.marks
from students
inner join grades
on students.marks between grades.min_mark and grades.max_mark
where grades.grade <= 7
order by grades.grade desc , students.marks asc
