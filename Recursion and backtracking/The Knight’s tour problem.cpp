#include <bits/stdc++.h>
using namespace std;

bool ans;
void solve(vector<vector<int>> &mat, int i, int j, int n, int k)
{
    if (k == 64)
    {
        ans = 1;
        return;
    }
    if (i < 0 or i >= n or j < 0 or j >= n or mat[i][j] != -1)
    {
        return;
    }
    // cout<<val<<" "<<k<<endl;
    mat[i][j] = k;
    solve(mat, i - 2, j + 1, n, k + 1);
    if (ans)
        return;
    solve(mat, i - 2, j - 1, n, k + 1);
    if (ans)
        return;
    solve(mat, i - 1, j + 2, n, k + 1);
    if (ans)
        return;
    solve(mat, i + 1, j + 2, n, k + 1);
    if (ans)
        return;
    solve(mat, i - 1, j - 2, n, k + 1);
    if (ans)
        return;
    solve(mat, i + 1, j - 2, n, k + 1);
    if (ans)
        return;
    solve(mat, i + 2, j + 1, n, k + 1);
    if (ans)
        return;
    solve(mat, i + 2, j - 1, n, k + 1);
    if (ans)
        return;
    mat[i][j] = -1;
}
int main()
{
    int n = 8;
    vector<vector<int>> mat(n, vector<int>(n, -1));

    solve(mat, 0, 0, n, 0);
    ans = 0;
    // }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
