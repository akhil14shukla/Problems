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

bool sortinrev(const int &a,
               const int &b)
{
    return (a > b);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
ll modu(ll n, ll d)
{
    ll qw = n % d;
    if (qw < 0)
    {
        return qw + d;
    }
    return qw;
}
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
ll power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        return x * temp * temp;
    }
}
ll count(ll a)
{
    if (a == 0)
    {
        return 0;
    }
    if (a == 1 || a == 2 || a == 4)
    {
        return 1;
    }
    ll max_power = (log2(a));
    ll pow1 = a - power(2, max_power);
    return 1 + count(pow1);
}

char give(int i, int j, vector<vector<char>> &final)
{
    int a1[] = {0, 1, -1};
    int b1[] = {0, 1, -1};
    vector<int> a(9, 0);

    rep(i1, 3)
    {
        rep(j1, 3)
        {
            if (i + a1[i1] >= 0 && i + a1[i1] < final.size() && j + b1[j1] >= 0 && j + b1[j1] < final[0].size() && final[i + a1[i1]][j + b1[j1]] != 'z')
            {
                a[final[i + a1[i1]][j + b1[j1]] - 'a']++;
            }
        }
    }
    rep(i1, 9)
    {
        if (a[i1] == 0)
        {
            return 'a' + i1;
        }
    }
    return 'w';
}
int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m < 2 && k > 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<char>> final(n, vector<char>(m, 'z'));
    if (n % 2 == 0)
    {
        if (k % 2 == 1 && (k % n) % 2 == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        int j = 0;
        int i = 0;
        for (; i <= n && k;)
        {
            if (i + 1 < n)
            {
                char a1 = give(i, j, final);
                final[i][j] = a1;
                final[i][j + 1] = a1;
                a1 = give(i + 1, j, final);
                final[i + 1][j] = a1;
                final[i + 1][j + 1] = a1;
                k = k - 2;
                i += 2;
            }
            else
            {
                i = 0;
                j += 2;
                if (j >= m || j + 1 >= m)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }

        for (; i <= n && j < m;)
        {
            if (i + 1 < n)
            {
                char a1 = give(i, j, final);
                final[i][j] = a1;
                final[i + 1][j] = a1;
                if (j + 1 < m)
                {
                    a1 = give(i, j + 1, final);
                    final[i][j + 1] = a1;
                    final[i + 1][j + 1] = a1;
                }
                i += 2;
            }
            else
            {
                i = 0;
                j += 2;
            }
        }
    }
    else
    {
        if (m > 2 * k)
        {
            cout << "NO" << endl;
            return 0;
        }
        int j = 0;
        int i = 0;
        for (; j <= m && k;)
        {
            if (j + 1 < m)
            {
                char a1 = give(i, j, final);
                final[i][j] = a1;
                final[i][j + 1] = a1;
                if (j + 3 < m && k - 2 >= 0)
                {
                    a1 = give(i, j + 2, final);
                    final[i][j + 2] = a1;
                    final[i][j + 3] = a1;
                    k = k - 2;
                    j += 4;
                    continue;
                }
                j += 2;
                k--;
            }
            else
            {
                break;
                i++;
                j = 0;
                if (i >= n)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        ////
        i = 1;
        j = 0;
        if (k % 2 == 1 && (k % (n - 1)) % 2 == 1)
        {
            cout << "NO" << endl;
            return 0;
        }
        for (; i <= n && k;)
        {
            if (i + 1 < n)
            {
                char a1 = give(i, j, final);
                final[i][j] = a1;
                final[i][j + 1] = a1;
                a1 = give(i + 1, j, final);
                final[i + 1][j] = a1;
                final[i + 1][j + 1] = a1;
                k = k - 2;
                i += 2;
            }
            else
            {
                i = 1;
                j += 2;
                if (j >= m || j + 1 >= m)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }

        for (; i <= n && j < m;)
        {
            if (i + 1 < n)
            {
                char a1 = give(i, j, final);
                final[i][j] = a1;
                final[i + 1][j] = a1;
                if (j + 1 < m)
                {
                    a1 = give(i, j + 1, final);
                    final[i][j + 1] = a1;
                    final[i + 1][j + 1] = a1;
                }
                i += 2;
            }
            else
            {
                i = 1;
                j += 2;
            }
        }

        ///////////
    }
    cout << "YES" << endl;
    rep(i, n)
    {
        rep(j, m)
        {
            cout << final[i][j];
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}