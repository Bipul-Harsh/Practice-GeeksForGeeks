// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        int ind=0;
        int val;
        while(ind<N){
            val = arr[ind];
            if(val > N)
                arr[ind]=0;
            else if(val == ind+1)
                arr[ind]=-1;
            else if(val>0 && arr[val-1]<1){
                arr[val-1]-=1;
                arr[ind]=0;
            }
            else if(val>0){
                arr[ind]=arr[val-1];
                arr[val-1]=-1;
                ind--;//to balance out the increment
            }
            ind++;
        }
        for(int ind=0; ind<N; ind++)
            arr[ind]*=-1;
    }
};


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}




  // } Driver Code Ends