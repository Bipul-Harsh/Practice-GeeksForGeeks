//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

void generateSpaceString(string str, vector<string>&ss, string curr, int ind=1){
    if(ind == str.size()){
        ss.push_back(curr);
        return;
    }
    generateSpaceString(str, ss, curr+str[ind], ind+1);
    generateSpaceString(str, ss, curr+" "+str[ind], ind+1);
}

vector<string>  spaceString(char str[])
{
//Your code here
    vector<string>ss;
    string inp = str;
    string out = "";
    out += inp[0];
    generateSpaceString(inp, ss, out);
    
    return ss;
}