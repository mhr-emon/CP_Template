#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Function to count the number of subarray with sum = X
ll solve(ll N, ll X, vector<ll>& arr)
{
    // Two pointers to mark the starting and ending of
    // sliding window
    ll start = 0, end = -1;
    // Variable to store sum of all elements in the current
    // sliding window
    ll sum = 0;
    // Variable to store the count of subarrays with sum = X
    ll cnt = 0;

    while (end < N) {
        // Increase the size of sliding window by moving the
        // end till the sum is smaller than X
        while (end < N && sum < X) {
            end += 1;
            sum += arr[end];
        }
        // Decrease the size of sliding window by moving the
        // start till the sum is greater than X
        while (start <= end && sum > X) {
            sum -= arr[start];
            start += 1;
        }

        // If the sum is equal to X, increase the count by 1
        if (sum == X) {
            cnt += 1;
            sum -= arr[start];
            start += 1;
        }
    }
    return cnt;
}

int main()
{
    // Sample Input
    ll N = 6, X = 5;
    vector<ll> arr = { 1, 1, 1, 1, 1, 1 };

    cout << solve(N, X, arr);
}
