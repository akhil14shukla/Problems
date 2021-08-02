#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<string, string> &a,
               const pair<string, string> &b)
{
    if (a.first > b.first)
    {
        return 1;
    }
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return (a.first > b.first);
}
void arrangeWords(int N, string words[]) // N is the number of words given, words is a list of all the given words
{
    unordered_map<char, int> m;
    vector<pair<string, string>> final;
    for (int i = 0; i < N; i++)
    {
        string tmp = {};
        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] - 'a' <= 2)
            {
                tmp.push_back('2');
            }
            else if (words[i][j] - 'a' <= 5)
            {
                tmp.push_back('3');
            }
            else if (words[i][j] - 'a' <= 8)
            {
                tmp.push_back('4');
            }
            else if (words[i][j] - 'a' <= 11)
            {
                tmp.push_back('5');
            }
            else if (words[i][j] - 'a' <= 14)
            {
                tmp.push_back('6');
            }
            else if (words[i][j] - 'a' <= 18)
            {
                tmp.push_back('7');
            }
            else if (words[i][j] - 'a' <= 21)
            {
                tmp.push_back('8');
            }
            else if (words[i][j] - 'a' <= 25)
            {
                tmp.push_back('9');
            }
        }
        final.push_back({tmp, words[i]});
    }
    sort(final.begin(), final.end(), sortinrev);
    for (int i = 0; i < N; i++)
    {
        cout << final[i].first + " " + final[i].second << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    string words[N];
    for (int i = 0; i < N; i++)
        cin >> words[i];
    arrangeWords(N, words);
    return 0;
}