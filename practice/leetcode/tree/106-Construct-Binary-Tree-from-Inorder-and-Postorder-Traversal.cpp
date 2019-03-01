#include <cstdio>
#include <vector>

using namespace std;

/**
 * 问题:
 * 给定一棵二叉树的中序遍历和后序遍历（每个数字不同），重建这棵树。
 */

/**
 * HINT:
 * 后序遍历的最后一个数字为根节点，
 * 在中序遍历的序列中找到这个根节点的位置，
 * 可以得到根节点的左子树和右子树的中序遍历和后序遍历的序列，递归子问题即可。
 */


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  vector<int> inorder;
  vector<int> postorder;

  int find_inorder(int start, int length, int target) {
    for (int i = 0; i < length; i++) {
      if (inorder[i + start] == target) {
        return i + start;
      }
    }
    return -1;
  }

  TreeNode* build_node(int in_start, int post_start, int length) {
    if (length <= 0) {
      return NULL;
    }

    int val = postorder[post_start + length - 1];
    TreeNode* root = new TreeNode(val);

    int index = find_inorder(in_start, length, val);
    int left_length = index - in_start;
    int right_length = length - left_length - 1;
    root->left = build_node(in_start, post_start, left_length);
    root->right = build_node(index + 1, post_start + length - 1 - right_length, right_length);

    return root;
  }

public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    this->inorder = inorder;
    this->postorder = postorder;

    return build_node(0, 0, inorder.size());
  }
};

int main() {

  vector<int> inorder = {4, 2, 10, 5, 1, 8, 6, 9, 3, 7};
  vector<int> postorder = { 4, 10, 5, 2, 8, 9, 6, 7, 3, 1};
  TreeNode* root = Solution().buildTree(inorder, postorder);

  return 0;
}
