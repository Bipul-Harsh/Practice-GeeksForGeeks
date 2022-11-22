//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

void checkString(string s);


// } Driver Code Ends
//User function Template for C++

bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

void checkString(string s)
{
    int v=0;
    int c=0;
    
    //Your code here
    for(auto ch : s){
        if(ch >= 'a' && ch <= 'z'){
            if(isVowel(ch))
                ++v;
            else
                ++c;
        }
    }
    
    if(v>c)
        cout<<"Yes";
    else if(c>v)
        cout<<"No";
    else
        cout<<"Same";
    
    cout<<endl;
}

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
	    
	    string s;
	    getline(cin,s);
	    
	    //function call
	    checkString(s);
	   
	}
	return 0;
}


// } Driver Code Ends