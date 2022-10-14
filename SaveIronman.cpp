//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}

// } Driver Code Ends


char convert(char ch){
    if(ch >= 'a' && ch <= 'z')
        return ch;
    if(ch >= 'A' && ch <= 'Z')
        return 'a' + (ch - 'A');
    if(ch >= '0' && ch <= '9')
        return ch;
    return '_';
}

bool saveIronman(string str)
{
    // Complete the function
    string fltrStr = "";
    for(auto ch: str){
        char conChar = convert(ch);
        if(conChar != '_')
            fltrStr += conChar;
    }
    int len = fltrStr.length();
    for(int ind=0; ind<len/2; ind++){
        if(fltrStr[ind] != fltrStr[len-ind-1])
            return false;
    }
    return true;
}
