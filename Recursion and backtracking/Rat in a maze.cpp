
/*
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
*/

#include <bits/stdc++.h>

using namespace std;
void solve(vector<vector<int>> &m, int i, int j, int n, vector<string> &res, string temp)
{
    if (i < 0 or j < 0 or i >= n or j >= n or m[i][j] == 0)
    {
        return;
    }

    if (i == n - 1 and j == n - 1)
    {
        res.push_back(temp);
        return;
    }
    m[i][j] = 0;
    solve(m, i + 1, j, n, res, temp + 'D');
    solve(m, i, j + 1, n, res, temp + 'R');
    solve(m, i - 1, j, n, res, temp + 'U');
    solve(m, i, j - 1, n, res, temp + 'L');
    m[i][j] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> res;
    solve(m, 0, 0, n, res, "");
    if (res.size() == 0)
    {
        return {"-1"};
    }
    return res;
}

int main()
{
    int n = 4;
    vector<vector<int>> v = {{1, 0, 0, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 0},
                             {1, 1, 1, 1}};
    vector<string> s = findPath(v, n);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}
