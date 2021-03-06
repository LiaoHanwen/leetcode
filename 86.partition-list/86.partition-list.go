/*
 * @lc app=leetcode id=86 lang=golang
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (39.75%)
 * Likes:    996
 * Dislikes: 258
 * Total Accepted:    195.6K
 * Total Submissions: 491.6K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	s := &ListNode{}
	b := &ListNode{}
	sp := s
	bp := b

	for head != nil {
		if head.Val < x {
			sp.Next = head
			sp = sp.Next
		} else {
			bp.Next = head
			bp = bp.Next
		}

		head = head.Next
	}

	sp.Next = b.Next
	bp.Next = nil
	return s.Next
}
// @lc code=end

