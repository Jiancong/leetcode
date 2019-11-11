#include <stack>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// 1) make an empty stack, and push the root node
	// 2) if stack is not empty, pop the node and print it out, 
	// 3) push the right node of top first
	// 4) push the left node of top second
	// NOTE: push the right first as make it pop out stack later than left.
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> res;

        // Base Case 
        if (root == NULL)
            return res;


        mystack.push(root);
        TreeNode* topNode=NULL;

        while( mystack.empty() == false )
        {
            topNode = mystack.top();
            res.push_back(topNode->val);

            mystack.pop();

            if (topNode->right!=NULL)
                mystack.push(topNode->right);

            if (topNode->left!=NULL)
                mystack.push(topNode->left);
        }
        return res;
    }

    /*
     * 1) Create an empty stack S.
     * 2) Initialize current node as root
     * 3) Push the current node to S and set current = current->left until current is NULL
     * 4) If current is NULL and stack is not empty then 
     *      a) Pop the top item from stack.
     *      b) Print the popped item, set current = popped_item->right 
     *      c) Go to step 3.
     *      5) If current is NULL and stack is empty then we are done.
     */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> res;

        // Base Case 
        if (root == NULL)
            return res;

        mystack.push(root);
        TreeNode* currentNode=root;
        bool isFirst=true;

        while( currentNode != NULL || mystack.empty() == false )
        {
            while( currentNode != NULL )
            {
                if (isFirst == false)
                    mystack.push(currentNode);

                currentNode = currentNode->left;
                isFirst = false;
            }

            if (currentNode == NULL && mystack.empty() == false)
            {
                TreeNode* popedNode = mystack.top();
                mystack.pop();
                res.push_back(popedNode->val);
                currentNode = popedNode->right;
            }
        }

        return res;
    }

	// 1. Push the root node to stack
	// 2. Move the pointer to the leftmost child, and push the node to stack
	//	  a) if it has the right child, go along with the next right child, and push node to stack
	//	  b) if it's the leaf node, pop the node and print the value, 
	//		 b1) leaf node is current node's left child, make right child as current node if existed, else 
	//			 make left child as NULL and make flag visited preventing re-stack the node.
	//		 b2) leaf node is current node's right child, just mark it as visited and null the right child.
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> res;

        // Base Case 
        if (root == NULL)
            return res;

        mystack.push(root);
        TreeNode* currentNode=root;
        bool isFirst = true;
        bool isVisited = false;
        while(currentNode != NULL && mystack.empty() == false ){

            if (isFirst == false && isVisited == false) {
                mystack.push(currentNode);
            } else {
                isFirst = false;
            }

            if (currentNode->left != NULL)
                currentNode=currentNode->left;
            else if (currentNode->right!= NULL)
                currentNode=currentNode->right;
            else {
                TreeNode* popedNode = NULL;
                if (mystack.empty() == false)
                {
                    popedNode = mystack.top();
                    res.push_back(popedNode->val);

                    mystack.pop();

                    if (mystack.empty() == false)
                    {
                        currentNode = mystack.top();
                        isVisited = false;
                        if (currentNode->left != NULL && currentNode->left->val == popedNode->val)
                        {
                            if (currentNode->right != NULL)
                                currentNode = currentNode->right ;
                            else
                            {
                                currentNode->left = NULL;
                                isVisited = true;
                            }
                        }
                        else if (currentNode->right != NULL && currentNode->right->val == popedNode->val)
                        {
                            currentNode->right = NULL;
                            isVisited = true;
                        }
                    }
                }
            }
        }
    }

	vector<vector<int> > levelOrder(TreeNode* root) {
		vector<vector<int> > result;	// returned data
        queue<TreeNode*> myqueue;		// BFS used queue 
		map<TreeNode*, int> mymap;		// TreeNode to its level depth
		map<int, vector<int> > mymap2;	// record the depth level and node list

		int maxDepth = 0;				// record how deep our tree is

		TreeNode* currentNode = root;

		if (currentNode != NULL ) {
			myqueue.push(currentNode);

			vector<int> res;
			res.push_back(currentNode->val);

			mymap.emplace(make_pair(currentNode, 0));
			mymap2.emplace(make_pair(0, res));
		} else return result;

		while(myqueue.empty() == false)
		{
			currentNode = myqueue.front();
			myqueue.pop();

			int parent_level = 0;
			map<TreeNode*, int>::iterator it = mymap.find(currentNode);
			if (it != mymap.end())
				parent_level = it->second;

			if (currentNode->left != NULL)
			{
				map<TreeNode*, int>::iterator it = mymap.find(currentNode->left);
				if (it == mymap.end())
				{
					vector<int> res;
					myqueue.push(currentNode->left);

					mymap.emplace(make_pair(currentNode->left, parent_level+1));
					
					map<int, vector<int> >::iterator it2 = mymap2.find(parent_level + 1);
					if (it2 == mymap2.end())
					{
						res.push_back(currentNode->left->val);
						mymap2.emplace(make_pair(parent_level + 1, res));
					} else {
						it2->second.push_back(currentNode->left->val);
					}

					if (parent_level+1 > maxDepth) maxDepth = parent_level+1;
				}

			}

			if (currentNode->right != NULL) {
				map<TreeNode*, int>::iterator it = mymap.find(currentNode->right);
				if (it == mymap.end())
				{
					vector<int> res;
					myqueue.push(currentNode->right);

					mymap.emplace(make_pair(currentNode->right, parent_level+1));

					map<int, vector<int> >::iterator it2 = mymap2.find(parent_level + 1);
					if (it2 == mymap2.end())
					{
						res.push_back(currentNode->right->val);
						mymap2.emplace(make_pair(parent_level + 1, res));
					} else {
						it2->second.push_back(currentNode->right->val);
					}

					if (parent_level+1 > maxDepth) maxDepth = parent_level+1;
				}
			}
		}

		for (int i = 0; i <= maxDepth; i++)
		{
			map<int, vector<int> >::iterator it = mymap2.find(i);
			result.push_back(it->second);
		}

		return result;
	}
};

void TestCase_BFS(){
	TreeNode root(3);
	TreeNode N1(9);
	TreeNode N2(20);
	TreeNode N3(15);
	TreeNode N4(7);
	root.left = &N1;
	root.right = &N2;
	N2.left = &N3;
	N2.right = &N4;
	Solution sol;

	vector<vector<int> > result;

	result = sol.levelOrder(&root) ;

	cout << "result size:" << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[ "  ;
		vector<int> inner = result[i];
		for (int j = 0; j < inner.size(); j++)
			cout << inner[j] << ",";
		cout << "] " ;
		cout << endl;
	}

}

void TestCase_PreoderTraversal(){
    vector<int> res;
    Solution sol;
    TreeNode Node1(2);
    TreeNode Node2(3);
    TreeNode rootNode(1);

    rootNode.left = NULL;
    rootNode.right = &Node1;
    Node1.left = &Node2;
    Node1.right = NULL;
  
    res = sol.preorderTraversal(&rootNode);
  
    for (auto const& val: res)
        cout << val << " ";
  
    cout << endl;

}

void TestCase_post()
{
    vector<int> res1;
    Solution sol;
    TreeNode Node11(1);
    TreeNode Node22(2);
    TreeNode rootNode1(3);

    rootNode1.left = &Node11;
    rootNode1.right = &Node22;
    Node11.left = NULL;
    Node11.right = NULL;
    Node22.left = NULL;

    Node22.right = NULL;

    res1 = sol.postorderTraversal(&rootNode1);
    for (auto const& val: res1)
        cout << val << " ";

    cout << endl;
}

int main(){
	TestCase_BFS();

    return 0;
}
