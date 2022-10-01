//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        stack<Node*> st;
        Node *temp = new Node(str[0]-'0');
        Node *parent;
        st.push(temp);
        for(int ind=1; ind<str.length(); ind++){
            if(str[ind] == '(')
                continue;
            if(str[ind] == ')'){
                st.pop();
                continue;
            }
            if(str[ind-1] != ')' && str[ind-1] != '('){
                st.top()->data = st.top()->data*10+(str[ind]-'0');
                continue;
            }
            temp = new Node(str[ind]-'0');
            parent = st.top();
            if(!parent->left){
                parent->left = temp;
            } else if(!parent->right){
                parent->right = temp;
            }
            st.push(temp);
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends