/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (38.86%)
 * Likes:    918
 * Dislikes: 59
 * Total Accepted:    66.3K
 * Total Submissions: 168.4K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        auto p = nums.begin() + 1;
        int ac = 0;
        int res = 1;

        while (p != nums.end())
        {
            if (*p - *(p - 1) == 0)
            {
                p++;
                continue;
            }

            if (ac == 0 || (*p - *(p - 1)) * ac < 0)
            {
                res++;
                ac = *p - *(p - 1);
            }

            p++;
        }

        return res;
    }
};
// @lc code=end
