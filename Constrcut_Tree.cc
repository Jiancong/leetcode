#include <iostream>
#include <vector>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

void inorderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->val << ' ' ;
	inorderTraversal(root->right);
}


void preorderTraversal(TreeNode* root)
{
	if (root == nullptr)
		return;

	cout << root->val << ' ' ;
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Recursive function to construct a binary tree from given
// inorder and preorder sequence
TreeNode* construct(int start, int end,
					vector<int> const& preorder,
					int &pIndex, 
					unordered_map<int, int> &map)
{
	// base case
	if (start > end)
		return nullptr;

	// The next element in preorder[] will be the root node of
	// subtree formed by inorder[start, end]
	TreeNode *root = new TreeNode(preorder[pIndex++]);

	// get the index of root node in inorder[] to determine the
	// boundary of left and right subtree
	int index_of_root = map[root->val];

	// recursively construct the left subtree
	root->left = construct(start, index_of_root - 1, preorder, pIndex, map);

	// recursively construct the right subtree
	root->right = construct(index_of_root +1, end, preorder, pIndex, map);

	// return current node
	return root;
}

// Construct a binary tree from inorder and preorder traverial
// This function assumes that the input is valid
// i.e. given inorder and preorder sequence forms a binary tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	// get number of nodes in the tree
	int n = inorder.size();

	// create a map to efficiently find the index of any element in 
	// given inorder sequence
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
		map[inorder[i]] = i;

	// pIndex stores index of next unprocessed node in 
	// preorder sequence start with root node 
	// (present at 0'th index)
	int pIndex = 0;
	return construct(0, n-1, preorder, pIndex, map);
}

int main(){
	vector<int> inorder = {4,2,1,7,5,8,3,6};
	vector<int> preorder = {1,2,4,3,5,7,8,6};

	TreeNode* root=buildTree(preorder, inorder);

	cout << "inorder : ";
	inorderTraversal(root);

	cout << "\nPreorder : ";
	preorderTraversal(root);

	return 0;

}
