//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       if (s1 == "0" || s2 == "0") return "0";
      
      string res;
      
      if(s1[0]=='-'&& s2[0]=='-'){
          s1=s1.substr(1);
          s2=s2.substr(1);
      }
      else if(s1[0]!='-' && s2[0]=='-'){
          s2=s2.substr(1);
          res.push_back('-');
      }
      else if(s1[0]=='-' && s2[0]!=0){
          s1=s1.substr(1);
          res.push_back('-');
      }
      
      vector<int> num(s1.size()+ s2.size(),0);
      
      for(int i=s1.size()-1;i>=0;--i){
          for(int j=s2.size()-1;j>=0;--j){
              num[i+j+1] += (s1[i]-'0') * (s2[j]-'0');
              num[i+j] += num[i+j+1]/10;
              num[i+j+1] %=10;
          }
      }
      int i=0;
      while(i<num.size() && num[i]==0) ++i;
      
      
      while(i<num.size()){
          res.push_back(num[i++] + '0');
      }
      
      return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends