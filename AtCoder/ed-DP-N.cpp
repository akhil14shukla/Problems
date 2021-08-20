#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> pre(n + 1, 0);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                dp[j][j + i] = 0;
            }
            else if (j + i < n)
            {
                dp[j][j + i] = 1e18;
                long long sum = pre[j + i + 1] - pre[j];
                for (int k = j; k < j + i; k++)
                {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum);
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
