//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends

char getLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return 'a' + (ch - 'A');
    return ch;
}

string transform(string S){
    //complete the function here
    int cnt = 1;
    S += '/';
    string res = "";
    char repCh = getLowerCase(S[0]);
    for(int ind=1; ind<S.length(); ind++){
        char ch = getLowerCase(S[ind]);
        if(repCh == ch){
            ++cnt;
        } else {
            res += to_string(cnt)+repCh;
            repCh = ch;
            cnt = 1;
        }
    }
    
    return res;
}

