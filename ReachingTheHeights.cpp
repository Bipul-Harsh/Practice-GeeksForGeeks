// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    if(n == 1)
        return vector<int>{a[0]};
    
    sort(a, a+n);
    vector<int>res(n);
    
    int pos = 0;
    for(int ind=n-1; ind>=n/2; ind--){
        res[pos] = a[ind];
        pos+=2;
    }
    
    pos = 1;
    for(int ind=0; ind<n/2; ind++){
        res[pos] = a[ind];
        pos+=2;
    }
    
    int height = 0;
    int flick = 1;
    for(auto val : res){
        height += val * (1 + flick*-2);
        flick = !flick;
    }
    
    return height ? res : vector<int>{-1};
}
