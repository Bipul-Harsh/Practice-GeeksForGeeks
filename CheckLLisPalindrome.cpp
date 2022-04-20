// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  Node *getSecondHalf(Node *head){
      Node *fptr=head, *sptr=head;
      while(fptr && fptr->next){
          fptr = fptr->next->next;
          sptr = sptr->next;
      }
      if(fptr) //odd length
         return sptr->next;
      return sptr;
  }
  Node* reverseLL(Node *head){
      if(!head || !head->next)
        return head;
      Node *next, *prev=nullptr;
      while(head){
          next = head->next;
          head->next = prev;
          prev = head;
          head = next;
      }
      return prev;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head || !head->next)
            return true;
        Node *secondHalf = getSecondHalf(head);
        secondHalf = reverseLL(secondHalf);
        while(secondHalf){
            if(head->data != secondHalf->data)
                return false;
            secondHalf = secondHalf->next;
            head = head->next;
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends