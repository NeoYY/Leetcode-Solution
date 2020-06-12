/*
Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.

First Solution using having, second one use WHERE
*/

# Write your MySQL query statement below
    SELECT Email FROM Person GROUP BY Email
    HAVING COUNT( Email ) > 1;

# Write your MySQL query statement below
    SELECT Email FROM(
    SELECT Email, COUNT(Email) AS num FROM Person GROUP BY Email
        ) AS temp
    WHERE temp.num > 1;
