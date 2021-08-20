#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<int, int>>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fir first
#define sec second
#define mod (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
#define fs fastscan
#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
using namespace std;

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));
    dp[0][0] = 1;
    int j = 0;
    for (int i = 1; i <= p.size(); i++)
    {
        for (j = 1; j <= s.size(); j++)
        {
            if (p[i - 1] == '.' && i < p.size() && p[i] == '*')
            {
                i++;
                for (int k = j - 1; k <= s.size(); k++)
                {
                    dp[i][k] = 1;
                }
            }

            if (dp[i - 1][j - 1] == 1)
            {
                if (p[i - 1] == '.')
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if (i < p.size() && p[i] == '*')
                    {
                        char tmp = p[i - 1];
                        i++;
                        for (int k = j - 1; k <= s.size(); k++)
                            dp[i][k] = dp[i - 2][k];

                        for (int k = j; k <= s.size(); k++)
                        {
                            if (tmp == s[k - 1])
                            {
                                dp[i][k] = 1;
                            }
                            if (dp[i][k] == 0)
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        if (s[j - 1] == p[i - 1])
                            dp[i][j] = 1;
                    }
                }
            }
        }
    }
    return dp[p.size()][s.size()];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "a", p = "ab*";
    cout << isMatch(s, p) << endl;
    return 0;
}