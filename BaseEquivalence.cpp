int countBaseDigit(int n, int b){
        int count = 0;
        while(n){
            ++count;
            n/=b;
        }
        return count; 
    }
    
    string baseEquiv(int n, int m){
        // code here
        int start = 2, end = 32;
        while(start <= end){
            int mid = start + (end-start)/2;
            int count = countBaseDigit(n, mid);
            if(count == m){
                return "Yes";
            } else if(count < m){
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return "No";
    }