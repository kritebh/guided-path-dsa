vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
 vector<int> ans;
    // prefix sum
    int prefix_sum[n+1];
    prefix_sum[0]=0;
     for(int i=0;i<n;i++){
        prefix_sum[i+1] = (prefix_sum[i]%1000000007+arr[i]%1000000007)%1000000007; 
    }
    
    for(auto q:queries){
        long long int left = q[0];
        long long int right = q[1];
      left-=1;
        long long temp= (prefix_sum[right%n]-prefix_sum[left%n]+((prefix_sum[n]*((right/n - left/n)%1000000007))))%1000000007;
        
        ans.push_back((temp+1000000007)%1000000007);
        
    }
    
    return ans;
    
}