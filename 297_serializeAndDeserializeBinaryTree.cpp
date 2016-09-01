// Sourse : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Difficulty : Hard

/***********************************************************************
 *
 * Serialization is the process of converting a data structure or object 
 * into a sequence of bits so that it can be stored in a file or memory buffer, 
 * or transmitted across a network connection link to be reconstructed later 
 * in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. 
 * There is no restriction on how your serialization/deserialization algorithm should work. 
 * You just need to ensure that a binary tree can be serialized to a string 
 * and this string can be deserialized to the original tree structure.
 *
 **********************************************************************/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
class Codec {
private:
    TreeNode* deserializeHelper(istringstream& ss) {
        TreeNode* cur = nullptr;
        string word;
        if (ss >> word && word != "n") {
            cur = new TreeNode(stoi(word));
            cur->left = deserializeHelper(ss);
            cur->right = deserializeHelper(ss);
        }
        return cur;
    }
    
public:
    // 别闹了最简单的递归建树不是inorder吗，为何要作死呵呵（微笑）
    string serialize(TreeNode* root) {
    	if (!root) return "n ";
    	return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* deserialize(string data) {
        istringstream ss(data);
    	return deserializeHelper(ss);
    }
};