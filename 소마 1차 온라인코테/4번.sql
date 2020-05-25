
SELECT stage, ROUND(AVG(student_num)) as student_avg, ROUND(SUM(student_num)/SUM(teacher_num), 1) as teacher_avg 
FROM SCHOOLS
GROUP BY stage
ORDER BY student_avg DESC, teacher_avg ASC