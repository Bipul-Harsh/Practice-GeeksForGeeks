//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void build_traversal(Node *ptr, vector<vector<int>>&t, int level=0){
        if(level >= t.size()){
            t.push_back({ptr->data});
        } else {
            t[level].push_back(ptr->data);
        }
        if(ptr->left)
            build_traversal(ptr->left, t, level+1);
        if(ptr->right)
            build_traversal(ptr->right, t, level+1);
    }
    
    bool areAnagrams(Node *root1, Node *root2)
    {
        vector<vector<int>>t1;
        vector<vector<int>>t2;
        
        build_traversal(root1, t1);
        build_traversal(root2, t2);

        if(t1.size() != t2.size())
            return false;
        
        for(int ind=0; ind<t1.size(); ind++){
            if(t1[ind].size() != t2[ind].size())
                return false;
            sort(t1[ind].begin(), t1[ind].end());
            sort(t2[ind].begin(), t2[ind].end());
            for(int sind=0; sind<t1[ind].size(); sind++){
                if(t1[ind][sind] != t2[ind][sind]){
                    return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends