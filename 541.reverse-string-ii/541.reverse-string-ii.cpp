/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (47.42%)
 * Likes:    433
 * Dislikes: 1236
 * Total Accepted:    89.2K
 * Total Submissions: 184.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        string res;
        bool re = true;
        for (int i = 0; i < s.size(); i += k)
        {
            if (re)
            {
                reverse(s.begin() + i, i + k > s.size() ? s.end() : s.begin() + i + k);
            }

            re = !re;
        }

        return s;
    }
};
// @lc code=end
