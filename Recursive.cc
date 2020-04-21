#include <iostream>
#include <climits>
#include <algorithm>
#include "TreeNode.h"
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:

	/* Helper function that allocates a new node */
	TreeNode* newNode(int data) 
	{ 
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); 
		node->val = data; 
		node->left = node->right = NULL; 
		return (node); 
	} 

	/* Recursive function to construct binary of size n 
	   from  Inorder traversal in[] and Postorder traversal 
	   post[].  Initial values of inStrt and inEnd should 
	   be 0 and n -1.  The function doesn't do any error 
	   checking for cases where inorder and postorder 
	   do not form a tree */
	TreeNode* buildUtil(vector<int>& in, vector<int>& post, int inStrt, 
	                int inEnd, int& index) 
	{ 
	    // Base case 
	    if (inStrt > inEnd) 
	        return NULL; 
	  
	    /* Pick current node from Postorder traversal using 
	       postIndex and decrement postIndex */
		int curr = post[index];
	    TreeNode* node = newNode(post[index]); 
	    index--; 
	  
	    /* If this node has no children then return */
	    if (inStrt == inEnd) 
	        return node; 

    	/* Else find the index of this node in Inorder  
    	traversal */
    	int iIndex = mp[curr];
	  
	    /* Using index in Inorder traversal, construct left and 
	       right subtress */
	    node->right = buildUtil(in, post, iIndex + 1, inEnd, index); 
	    node->left = buildUtil(in, post, inStrt, iIndex - 1, index); 
	  
	    return node; 
	} 	

	TreeNode* buildUtil1(vector<int>& pre, vector<int>& in, int inStrt, 
	                int inEnd, int& index) 
	{
	    // Base case 
	    if (inStrt > inEnd) 
	        return NULL; 

	    /* Pick current node from Preorder traversal using 
	       preIndex and increment preIndex */
		int curr = pre[index];
	    TreeNode* node = newNode(pre[index]); 
	    index++; 

	    /* If this node has no children then return */
	    if (inStrt == inEnd) 
	        return node; 

    	/* Else find the index of this node in Inorder  
    	traversal */
    	int iIndex = mp[curr];

	    /* Using index in Inorder traversal, construct left and 
	       right subtress */
	    node->left = buildUtil1(pre, in, inStrt, iIndex - 1, index); 
	    node->right = buildUtil1(pre, in, iIndex + 1, inEnd, index); 

	}


	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();

    	// Store indexes of all items so that we 
    	// we can quickly find later 
    	for (int i = 0; i < n; i++) 
    	    mp[inorder[i]] = i; 

		int index = n-1;
	    m_root = buildUtil(inorder, postorder, 0, n - 1, index); 
		return m_root;
	}

	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();

    	for (int i = 0; i < n; i++) 
    	    mp[inorder[i]] = i; 

		int index = 0;
	    m_root = buildUtil1(preorder, inorder, 0, n - 1, index); 
		return m_root;

	}

	/* This funtcion is here just to test  */
	void preOrder(TreeNode* node) 
	{ 
	    if (node == NULL) 
	        return; 
	    printf("%d ", node->val); 
	    preOrder(node->left); 
	    preOrder(node->right); 
	} 

	// Top to Bottom
    bool hasPathSum(TreeNode* root, int sum) {
		if(root == NULL) return false;
        if (sum - root->val == 0 && (root->left == NULL && root->right == NULL) ) {
			g_isGot = true;
			return g_isGot;
		}
        
		if (!g_isGot && root->left != NULL)
			hasPathSum(root->left, sum - root->val);

		if (!g_isGot && root->right != NULL)
			hasPathSum(root->right, sum - root->val);

		return g_isGot;
    }

	// bottom to up.
	int maxPathSum(TreeNode* root) {
		int leftMax = INT_MIN;
		int rightMax = INT_MIN;
		if (root == NULL) return 0;

		if (!root->left && !root->right) return root->val;

		if (root->left)leftMax = maxPathSum(root->left);
		if (root->right)rightMax = maxPathSum(root->right);

		if (root->val < 0) {
			int tmpMax = max(leftMax, rightMax);
			if (root->val < tmpMax) return tmpMax;
			else return root->val;
		}

		if (leftMax<0) leftMax = 0;
		if (rightMax<0) rightMax = 0;

		int tempMaxSum = INT_MIN;
		if (root->val >= 0) {
			if (root->left && (root->left->val < 0 && root->left->val + root->val < 0 )) 
			{
				tempMaxSum = max(leftMax, rightMax + root->val);

			} else if (root->right && (root->right->val < 0 && root->right->val + root->val < 0))
			{
				tempMaxSum = max(rightMax, tempMaxSum);
			} else 
				tempMaxSum = root->val + leftMax + rightMax;
		}
		else if (root->val < 0)
		{
			if (rightMax > leftMax)
			{
				tempMaxSum = rightMax;
				if (root->val + leftMax > 0) tempMaxSum += root->val+leftMax;
			}else {
				tempMaxSum = leftMax;
				if (root->val + rightMax > 0) tempMaxSum += root->val+rightMax;
			}
		}

		return tempMaxSum;
	}


private:
	bool g_isGot = false;
	TreeNode* m_root;
	unordered_map<int, int> mp; 
};

void TestCase_buildTree1(){
	Solution sol;
	vector<int> vPreorder = {3,9,20,15,7};
	vector<int> vInorder = {9,3,15,20,7};

	TreeNode* root = sol.buildTree1(vPreorder, vInorder); 	
	cout << "Preorder of the constructed tree : \n"; 
    sol.preOrder(root); 

}

void TestCase_buildTree(){
	Solution sol;
	vector<int> vInorder = {9,3,15,20,7};
	vector<int> vPostorder = {9,15,7,20,3};

	TreeNode* root = sol.buildTree(vInorder, vPostorder); 	
	cout << "Preorder of the constructed tree : \n"; 
    sol.preOrder(root); 

}

void TestCase_maxPathSum(){
	Solution sol;
	TreeNode Node00(1);
	TreeNode Node10(2);
	TreeNode Node11(3);
	Node00.left = &Node10;
	Node00.right = &Node11;
	cout << "max:" << sol.maxPathSum(&Node00) << endl;
}

void TestCase_maxPathSum_4(){
	Solution sol;
	TreeNode Node00(1);
	TreeNode Node10(2);
	Node00.left = &Node10;
	cout << "max:" << sol.maxPathSum(&Node00) << endl;
}


void TestCase_maxPathSum_1(){
	Solution sol;
	TreeNode Node00(-10);
	TreeNode Node10(9);
	TreeNode Node11(20);
	TreeNode Node22(15);
	TreeNode Node23(7);

	Node00.left = &Node10;
	Node00.right = &Node11;
	Node11.left = &Node22;
	Node11.right = &Node23;
	//cout << "result expected: 42"  << endl;
	//cout << "max:" << sol.maxPathSum(&Node00) << endl;
	if (sol.maxPathSum(&Node00) == 42)
		cout << "True" << endl;
	else 
		cout << "False" << endl;

}

void TestCase_maxPathSum_55(){
    Solution sol;
	TreeNode Node00(5);
	TreeNode Node10(4);
	TreeNode Node11(8);
	TreeNode Node20(11);

	Node00.left = &Node10;
	Node00.right = &Node11;
	Node10.left = &Node20;

	TreeNode Node30(13);
	TreeNode Node31(4);
	TreeNode Node32(7);
	TreeNode Node33(2);

	Node11.left = &Node30;
	Node11.right = &Node31;
	Node20.left = &Node32;
	Node20.right = &Node33;

	TreeNode Node41(1);
	Node30.right = &Node41;

	int ret = sol.maxPathSum(&Node00);
	if (ret == 48)
		cout << "True" << endl;
	else {
		cout << "Actual:" << ret <<", expected: 48" <<  endl;
		cout << "False" << endl;
	}
	
}

void TestCase_maxPathSum_2(){
    Solution sol;
	TreeNode Node00(-2);
	TreeNode Node10(-1);
	Node00.left = &Node10;

	int ret = sol.maxPathSum(&Node00);
	if (ret == -1)
		cout << "True" << endl;
	else {
		cout << "Actual:" << ret <<", expected:" << -1 << endl;
		cout << "False" << endl;
	}
	
}

void TestCase_maxPathSum_3(){
	Solution sol;
	TreeNode Node00(1);
	TreeNode Node10(-2);
	TreeNode Node11(-3);
	Node00.left = &Node10;
	Node00.right = &Node11;
	
	TreeNode Node20(1);
	TreeNode Node21(3);
	TreeNode Node22(-2);
	Node10.left = &Node20;
	Node10.right = &Node21;
	Node11.left = &Node22;
	TreeNode Node30(-1);
	Node20.left = &Node30;

	if (sol.maxPathSum(&Node00) == 3)
		cout << "True" << endl;
	else 
	{
		cout << "Actual:" << sol.maxPathSum(&Node00) <<", expected:" << 3<< endl;
		cout << "False" << endl;
	}

}

void TestCase_hasPathSum_1(){
    Solution sol;
	TreeNode Node00(1);
	TreeNode Node10(2);
	Node00.left = &Node10;

	cout << "Yes/No: " << sol.hasPathSum(&Node00, 1) << endl;
	
}


void TestCase_hasPathSum(){
    Solution sol;
	TreeNode Node00(5);
	TreeNode Node10(4);
	TreeNode Node11(8);

	Node00.left = &Node10;
	Node00.right = &Node11;

	TreeNode Node20(11);
	Node10.left = &Node20;

	TreeNode Node22(13);
	TreeNode Node23(4);
	Node11.left = &Node22;
	Node11.right = &Node23;

	TreeNode Node30(7);
	TreeNode Node31(2);
	TreeNode Node37(1);

	Node20.left = &Node30;
	Node20.right = &Node31;
	Node23.right = &Node37;
	cout << "Yes/No: " << sol.hasPathSum(&Node00, 22) << endl;

}

int main(){
	//TestCase_hasPathSum_1();
	TestCase_maxPathSum_4();
	TestCase_maxPathSum_2();
	TestCase_maxPathSum_1();
	TestCase_maxPathSum();
	TestCase_maxPathSum_3();

	TestCase_maxPathSum_55();

	TestCase_buildTree();
	TestCase_buildTree1();
	return 0;
}
