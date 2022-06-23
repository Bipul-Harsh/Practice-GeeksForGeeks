// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(!head || !head->next || m==n)
            return head;
        
        Node *temp = new Node(-1);
        temp->next = head;
        head = temp;
        Node *tail = head;
        int cm = m;
        while(--cm && tail){
            tail = tail->next;
        }
        
        if(!tail || !tail->next || !tail->next->next)
            return head->next;
        
        Node *head2 = tail->next;
        Node *tail2 = head2;
        
        n -= m;
        
        while(n-- && tail2){
            tail2 = tail2->next;
        }
        
        Node *head3;
        if(!tail2)
            head3 = nullptr;
        else
            head3 = tail2->next;
        
        Node *prev = head3;
        Node *curr = head2;
        Node *next;
        while(curr != head3){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail->next = prev;
        
        return head->next;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends
