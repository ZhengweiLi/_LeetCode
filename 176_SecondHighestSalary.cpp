/*
SQL Schema
Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the query should return 200
as the second highest salary. If there is no second highest salary,
then the query should return null.
*/
# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from Employee E1 where 1 =
(select count(distinct (E2.Salary) )from Employee E2 where E2.Salary > E1.Salary);
