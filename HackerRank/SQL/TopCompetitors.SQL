select h.hacker_id , h.name
from submissions as s
join challenges as c
on s.challenge_id = c.challenge_id
join difficulty as d
on c.difficulty_level = d.difficulty_level
join hackers as h
on s.hacker_id = h.hacker_id
where s.score = d.score and c.difficulty_level = d.difficulty_level
group by h.hacker_id
having count(s.hacker_id) > 1
order by count(s.hacker_id) desc , h.hacker_id asc
