#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "No. of rows ";
    cin >> m;
    cout << "No. of Columns ";
    cin >> n;
    cout << "here is the rectengular matrix "
         << "\n";
    vector<vector<char>> v(m, vector<char>(n, '1'));
    int total = m * n;
    int count = 0;
    bool ins = true;
    int start_row = 0;
    int start_col = 0;
    int end_row = v.size() - 1;
    int end_col = v[0].size() - 1;
    while (count < total)
    {
        for (int i = start_col; i <= end_col and count < total; i++)
        {
            if (ins)
            {
                v[start_row][i] = 'X';
            }
            else
            {
                v[start_row][i] = 'O';
            }
            count++;
        }
        start_row++;
        for (int i = start_row; i <= end_row and count < total; i++)
        {
            if (ins)
            {
                v[i][end_col] = 'X';
            }
            else
            {
                v[i][end_col] = 'O';
            }
            count++;
        }
        end_col--;
        for (int i = end_col; i >= start_col and count < total; i--)
        {
            if (ins)
            {
                v[end_row][i] = 'X';
            }
            else
            {
                v[end_row][i] = 'O';
            }
            count++;
        }
        end_row--;
        for (int i = end_row; i >= start_row and count < total; i--)
        {
            if (ins)
            {
                v[i][start_col] = 'X';
            }
            else
            {
                v[i][start_col] = 'O';
            }
            count++;
        }
        start_col++;
        if (ins == true)
        {
            ins = false;
        }
        else
        {
            ins = true;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}