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

int solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    multiset<ll> s;
    ll sum = 0;
    int count = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 0)
        {
            count++;
        }
    }
    vector<int> l(n, -1);
    for (int i = 0; i < n;i++)
    {
        if (a[i] > 0)
        {
            // l[i] = 0;
            while (l[i] == -1)
            {
                if (a[i] > 0)
                {
                    l[i] = 0;
                }
                else
                {
                    l[i] = l[(n + i - 1) % n] + 1;
                }
                i = (n + i + 1) % n;
            }
            break;
        }
    }
    vector<int> r(n, -1);
    for (int i = 0; i < n;i++)
    {
        if (a[i] > 0)
        {
            // r[i] = 0;
            while (r[i] == -1)
            {
                if (a[i] > 0)
                {
                    r[i] = 0;
                }
                else
                {
                    r[i] = r[(n + i + 1) % n] + 1;
                }
                i = (n + i - 1) % n;
            }
            break;
        }
    }
    for(int i = 0;i<n;i++)[
        
    ]
    rep(i,n){
        cout<<l[i]<<" "<<r[i]<<el;
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    // cout << -1 % 3;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

// for (int i = 0; i < n;)
//     {
//         if (a[i] > 0)
//         {
//             a[i] == -1;
//         }
//         else if (a[i] == 0)
//         {
//             int ct = 0;
//             while (a[i] == 0)
//             {
//                 if (a[i] == -1)
//                 {
//                     break;
//                 }
//                 ct++;
//                 i = (i + 1) % n;
//             }
//             if (a[i] == -1)
//             {
//                 break;
//             }
//             a[i] = -1;
//             s.insert(ct);
//         }
//         else
//         {
//             break;
//         }
//         i = (i + 1) % n;
//     }
//     if (k == 0)
//     {
//         cout << sum << el;
//         return 0;
//     }
//     int k1 = 1;
//     while (s.empty() == false && k1 <= k)
//     {
//         while (s.empty() == false && *s.begin() - 2 * k1 <= 0)
//         {
//             sum += 2 * (k - k1) - 2;
//             s.erase(s.begin());
//         }
//         k1++;
//     }
//     sum -= 2 * s.size();
//     cout << sum << el;