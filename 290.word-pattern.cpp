/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (36.32%)
 * Likes:    1007
 * Dislikes: 144
 * Total Accepted:    182K
 * Total Submissions: 496.8K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        map<char, string> m;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (str.size() == 0)
                return false;
            int pos = str.find(' ');
            string s;
            if (pos == string::npos)
            {
                s = str;
                str = "";
            }
            else
            {
                s = str.substr(0, pos);
                str = str.substr(pos + 1);
            }

            auto p = m.find(pattern[i]);
            if (p == m.end())
            {
                m[pattern[i]] = s;
            }
            else
            {
                if (m[pattern[i]] != s)
                {
                    return false;
                }
            }

            for (auto it = m.begin(); it != m.end(); ++it)
                if (it->second == s && it->first != pattern[i])
                    return false;
        }

        return str.size() == 0;
    }
};
// @lc code=end
