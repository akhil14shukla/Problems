#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1, 0);
    long long mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx += a[i];
    }
    if (mx < k)
    {
        cout << 0;
        return 0;
    }
    else if (k == mx)
    {
        cout << 1;
        return 0;
    }
    k = min(k, mx - k);
    vector<vector<long long>> dp(2, vector<long long>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[1][j] += dp[0][j];
            dp[1][j] %= 1000000007;
            if (j + a[i] + 1 <= k)
            {
                dp[1][j + a[i] + 1] -= dp[0][j];
                dp[1][j + a[i] + 1] %= 1000000007;
                if (dp[1][j + a[i] + 1] < 0)
                    dp[1][j + a[i] + 1] += 1000000007;
            }
        }
        dp[0][0] = dp[1][0];

        for (int j = 1; j <= k; j++)
        {
            dp[1][j] += dp[1][j - 1];
            dp[1][j] = dp[1][j] % 1000000007;
            dp[0][j] = dp[1][j];
            dp[1][j - 1] = 0;
        }
        dp[1][k] = 0;
    }
    cout << dp[0][k];

    return 0;
}