/* Problem: Find the length of the longest increasing subsequence in an array.
5
1 7 3 5 9
4
  */
int LIS(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n,1);
    int ans = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
