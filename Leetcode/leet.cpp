#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int longestValidParentheses(string s)
{
    vector<int> tmp(s.size(), 0);
    stack<pair<char, int>> s1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s1.push({'(', i});
        }
        else
        {
            if (!s1.empty() && s1.top().first == '(')
            {
                tmp[s1.top().second] = 1;
                tmp[i] = 1;
                s1.pop();
            }
        }
    }
    int mx = 0, t1 = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (tmp[i] == 1)
        {
            t1++;
            mx = max(mx, t1);
        }
        else
        {
            t1 = 0;
        }
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << longestValidParentheses("))))())()()(()");
    return 0;
}
// ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]