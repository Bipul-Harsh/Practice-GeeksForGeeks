//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int start = 0;
        int end = a.size()-1;
        while(start <= end){
            // cout<<start<<' '<<end<<endl;
            int middle = start + (end - start)/2;
            if(middle+1 < a.size() && a[middle+1] >= a[middle]){
                start = middle+1;
            } else if(middle-1 >= 0 && a[middle-1] >= a[middle]){
                end = middle-1;
            } else {
                return a[middle];
            }
        }
        
        return a[start];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends