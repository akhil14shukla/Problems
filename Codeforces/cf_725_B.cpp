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

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    sum = sum / n;
    int count = 0;
    rep(i, n)
    {
        if (a[i] > sum)
        {
            count++;
        }
    }
    cout << count << endl;

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