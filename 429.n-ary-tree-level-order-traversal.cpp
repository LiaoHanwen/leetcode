/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (62.66%)
 * Likes:    562
 * Dislikes: 46
 * Total Accepted:    73.8K
 * Total Submissions: 114.5K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [[1],[3,2,4],[5,6]]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        vector<int> t;

        while (!q.empty())
        {
            Node *n = q.front();
            if (n == nullptr)
            {
                if (t.size() == 0)
                    break;

                res.push_back(t);
                t.clear();
                q.push(nullptr);
            }
            else
            {
                t.push_back(n->val);
                for (auto p = n->children.begin(); p != n->children.end(); p++)
                {
                    q.push(*p);
                }
            }

            q.pop();
        }

        return res;
    }
};
// @lc code=end
