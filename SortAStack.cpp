// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortPush(stack<int>&s, int element){
    if(s.empty() || element>=s.top())
        s.push(element);
    else{
        int element2 = s.top();
        s.pop();
        sortPush(s, element);
        s.push(element2);
    }
}
void SortedStack :: sort()
{
   //Your code here
   int element = s.top();
   s.pop();
   if(!s.empty())
    sort();
    sortPush(s, element);
}