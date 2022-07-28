//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end());
        
        long long int sum = 0;
        long long int csum = 0;
        for(int val : Arr){
            sum += val;
        }

        int count = 0;
        for(int ind=N-1; ind>=0; ind--){
            if(sum >= csum){
                sum -= Arr[ind];
                csum += Arr[ind];
                ++count;
            } else {
                break;
            }
        }
        
        return count;
    }
};