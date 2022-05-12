#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;

void findLongestPath(vector<vector<int>> &mat, int sr, int sc, int dr, int dc, int count)
{
    if (sr == dr and sc == dc)
    {
        ans = max(ans, count);
        return;
    }
    if (sr < 0 or sr >= mat.size() or sc < 0 or sc >= mat[0].size() or mat[sr][sc] == 0 or mat[sr][sc] == 5)
    {
        return;
    }
    mat[sr][sc] = 5;
    findLongestPath(mat, sr + 1, sc, dr, dc, count++);
    findLongestPath(mat, sr, sc + 1, dr, dc, count++);
    findLongestPath(mat, sr - 1, sc, dr, dc, count++);
    findLongestPath(mat, sr, sc - 1, dr, dc, count++);
    mat[sr][sc] == 1;
}
int main()
{

    vector<vector<int>> mat =
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
         {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // find longest path with source (0, 0) and
    // destination (1, 7)

    findLongestPath(mat, 0, 0, 1, 7, 1);
    cout << ans;
    return 0;
}