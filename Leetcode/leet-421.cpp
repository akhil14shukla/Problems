#include <bits/stdc++.h>
using namespace std;

struct Trie
{
public:
    vector<pair<int, Trie *>> children = {{0, NULL}, {1, NULL}};
    // children[1] = NULL;
};
int findMaximumXOR(vector<int> &nums)
{
    Trie *root = new Trie();
    for (int i1 = 0; i1 < nums.size(); i1++)
    {
        int n = nums[i1];
        Trie *tmp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bt = (n & (1 << i));
            bt = bt >> i;
            if (tmp->children[bt].second == NULL)
            {
                Trie *t = new Trie();
                tmp->children[bt].second = t;
                tmp = t;
            }
            else
            {
                tmp = tmp->children[bt].second;
            }
        }
    }
    int max1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        Trie *tmp = root;
        int mx = 0;
        for (int it = 31; it >= 0; it--)
        {
            int bt = (nums[i] & (1 << it));
            bt = bt >> it;
            // if (tmp != NULL)
            if (tmp->children[!bt].second != NULL)
            {
                tmp = tmp->children[!bt].second;
                mx += (1 << it);
            }
            else
            {
                tmp = tmp->children[bt].second;
            }
        }
        max1 = max(max1, mx);
    }
    return max1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> f = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(f) << endl;

    return 0;
}