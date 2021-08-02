class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
 int m1 = board.size();
    int n1 = board[0].size();
    vector<unordered_map<string, unordered_multiset<int>>> m(26);
    for (int i = 0; i < words.size(); i++)
    {
        string s = "";
        for (int j = 0; j < words[i].size(); j++)
        {
            s.push_back(words[i][j]);
            if (j != words[i].size() - 1)
            {
                m[words[i][j] - 'a'][s].insert(words[i][j + 1] - 'a');
            }
            else
            {
                m[words[i][j] - 'a'][s].insert(-1);
            }
        }
    }
    vector<string> final;
    // unordered_set<string> check;
    stack<pair<string, pair<int, int>>> q;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (m[board[i][j] - 'a'].find(string(1, board[i][j])) != m[board[i][j] - 'a'].end())
            {
                q.push({string(1, board[i][j]), {i, j}});
                // recurrent code
                vector<vector<bool>> check2(m1, vector<bool>(n1, false));
                // check2[i][j]=true;
                while (!q.empty())
                {
                    string s = q.top().first;
                    pair<int, int> p = q.top().second;
                    // q.pop();
                    if (check2[p.first][p.second])
                    {
                        check2[p.first][p.second] = false;
                        q.pop();
                        continue;
                    }
                    check2[p.first][p.second] = true;
                    if (m[board[p.first][p.second] - 'a'][s].find(-1) != m[board[p.first][p.second] - 'a'][s].end())
                    {
                        // if (check.find(s) == check.end())
                        {
                            final.push_back(s);
                            // check.insert(s);
                            m[s[s.size() - 1] - 'a'][s].erase(-1);
                            int last = s[s.size() - 1] - 'a';
                            s.pop_back();
                            while (s.size())
                            {
                                unordered_multiset<int>::iterator it = m[s[s.size() - 1] - 'a'][s].find(last);
                                m[s[s.size() - 1] - 'a'][s].erase(it);
                                // if(m[s[s.size() - 1] - 'a'][s].size()==0){
                                //     m[s[s.size() - 1] - 'a'].erase(s);
                                // }
                                last = s[s.size() - 1] - 'a';
                                s.pop_back();
                            }
                        }
                    }
                    if (p.first + 1 < m1 && !check2[p.first + 1][p.second])
                    {
                        if (m[board[p.first][p.second] - 'a'][s].find(board[p.first + 1][p.second] - 'a') != m[board[p.first][p.second] - 'a'][s].end())
                        {
                            q.push({s + board[p.first + 1][p.second], {p.first + 1, p.second}});
                        }
                    }
                    if (p.first - 1 >= 0 && !check2[p.first - 1][p.second])
                    {
                        if (m[board[p.first][p.second] - 'a'][s].find(board[p.first - 1][p.second] - 'a') != m[board[p.first][p.second] - 'a'][s].end())
                        {
                            q.push({s + board[p.first - 1][p.second], {p.first - 1, p.second}});
                        }
                    }
                    if (p.second + 1 < n1 && !check2[p.first][p.second + 1])
                    {
                        if (m[board[p.first][p.second] - 'a'][s].find(board[p.first][p.second + 1] - 'a') != m[board[p.first][p.second] - 'a'][s].end())
                        {
                            q.push({s + board[p.first][p.second + 1], {p.first, p.second + 1}});
                        }
                    }
                    if (p.second - 1 >= 0 && !check2[p.first][p.second - 1])
                    {
                        if (m[board[p.first][p.second] - 'a'][s].find(board[p.first][p.second - 1] - 'a') != m[board[p.first][p.second] - 'a'][s].end())
                        {
                            q.push({s + board[p.first][p.second - 1], {p.first, p.second - 1}});
                        }
                    }
                }
                //recurrent code
            }
        }
    }
    return final;
    }
};