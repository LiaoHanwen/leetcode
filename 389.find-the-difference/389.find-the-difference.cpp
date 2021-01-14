/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (54.33%)
 * Likes:    762
 * Dislikes: 279
 * Total Accepted:    192.9K
 * Total Submissions: 351K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 
 * Given two strings s and t which consist of only lowercase letters.
 * 
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 * 
 * Find the letter that was added in t.
 * 
 * Example:
 * 
 * Input:
 * s = "abcd"
 * t = "abcde"
 * 
 * Output:
 * e
 * 
 * Explanation:
 * 'e' is the letter that was added.
 * 
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        map<char, int> m;
        for (size_t i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        for (size_t i = 0; i < t.size(); i++)
        {
            m[t[i]]--;
            if (m[t[i]] < 0)
                return t[i];
        }

        return '0';
    }
};
// @lc code=end