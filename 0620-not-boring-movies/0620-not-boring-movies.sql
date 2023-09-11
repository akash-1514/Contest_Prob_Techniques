# Write your MySQL query statement below
select * from cinema where mod(id, 2) != 0 && description != "boring" order by rating desc;