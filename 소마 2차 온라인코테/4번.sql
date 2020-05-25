SELECT name, COUNT(*) as comment_num
FROM users JOIN comments ON (users.id=comments.user_id)
GROUP BY users.name
ORDER BY comment_num DESC, name DESC
LIMIT 3;