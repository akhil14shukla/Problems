#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

int solve(vector<int> &a)
{
    ll sum= 0;
    rep(i,a.size()){
        sum+=a[i];
    }   
    int final=1;
    int last=1;
    sort(a.begin(),a.end());
    for(int i=a.size()-2;i>=0;i--){
        sum=sum-a[i+1];
        if(sum*2>=a[i+1]){
            final++;
        }
        else{
            break;
        }
    }
    return final;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}
// ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]