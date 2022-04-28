// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head){
        Node *prev = nullptr;
        Node *next, *nextBatch;
        if(!head || !head->next)
            return head;
        while(head && head->next){
            next = head->next;
            nextBatch = head->next->next;
            head->next->next = head;
            head->next = prev;
            prev = next;
            head = nextBatch;
        }
        if(nextBatch){
            nextBatch->next = prev;
            prev = nextBatch;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry = 1;
        head = reverse(head);
        Node *itr = head;
        Node *prev;
        itr = head;
        while(carry && itr){
            if(itr->data<9){
                itr->data += 1;
                carry = 0;
                break;
            }else{
                itr->data = 0;
            }
            prev = itr;
            itr = itr->next;
        }
        if(carry){
            Node *new_n = new Node(1);
            prev->next = new_n;
        }
        head = reverse(head);
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends