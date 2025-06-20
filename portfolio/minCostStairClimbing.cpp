#include <iostream>
#include <vector>
using namespace std;

int solve(int cost[], int n, vector<int>& dp) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
    return dp[n];
}

int solve3(){
    
}

int main() {
    int cost[] = {1, 100, 1, 1, 1, 100, 1, 1, 100};
    int n = sizeof(cost) / sizeof(cost[0]);
    vector<int> dp(n + 1, -1); // Adjusted size to n+1 to include 'top'

    // We need to compute the cost to reach one step beyond the last step
    // which means we don't add the cost of the final step itself
    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    cout << ans << endl; // Expected output --> 6

    return 0;
}