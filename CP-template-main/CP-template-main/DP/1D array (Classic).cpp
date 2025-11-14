// 1D DP Example: Fibonacci
const int N = 1e5+5;
long long dp[N];

long long fib(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
