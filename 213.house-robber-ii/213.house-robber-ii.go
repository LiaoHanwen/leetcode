/*
 * @lc app=leetcode id=213 lang=golang
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (35.96%)
 * Likes:    1423
 * Dislikes: 44
 * Total Accepted:    155.5K
 * Total Submissions: 431.3K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */

// @lc code=start
func rob(nums []int) int {
	
	if len(nums) == 0 {
		return 0
	}

	if len(nums) == 1 {
		return nums[0]
	}

	max := func(x, y int) int {
		if x > y {
			return x
		}

		return y
	}

	r := func(n []int) int {
		if len(n) == 1 {
			return n[0]
		}

		ll := n[0]
		l := max(n[1], n[0])
		for i := 2; i < len(n); i++ {
			t := max(ll + n[i], l)
			ll = l
			l = t
		}

		return l
	}

	return max(r(nums[1:]), r(nums[:len(nums)-1]))
}
// @lc code=end

