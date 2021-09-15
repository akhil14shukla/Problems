#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &a, vector<vector<bool>> ch, int i, int j, int rn, int &final)
{
    int n = a.size();
    if (i == n - 1 && j == n - 1)
    {
        rn = max(rn, a[i][j]);
        final = min(final, rn);
        return;
    }
    if (i + 1 < n && !ch[i + 1][j])
    {
        ch[i + 1][j] = true;
        dfs(a, ch, i + 1, j, max(rn, a[i + 1][j]), final);
        ch[i + 1][j] = false;
    }
    if (i - 1 >= n && !ch[i - 1][j])
    {
        ch[i - 1][j] = true;
        dfs(a, ch, i - 1, j, max(rn, a[i - 1][j]), final);
        ch[i - 1][j] = false;
    }
    if (j + 1 < n && !ch[i][j + 1])
    {
        ch[i][j + 1] = true;
        dfs(a, ch, i, j + 1, max(rn, a[i][j + 1]), final);
        ch[i][j + 1] = false;
    }
    if (j - 1 >= 0 && !ch[i][j - 1])
    {
        ch[i][j - 1] = true;
        dfs(a, ch, i, j - 1, max(rn, a[i][j - 1]), final);
        ch[i][j - 1] = false;
    }
}
int swimInWater(vector<vector<int>> &grid)
{
    int mn = 100000000;
    int n = grid.size();
    vector<vector<bool>> ch(n, vector<bool>(n, false));
    ch[0][0] = true;
    dfs(grid, ch, 0, 0, -1, mn);
    return mn;
}

int main()
{
    vector<vector<int>> a = {{0, 2}, {1, 3}};
    cout << swimInWater(a) << endl;
    return 0;
}





// vector<vector<int>> dp(51,vector<int> (51,10000000));
// class Solution {
// public:
    
//      int dfs(vector<vector<int>> &a, vector<vector<bool>> ch, int i, int j, int rn, int &final){
//         int n = a.size();
//         if(i == n-1 && j == n-1){
//             rn = max(rn, a[i][j]);
//             final = min(final,rn);
//             return final;
//         }   
//          if(dp[i][j]!=10000000){
//              return dp[i][j];
//          }
//          int tmp = 10000000;
//         if(i+1<n && !ch[i+1][j]){
//             ch[i+1][j]=true;
//             tmp = min(tmp,dfs(a,ch,i+1,j,max(rn,a[i+1][j]),final));
//             ch[i+1][j]=false;
//         }
//         if(i-1>=0 && !ch[i-1][j]){
//             ch[i-1][j]=true;
//             tmp = min(tmp,dfs(a,ch,i-1,j,max(rn,a[i-1][j]),final));
//             ch[i-1][j]=false;
//         }
//         if(j+1<n && !ch[i][j+1]){
//             ch[i][j+1]=true;
//             tmp = min(tmp,dfs(a,ch,i,j+1,max(rn,a[i][j+1]),final));
//             ch[i][j+1]=false;
//         }
//         if(j-1>=0 && !ch[i][j-1]){
//             ch[i][j-1]=true;
//             tmp = min(tmp,dfs(a,ch,i,j-1,max(rn,a[i][j-1]),final));
//             ch[i][j-1]=false;
//         }
//          if(tmp != 10000000){
//              dp[i][j] = tmp;
//              return tmp;
//          }
//          else {
//              return 10000000;
//          }
//     }
//     int swimInWater(vector<vector<int>>& grid) {
//         int mn = 100000000;
//         int n = grid.size();
//         vector<vector<bool>> ch(n,vector<bool>(n,false));
//         ch[0][0]=true;
//         dfs(grid,ch,0,0,grid[0][0],mn);
//         return dp[0][0];
//     }
// };