#include <stack>
#include <vector>
#include <iostream>
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
        return res;
    }
};

int main(){
    vector<int> res;
    vector<int> res1;
    Solution sol;
    TreeNode Node1(2);
    TreeNode Node2(3);
    TreeNode rootNode(1);

    rootNode.left = NULL;
    rootNode.right = &Node1;
    Node1.left = &Node2;
    Node1.right = NULL;

//  res = sol.preorderTraversal(&rootNode);
//
//  for (auto const& val: res)
//      cout << val << " ";
//
//  cout << endl;

    res1 = sol.postorderTraversal(&rootNode);
    for (auto const& val: res1)
        cout << val << " ";

	cout << endl;

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

    return 0;
}
