select city.name
from city
inner join country
on city.countrycode = country.code
where country.continent = 'Africa'
