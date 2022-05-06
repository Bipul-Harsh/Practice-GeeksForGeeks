// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    
    void lvlTraverse(vector< pair<Node*, int> >lvl, int &min, int&max,
        unordered_map<int, vector<int>>&record){
        if(!lvl.size())
            return;
        vector<pair<Node*, int>> new_lvl;
        pair<int, int>n_info;
        int pos;
        for(int ind=0; ind<lvl.size(); ind++){
            record[lvl[ind].second].push_back(lvl[ind].first->data);
            if(lvl[ind].first->left){
                pos = lvl[ind].second-1;
                if(pos<min)
                    min = pos;
                new_lvl.push_back(make_pair(lvl[ind].first->left, pos));
            }
            if(lvl[ind].first->right){
                pos = lvl[ind].second+1;
                if(pos>max)
                    max = pos;
                new_lvl.push_back(make_pair(lvl[ind].first->right, pos));
            }
        }
        lvlTraverse(new_lvl, min, max, record);
    }
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        vector< pair<Node*, int> >lvl;
        unordered_map<int, vector<int>>record;
        int min=0;
        int max=0;
        lvl.push_back(make_pair(root, 0));
        lvlTraverse(lvl, min, max, record);
        for(int ind=min; ind<=max; ind++){
            for(int sind=0; sind<record[ind].size(); sind++){
                ans.push_back(record[ind][sind]);
            }
        }
        return ans;
    }
    
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends