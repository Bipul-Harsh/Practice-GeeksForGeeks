// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        unordered_map<char, int>cvrt = {
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9}
        };
        stack<int>s;
        for(int ind=0; ind<S.length(); ind++){
            if(S[ind] == '+' || S[ind] == '-' || S[ind] == '/' || S[ind] == '*'){
                int opr2 = s.top();
                s.pop();
                int opr1 = s.top();
                s.pop();
                switch(S[ind]){
                    case '+': s.push(opr1+opr2);
                        break;
                    case '-': s.push(opr1 - opr2);
                        break;
                    case '*': s.push(opr1 * opr2);
                        break;
                    case '/': s.push(opr1 / opr2);
                        break;
                }
            }
            else
                s.push(cvrt[S[ind]]);
        }
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends