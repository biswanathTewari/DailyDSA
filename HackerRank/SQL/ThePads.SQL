select concat(name,'(',left(occupation,1),')') from occupations
order by name asc;
select concat('There are a total of',' ',count(occupation),' ',lower(occupation),'s.') as total from occupations
group by occupation
order by total
