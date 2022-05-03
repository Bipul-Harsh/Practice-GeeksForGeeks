// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>result;
        unordered_map<int, bool>check;
        int ind1=0, ind2=0;
        while(ind1<n && ind2<m){
            if(arr1[ind1]<arr2[ind2]){
                if(!check[arr1[ind1]]){
                    result.push_back(arr1[ind1]);
                    check[arr1[ind1]] = true;
                }
                ind1++;
            }
            else if(arr1[ind1]>arr2[ind2]){
                if(!check[arr2[ind2]]){
                    result.push_back(arr2[ind2]);
                    check[arr2[ind2]] = true;
                }
                ind2++;
            }else{
                if(!check[arr1[ind1]]){
                    result.push_back(arr1[ind1]);
                    check[arr1[ind1]] = true;
                }
                ind1++;ind2++;
            }
        }
        for(int ind=ind1; ind<n; ind++)
             if(!check[arr1[ind]]){
                result.push_back(arr1[ind]);
                check[arr1[ind]] = true;
            }
        for(int ind=ind2; ind<m; ind++)
             if(!check[arr2[ind]]){
                result.push_back(arr2[ind]);
                check[arr2[ind]] = true;
            }
        return result;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends