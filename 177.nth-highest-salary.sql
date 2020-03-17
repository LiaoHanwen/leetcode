--
-- @lc app=leetcode id=177 lang=mysql
--
-- [177] Nth Highest Salary
--
-- https://leetcode.com/problems/nth-highest-salary/description/
--
-- database
-- Medium (29.76%)
-- Likes:    352
-- Dislikes: 301
-- Total Accepted:    97K
-- Total Submissions: 325.2K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "argument": 2, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
--
-- Write a SQL query to get the n^th highest salary from the Employee table.
--
--
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
--
--
-- For example, given the above Employee table, the n^th highest salary where n
-- = 2 is 200. If there is no n^th highest salary, then the query should return
-- null.
--
--
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
--
--
--
-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN DECLARE M INT;
SET
  M = N -1;
RETURN (
    # Write your MySQL query statement below.
    SELECT
      (
        SELECT
          DISTINCT Salary
        FROM Employee
        ORDER BY
          Salary DESC
        LIMIT
          1 OFFSET M
      ) AS SecondHighestSalary
  );
END 
-- @lc code=end