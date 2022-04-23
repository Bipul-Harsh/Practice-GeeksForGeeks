// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node *head){
        Node *prev = nullptr;
        Node *next, *nextBatch;
        Node *itr = head;
        while(itr && itr->next){
            next = itr->next;
            nextBatch = next->next;
            next->next = itr;
            itr->next = prev;
            prev = next;
            itr = nextBatch;
        }
        if(itr){
            itr->next = prev;
            return itr;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        int sum=0;
        first = reverse(first);
        second = reverse(second);
        Node *result=nullptr, *new_n=nullptr;
        while(first || second || sum){
            sum += (first?first->data:0)+(second?second->data:0);
            if(first)
                first = first->next;
            if(second)
                second = second->next;
            // cout<<sum<<endl;
            new_n = new Node(sum%10);
            new_n->next = result;
            result = new_n;
            sum /= 10; // Adding carry value
        }
        return result;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends