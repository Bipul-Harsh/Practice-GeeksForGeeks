// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> openedBracket;
        for(int ind=0; ind<x.length(); ind++)
            if(x[ind] == '{' || x[ind] == '[' || x[ind] == '(')
                openedBracket.push(x[ind]);
            else{
                if(!openedBracket.size() || (x[ind] == ']' && openedBracket.top() != '[') || (x[ind] == ')' && openedBracket.top() != '(') || (x[ind] == '}' && openedBracket.top() != '{'))
                    return false;
                openedBracket.pop();
            }
        if(openedBracket.size()>0)
            return false;
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends