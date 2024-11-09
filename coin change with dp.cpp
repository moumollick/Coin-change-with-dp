#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1000;
int dp[N][N];
vector<int> coins(N);
int countWays(int n, int target_sum)
{
    if (target_sum == 0) return 1;
    if (target_sum < 0 || n == 0) return 0;
    if(dp[n][target_sum] != -1) return dp[n][target_sum];
    dp[n][target_sum] = countWays(n, target_sum - coins[n - 1]) + countWays(n - 1, target_sum);
    return dp[n][target_sum];
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }
    memset(dp, -1, sizeof dp);
    int sum;
    cin >> sum;
    cout << countWays(n, sum) << endl;
    return 0;
}