select sum(city.population)
from city
inner join country
on city.countrycode = country.code
where country.continent = 'Asia'
